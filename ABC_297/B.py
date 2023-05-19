
def check():

    string = input()

    B_idx = list()
    for idx,char in enumerate(string):
        if char == 'B':
            B_idx.append(idx)
    
    if (B_idx[0] + B_idx[1]) % 2 == 0:
        print('No')
        return
    
    K_idx = ''
    R_idx = list()
    for idx,char in enumerate(string):
        if char == 'R':
            R_idx.append(idx)
        if char == 'K':
            K_idx = idx

    if K_idx > R_idx[0] and K_idx < R_idx[1]:
        print('Yes')
    else:
        print('No')

check()