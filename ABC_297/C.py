
N,length = map(int,input().split(' '))
out = ''
for _ in range(N):
    string = input()

    is_prevT = False
    str_list = list()
    for idx,char in enumerate(string):
        str_list.append(char)
        if char == 'T':
            if is_prevT:
                str_list[idx - 1] = 'P'
                str_list[idx] = 'C'
                is_prevT = False
            else:
                is_prevT = True
        else:
            is_prevT = False
    out_buf = ''
    for t in str_list:
        out_buf += t
    out += f'{out_buf}\n'
print(out)
