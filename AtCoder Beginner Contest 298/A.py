
def check():
    _ = input()

    data = input()

    good_flg = False
    for str in data:
        if str == 'o':
            good_flg = True

        if str == 'x':
            return 'No'
        
    if good_flg:
        return 'Yes'
    else:
        return 'No'
    
print(check())