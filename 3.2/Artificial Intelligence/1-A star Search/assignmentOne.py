# A* Search
# Result : S-> A-> B-> C-> D , Cost = 8

adjacency_list = {
    'S': [('A', 1), ('B', 4)],
    'A': [('B', 2), ('C', 5), ('D', 12)],
    'B': [('C', 2)],
    'C': [('D', 3)],
    'D': [('C', 4)],
}

H = {
    'S': 7,
    'A': 6,
    'B': 2,
    'C': 1,
    'D': 0,
}


class Node:
    def __init__(self,nodeName,parent,g,h):
        self.nodeName = nodeName
        self.parent = parent
        self.g = g
        self.h = h
        self.f = g+h


pq = []
path = []
cost = 0

NOb = Node('S',None,0,H['S'])

pq.append(NOb)

while not len(pq)==0:
    pq.sort(key= lambda x: x.f)
    ob = pq.pop(0)
    if ob.nodeName == 'D':
        NOb = ob
        break
    else:
        for item in adjacency_list[ob.nodeName]:
            newOb = Node(item[0],ob,item[1]+ob.g,H[item[0]])
            pq.append(newOb)

cost = NOb.g

while not NOb.parent == None:
    path.append(NOb.nodeName)
    NOb = NOb.parent
    if(NOb.parent==None):
        path.append(NOb.nodeName)


path.reverse()
print(path)
print("The total cost is ",cost)







    







