def check():
    _ = input()
    string = input()

    m_flag = False
    o_flag = False
    count = 0
    max_count = 0
    for s in string:
        if s == '-':
            if count > max_count:
                max_count = count
            count = 0
            m_flag = True
        else:
            count += 1
            o_flag = True
    if m_flag and o_flag:
        if count > max_count:
            max_count = count
        return max_count
    
    return -1

print(check())