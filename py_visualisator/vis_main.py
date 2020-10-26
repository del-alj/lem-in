import pygame, math
import sys
from typing import List

listof_rooms = []
listof_inst: List[str] = []
listof_connections = []
dictof_connections = {}

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
            dictof_connections[r2].append(r1)
        else:
            listof_rooms.append(line)
            tpl = line.split()
            if len(tpl) == 3:
                dictof_connections[tpl[0]] = []

print("done")

rooms = {}
for temp in listof_rooms:
    tpl = temp.split()
    if len(tpl) == 3:
        # room = [x, y, list of connections]
        rooms[tpl[0]] = [int(tpl[1]), int(tpl[2]), dictof_connections[tpl[0]]]

def center_screen():

    print(z)
    if z == -1:
        #hadi ba9i
        x_map = 1
        y_map = 1
    if z == 1:
        x_map = int(((width * zoom) - width) / 2)
        y_map = int(((height * zoom) - height) / 2)
    else:
        print("notwork")

def draw_room_edg():

    #not work moxkil dyal inisalisation x_map and x_map
    center_screen()
    for rm in rooms:
        x_room = rooms[rm][0]
        y_room = rooms[rm][1]
        x_room = int((rooms[rm][0] * zoom) + offset_x - int(x_map))
        y_room = int((rooms[rm][1] * zoom) + offset_y - int(y_map))
        if rooms[rm][2]:
            edgs = rooms[rm][2]
            for r in edgs:
                x_edg = rooms[r][0]
                y_edg = rooms[r][1]
                x_edg = int((x_edg * zoom) + offset_x - int(x_map))
                y_edg = int((y_edg * zoom) + offset_y - int(y_map))
                # draw edg
                pygame.draw.line(screen, edg_color, (x_room, y_room), (x_edg, y_edg), 8)
        pygame.draw.circle(screen, room_color, (x_room, y_room), r_room)



#pygame.init()
# basique
background_color = (183, 135, 86)
room_color = (204, 193, 105)
edg_color = (208, 152, 57)
(width, height) = (2000, 1000)
offset_x = width / 4
offset_y = height / 4
nm_rooms = 20
zoom = 10
x_map = 1
y_map = 1
#if nm_rooms < 100:
#    zoom = 100 / nm_rooms
z = 0
# need parse
(x_room, y_room) = (0, 0)
x_edg = 100
y_edg = 20
#
r_room = 20
#rooms = ants_map
pygame.init()
# open window
screen = pygame.display.set_mode((width, height))
# give name for window
pygame.display.set_caption('Lem-in')
# coloring background
#screen.fill(background_color)
# loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        mouse = pygame.mouse.get_pos()
        if event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 4:
                zoom *= 1.09
                z = 1
            elif event.button == 5:
                if zoom > 0:
                    zoom /= 1.09
                    z = -1

            else:
                z = 0


    # draw room and edg
    screen.fill(background_color)
    draw_room_edg()
   # pygame.display.update()
    pygame.display.flip()