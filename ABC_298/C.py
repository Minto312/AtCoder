
N = int(input())

Q = int(input())

output = ''
box = list()
box.append(set())
for idx in range(N):
    box.append(set())

for _ in range(Q):
    q = list(map(int,input().split(' ')))

    if q[0] == 1:
        box[q[2]].add(q[1])

    elif q[0] == 2:
        box[q[1]].sorted()
        output += f"{' '.join(set(map(str,box[q[1]])))}\n"
    
    else:
        for idx,num in enumerate(box):
            if q[1] in num:
                output += f'{idx} '
        
        output += '\n'

print(output)