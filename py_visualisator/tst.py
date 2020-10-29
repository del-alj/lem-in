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
    pad_x = int(width / (x_max + 1))
    pad_y = int(height / (y_max + 1))
    change_cordinates(listof_connections, pad_x, pad_y)
    return(listof_connections)

def change_cordinates(rooms: dict, padx: int, pady: int):
    """
    this changes the cords from the basic ones we get to the new screen scale
    """
    for rm in rooms:
        rooms[rm][0] = rooms[rm][0] * padx
        rooms[rm][1] = rooms[rm][1] * pady
"""
def center_screen(zoom, z):
    x_delta = 0
    y_delta = 0
    if z == -1:
        #hadi ba9i
        x_delta = 1
        y_delta = 1
    if z == 1:
        x_delta = int(((width * zoom) - width) / 2)
        y_delta = int(((height * zoom) - height) / 2)
    return(x_delta, y_delta)
"""
def draw_room_edg(screen, rooms, zoom, z, offset_x, offset_y, a):
    line_width = 8
    (x_map, y_map) = (0, 0)
    #center screan
    if z == -1:
        x_map = int((width - (width * zoom)) / 2)
        y_map = int((height - (height * zoom)) / 2)
    if z == 1:
        x_map = int(((width * zoom) - width) / 2) * -1
        y_map = int(((height * zoom) - height) / 2) * -1

    for rm in rooms:
        x_room = int((rooms[rm][0] * zoom) + offset_x + int(x_map))
        y_room = int((rooms[rm][1] * zoom) + offset_y + int(y_map))
        if rooms[rm][2]:
            edgs = rooms[rm][2]
            for r in edgs:
                x_edg = rooms[r][0]
                y_edg = rooms[r][1]
                x_edg = int((x_edg * zoom) + offset_x + int(x_map))
                y_edg = int((y_edg * zoom) + offset_y + int(y_map))
                # draw edg
                pygame.draw.line(screen, edg_color, (x_room, y_room), (x_edg, y_edg), line_width)
                pygame.draw.circle(screen, room_color, (x_edg, y_edg), radius_of_room)
        pygame.draw.circle(screen, room_color, (x_room, y_room), radius_of_room)

    for name_room in rooms:
        is_ant = (nbr_ant % 8)
            # draw the current room
        x_room = int((rooms[name_room][0] * zoom) + offset_x + int(x_map))
        y_room = int((rooms[name_room][1] * zoom) + offset_y + int(y_map))
        screen.blit(a[is_ant], (x_room - radius_of_room, y_room - radius_of_room))

    print(z, x_map, y_map)
"""
def moveing_with_keybord(event, offset_x, offset_y):
    if event.type == pygame.KEYDOWN:
        if event.key == pygame.K_LEFT:
            offset_x -= 10
        if event.key == pygame.K_RIGHT:
            offset_x += 10
        if event.key == pygame.K_UP:#
            offset_y -= 10
        if event.key == pygame.K_DOWN:
            offset_y += 10
    return (offset_x, offset_y)
"""
def main(zoom, offset_x, offset_y):
    z = 0
    rooms = {}
    rooms = parcing()
    # open window
    pygame.init()
    clock = pygame.time.Clock()
    screen = pygame.display.set_mode((width, height))
    pygame.display.set_caption('Lem-in')
    # loop
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            #zooming
            if event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 4:
                    zoom *= 1.09
                    z = 1
                elif event.button == 5:
                    if zoom > 0:
                        zoom /= 1.09
                        z = -1
                else:
                    #hadi wa9ila  hiya li kat khalini mni n kliki yw9a3 dak moxkil
                    z = 0

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    offset_x -= 10
                if event.key == pygame.K_RIGHT:
                    offset_x += 10
                if event.key == pygame.K_UP:
                    offset_y -= 10
                if event.key == pygame.K_DOWN:
                    offset_y += 10

        # coloring background
        screen.fill(background_color)
        # draw room and edg
        path = {}
        draw_room_edg(screen, rooms, zoom, z, offset_x, offset_y, ant, path)

       # pygame.display.update()
        pygame.display.flip()
        clock.tick(2000)


# initialization
background_color = (183, 135, 86)
room_color = (204, 193, 105)
edg_color = (208, 152, 57)
(width, height) = (2000, 1000)
radius_of_room = 20
#now manual it will become automated (offset_x, offset_y)
offset_x = 0
offset_y = 0
zoom = 1





#from parse
nbr_ant = 1


ant = {}
ant[1] = pygame.image.load('ants_type/1.png')
ant[2] = pygame.image.load('ants_type/2.png')
ant[3] = pygame.image.load('ants_type/3.png')
ant[4] = pygame.image.load('ants_type/4.png')
ant[5] = pygame.image.load('ants_type/5.png')
ant[6] = pygame.image.load('ants_type/6.png')
ant[7] = pygame.image.load('ants_type/7.png')
ant[8] = pygame.image.load('ants_type/8.png')




if __name__ == "__main__":
    main(zoom, offset_x, offset_y)
