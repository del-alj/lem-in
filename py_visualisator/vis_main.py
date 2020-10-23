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
        if line[0] == 'L':
            listof_inst.append(line)
        elif line.find('-') != -1:
            listof_connections.append(line)
            r1, r2 = line.split('-')
#            print("line {}, r1:[{}], r2:[{}]".format(line, r1, r2))
            dictof_connections[r1].append(r2)
            dictof_connections[r2].append(r1)
        else:
            listof_rooms.append(line)
            tpl = line.split()
            if len(tpl) == 3:
                dictof_connections[tpl[0]] = []

print("done")
map = {}
for temp in listof_rooms:
    tpl = temp.split()
    if len(tpl) == 3:
        # room = [x, y, list of connections]
        map[tpl[0]] = [tpl[1], tpl[2], dictof_connections[tpl[0]]]

print(map)
