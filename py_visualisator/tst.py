import pygame, math
import sys
from typing import List
from time import sleep

# we use frames, so that the game doesn't run faster then what the player can see.
FPS = 1  # frames per second setting
fpsClock = pygame.time.Clock()

listof_inst: List[str] = []
# we well fill these vars from parse function
nbrof_ants = 0
start_name = ''
end_name = ''


def calculate_map_edges(x_max: int, x_min: int, y_max: int, y_min: int, tpl):
    if (int(tpl[1]) > x_max):
        x_max = int(tpl[1])
    if (int(tpl[2]) > y_max):
        y_max = int(tpl[2])

    if (int(tpl[1]) < x_min):
        x_min = int(tpl[1])
    if (int(tpl[2]) < y_min):
        y_min = int(tpl[2])
    return ((x_max, x_min, y_max, y_min))


def parcing():
    """
    reads the input from  stdin, then divids it to rooms info and list of edges
    number of ants, start/sink are global variables and it's the easiest way to do the job for now

    """
    global listof_inst
    global start_name
    global end_name

    listof_rooms = []
    map_dict = {}
    dictof_connections = {}

    x_max = -1
    y_max = -1
    x_min = 1000000
    y_min = 1000000

    bol = 0

    global nbrof_ants
    nbrof_ants = sys.stdin.readline()

    for line in sys.stdin:
        line = line.strip()
        if len(line) > 0:
            if line[0] == 'L':  # todo find someway to stock this data, the good way !
                listof_inst.append(line)
            elif line.find('-') != -1:  # updating a dict that contains each room neighbers
                r1, r2 = line.split('-')
                dictof_connections[r1].append(r2)
            elif line[0] == '#':
                if line == '##start':
                    bol = 1
                else:
                    bol -= 1
            else:
                listof_rooms.append(line)
                tpl = line.split()
                if bol != 0:
                    if bol == 1:
                        start_name = tpl[0]
                    else:
                        end_name = tpl[0]
                    bol = 0
                if len(tpl) == 3:
                    dictof_connections[tpl[0]] = []
                    x_max, x_min, y_max, y_min = calculate_map_edges(x_max, x_min, y_max, y_min, tpl)

    for temp in listof_rooms:
        tpl = temp.split()
        if len(tpl) == 3:
            # room = [x, y, list of connections]
            map_dict[tpl[0]] = [int(tpl[1]), int(tpl[2]), dictof_connections[tpl[0]]]
    pad_x = int(width / (x_max + x_min))
    pad_y = int(height / (y_max + x_min))
    change_cordinates(map_dict, pad_x, pad_y)

    return (map_dict)


def change_cordinates(rooms: dict, padx: int, pady: int):
    """
    this changes the cords from the basic ones we get to the new screen scale
    """
    for rm in rooms:
        rooms[rm][0] = rooms[rm][0] * padx
        rooms[rm][1] = rooms[rm][1] * pady


def moveing_with_keybord(event, offset_x, offset_y):
    if event.key == pygame.K_LEFT:
        offset_x -= 10
    if event.key == pygame.K_RIGHT:
        offset_x += 10
    if event.key == pygame.K_UP:
        offset_y -= 10
    if event.key == pygame.K_DOWN:
        offset_y += 10
    return (offset_x, offset_y)


def ft_zoom(button: int, zoom: int, z: int):
    if button == 4:
        zoom *= 1.09
        z = 1
    elif button == 5:
        zoom /= 1.09
        z = -1
    else:
        z = 0
    return ((zoom, z))


def write_numb(screen, rooms, name, zoom, offset_x, offset_y, x_map, y_map, st):
    font = pygame.font.Font('freesansbold.ttf', 21)
    x_room = int((rooms[name][0] * zoom) + offset_x + int(x_map))
    y_room = int((rooms[name][1] * zoom) + offset_y + int(y_map))
    text = font.render(str(st), True, nbr_color, background_color)
    screen.blit(text, (x_room - 10, y_room + 25))
    return(x_room, y_room)

