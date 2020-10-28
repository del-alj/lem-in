import pygame, math
import sys
from typing import List

padx = 0
pady = 0

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
            print("{}: {} {}".format(tpl[0], tpl[1], tpl[2]))
    print ('max x : {}, min x = {}'.format(x_max, x_min))
    print ('max y : {}, min y = {}'.format(y_max, y_min))
    global padx
    global pady
    padx = int(width / (x_max + 1))
    pady = int(height / (y_max + 1))
    print ("padx == ", padx)
    print ("pady == ", pady)
    return(listof_connections)

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

# def zoom_in(z: int, mouse: tuple, x: int, y: int):
#     if x < mouse[0]:
#         x -= 10
#     else:
#         x += 10
#     if y < mouse[1]:
#         y -= 10
#     else:
#         y += 10
#     return ((x, y))


def draw_room_edg(screen, rooms, move_x, move_y):
    """
    this function draws the rooms and the edges btw them
    """
    line_width = 5
    #not work moxkil dyal inisalisation x_map and x_map
    for rm in rooms:
        x_room = rooms[rm][0] * padx + move_x
        y_room = rooms[rm][1] * pady + move_y

        if rooms[rm][2]:
            edgs = rooms[rm][2]
            for r in edgs:
                x_edg = rooms[r][0] * padx + move_x
                y_edg = rooms[r][1] * pady + move_y

                # drawing lines to the next vertices
                pygame.draw.line(screen, edg_color, (x_room, y_room), (x_edg, y_edg), line_width)

    for rm in rooms:
        x_room = rooms[rm][0] * padx + move_x
        y_room = rooms[rm][1] * pady + move_y
        # draw the current room
        pygame.draw.circle(screen, room_color, (x_room, y_room), radius_of_room)

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
    return(offset_x, offset_y)

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

            #still not usit mouse
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
            if event.type == pygame.KEYDOWN:
                (move_x, move_y) = moveing_with_keybord(event, move_x, move_y)

        # coloring background
        screen.fill(background_color)
        # draw the graph
        draw_room_edg(screen, rooms, move_x, move_y)
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
#if nb_rooms < 100:
#    zoom = 100 / nb_rooms


if __name__ == "__main__":
    main()
