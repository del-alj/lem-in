import pygame, math
import sys
from typing import List


def parcing():
    listof_rooms = []
    listof_inst: List[str] = []
    listof_connections = {}
    dictof_connections = {}

    x_max = -1
    y_max = -1
    x_min = 1000000
    y_min = 1000000

    for line in sys.stdin:
        line = line.strip()
        if line == 'exit':
            break
        if len(line) > 0:
            if line[0] == 'L':  # todo find someway to stock this data, the good way !
                listof_inst.append(line)
            elif line.find('-') != -1:  # updating a dict that contains each room neighbers
                r1, r2 = line.split('-')
                dictof_connections[r1].append(r2)
            #  dictof_connections[r2].append(r1)
            else:
                listof_rooms.append(line)
                tpl = line.split()
                if len(tpl) == 3:
                    dictof_connections[tpl[0]] = []

                    if (int(tpl[1]) > x_max):
                        x_max = int(tpl[1])
                    if (int(tpl[2]) > y_max):
                        y_max = int(tpl[2])

                    if (int(tpl[1]) < x_min):
                        x_min = int(tpl[1])
                    if (int(tpl[2]) < y_min):
                        y_min = int(tpl[2])

    for temp in listof_rooms:
        tpl = temp.split()
        if len(tpl) == 3:
            # room = [x, y, list of connections]
            listof_connections[tpl[0]] = [int(tpl[1]), int(tpl[2]), dictof_connections[tpl[0]]]
            #           print("{}: {} {}".format(tpl[0], tpl[1], tpl[2]))

    pad_x = int(width / (x_max + 1))
    pad_y = int(height / (y_max + 1))
    change_cordinates(listof_connections, pad_x, pad_y)

    return (listof_connections)


# def center_screen(zoom, z):
#     x_delta = 0
#     y_delta = 0
#     if z == -1:
#         #hadi ba9i
#         x_delta = 1
#         y_delta = 1
#     if z == 1:
#         x_delta = int(((width * zoom) - width) / 2)
#         y_delta = int(((height * zoom) - height) / 2)
#     return(x_delta, y_delta)

def zoom_in(z: int, x: int, y: int):
    '''
    the size of the screen is 2000 * 1000
    so the center of it is 1000 * 500

    this func take care of the zoom
    '''
    # z == 1
    if x < 1000:
        x = x - 10
    else:
        x += 10

    if y < 500:
        y -= 10
    else:
        y += 10
    return ((x, y))


def draw_room_edg(screen, rooms, move_x, move_y, zoom):
    """
    this function draws the rooms and the edges btw them
    """
    line_width = 5
    print(zoom)
    for rm in rooms:
        # if zoom != 0:
        #   x_room, y_room = zoom_in(x_room, y_room, zoom)
        if rooms[rm][2]:
            edgs = rooms[rm][2]
            for r in edgs:
                # drawing lines to the next vertices
                pygame.draw.line(screen, edg_color, (rooms[rm][0], rooms[rm][1]), (rooms[r][0], rooms[r][1]), line_width)

    for vert in rooms:
        # draw the current room
        pygame.draw.circle(screen, room_color, (rooms[vert][0], rooms[vert][1]), radius_of_room)


def moveing_with_keybord(event, offset_x, offset_y):
    if event.type == pygame.KEYDOWN:
        if event.key == pygame.K_LEFT:
            offset_x -= 10
        if event.key == pygame.K_RIGHT:
            offset_x += 10
        if event.key == pygame.K_UP:
            offset_y -= 10
        if event.key == pygame.K_DOWN:
            offset_y += 10
    return (offset_x, offset_y)


def change_cordinates(rooms: dict, padx: int, pady: int):
    """
    this changes the cords from the basic ones we get to the new screen scale
    """
    for rm in rooms:
        rooms[rm][0] = rooms[rm][0] * padx
        rooms[rm][1] = rooms[rm][1] * pady


def move_graph(rooms: dict, move_x: int, move_y: int):
    '''
    this moves the graph to the new pos after getting the changes from keyboard arrows
    '''
    for rm in rooms:
        rooms[rm][0] = rooms[rm][0] + move_x
        rooms[rm][1] = rooms[rm][1] + move_y


def main():
    # z = 0
    move_x = 0
    move_y = 0
    rooms = parcing()

    # open window
    pygame.init()
    screen = pygame.display.set_mode((width, height))
    pygame.display.set_caption('Lem-in')
    # pygame loop
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            # still not usit mouse
            mouse = pygame.mouse.get_pos()
            # if event.type == pygame.MOUSEBUTTONDOWN:
            #     if event.button == 4:
            #         zoom *= 1.09
            #         z = 1
            #     elif event.button == 5:
            #         if zoom > 0:
            #             zoom /= 1.09
            #             z = -1
            # moving the screen with arrow keys
            zoom = 0
            if event.type == pygame.KEYDOWN:
                (move_x, move_y) = moveing_with_keybord(event, move_x, move_y)
                move_graph(rooms, move_x, move_y)
                if event.key == pygame.K_KP_PLUS:
                    print("you clicked ++")
                    zoom = 1
                if event.key == pygame.K_KP_MINUS:
                    print("you clicked --")
                    zoom = -1

        # coloring background
        screen.fill(background_color)
        # draw the graph
        draw_room_edg(screen, rooms, move_x, move_y, zoom)
        # pygame.display.update()
        pygame.display.flip()
        # return to this value after each time i scroll
        # z = 0


# initialization
background_color = (183, 135, 86)
room_color = (204, 193, 105)
edg_color = (208, 152, 57)
# for mac
(width, height) = (2000, 1000)
# for lpc lmskin
# (width, height) = (700, 700)
radius_of_room = 20

nb_rooms = 20
# if nb_rooms < 100:
#    zoom = 100 / nb_rooms


if __name__ == "__main__":
    main()