def draw_ant_start_to_and(screen, line, rooms, zoom, offset_x, offset_y, x_map, y_map, a, radius_of_room):
    global cnt
    global last_ant
    splt = line.split()
    for inst in splt:
        details = inst.split('-')
        nbr_ant = int(details[0][1:])
        name_room = details[1]

        is_ant = (nbr_ant % 8)
        # draw the current room
        x_room = int((rooms[name_room][0] * zoom) + offset_x + int(x_map))
        y_room = int((rooms[name_room][1] * zoom) + offset_y + int(y_map))
        screen.blit(a[is_ant], (x_room - radius_of_room, y_room - radius_of_room))
        if name_room == end_name:
            cnt += 1
        if nbr_ant > last_ant:
            last_ant = nbr_ant

    font = pygame.font.Font('freesansbold.ttf', 21)
    # draw start
    (x_room, y_room) = write_numb(screen, rooms, start_name, zoom, offset_x, offset_y, x_map, y_map, (int(nbrof_ants) - last_ant))
    screen.blit(a[is_ant], (x_room - radius_of_room, y_room - radius_of_room))
    # draw end
    write_numb(screen, rooms, end_name, zoom, offset_x, offset_y, x_map, y_map, cnt)


def center_screen_after_zoom(z, zoom):
    (x_map, y_map) = (0, 0)
    if z == -1:
        x_map = int((width - (width * zoom)) / 2)
        y_map = int((height - (height * zoom)) / 2)
    if z == 1:
        x_map = int(((width * zoom) - width) / 2) * -1
        y_map = int(((height * zoom) - height) / 2) * -1
    return (x_map, y_map)

# def draw_room_edg(screen, rooms, zoom, z, offset_x, offset_y, line: str):
def draw_room_edg(screen, rooms, zoom, z, offset_x, offset_y, a: dict, line: str):
    line_width = 8
    # center screen after zooming
    (x_map, y_map) = center_screen_after_zoom(z, zoom)
    for rm in rooms:
        x_room = int((rooms[rm][0] * zoom) + offset_x + int(x_map))
        y_room = int((rooms[rm][1] * zoom) + offset_y + int(y_map))
        if rooms[rm][2]:
            edgs = rooms[rm][2]
            for r in edgs:
                x_edg = int((rooms[r][0] * zoom) + offset_x + int(x_map))
                y_edg = int((rooms[r][1] * zoom) + offset_y + int(y_map))
                # draw edg
                pygame.draw.line(screen, edg_color, (x_room, y_room), (x_edg, y_edg), line_width)
                pygame.draw.circle(screen, room_color, (x_edg, y_edg), radius_of_room)
        pygame.draw.circle(screen, room_color, (x_room, y_room), radius_of_room)
    draw_ant_start_to_and(screen, line, rooms, zoom, offset_x, offset_y, x_map, y_map, a, radius_of_room)


def main(zoom, offset_x, offset_y):
    global cnt
    global FPS
    global last_ant

    z = 0
    rooms = {}
    rooms = parcing()
    # open window
    pygame.init()
    # clock = pygame.time.Clock()
    screen = pygame.display.set_mode((width, height))
    pygame.display.set_caption('Lem-in')
    # loop
    for line in listof_inst:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            # zooming
            if event.type == pygame.MOUSEBUTTONDOWN:
                zoom, z = ft_zoom(event.button, zoom, z)

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LSHIFT:
                    ##  to slow down the vis
                    FPS = max((FPS - 5, 1))  # in case this went negatif, fps should always be > 0

                elif event.key == pygame.K_RSHIFT:
                    ## to accelerate the vis
                    FPS += 5
                else:
                    (offset_x, offset_y) = moveing_with_keybord(event, offset_x, offset_y)

        # coloring background
        screen.fill(background_color)

        # draw room and edg
        path = {}
        # draw_room_edg(screen, rooms, zoom, z, offset_x, offset_y, line)
        draw_room_edg(screen, rooms, zoom, z, offset_x, offset_y, ant, line)

        pygame.display.update()
        # pygame.display.flip()

        # we don't need the fps clock, the game is already slow.
        fpsClock.tick(FPS)
        print(FPS)


# initialization
background_color = (183, 135, 86)
room_color = (204, 193, 105)
edg_color = (208, 152, 57)
rect_color = (179, 208, 101)
# rect_color = (244, 246, 246)
nbr_color = (18, 22, 22)
(width, height) = (2000, 1000)
radius_of_room = 20
# now manual it will become automated (offset_x, offset_y)
offset_x = 0
offset_y = 0
zoom = 1

cnt = 0
last_ant = 0
ant = {}
ant[1] = pygame.image.load('ants_type/1.png')
ant[2] = pygame.image.load('ants_type/2.png')
ant[3] = pygame.image.load('ants_type/3.png')
ant[4] = pygame.image.load('ants_type/4.png')
ant[5] = pygame.image.load('ants_type/5.png')
ant[6] = pygame.image.load('ants_type/6.png')
ant[7] = pygame.image.load('ants_type/7.png')
ant[0] = pygame.image.load('ants_type/8.png')

if __name__ == "__main__":
    main(zoom, offset_x, offset_y)
