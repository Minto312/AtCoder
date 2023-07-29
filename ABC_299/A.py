def check():
    _ = input()
    string = input()

    I_flag = False
    ok_flag = False
    for s in string:

        if s == r'*':
            if I_flag:
                ok_flag = True
            else:
                return 'out'
        
        if s == r'|':
            if ok_flag:
                return 'in'
            else:
                I_flag = True
    
    return 'out'

print(check())

