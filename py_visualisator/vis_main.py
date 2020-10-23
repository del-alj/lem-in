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

ants_map = {}
for temp in listof_rooms:
    tpl = temp.split()
    if len(tpl) == 3:
        # room = [x, y, list of connections]
        ants_map[tpl[0]] = [tpl[1], tpl[2], dictof_connections[tpl[0]]]

for room in ants_map.keys():
    print("{}  x = {}, y = {}, ----     {}".format(room, ants_map[room][0], ants_map[room][1], ants_map[room][2]))
