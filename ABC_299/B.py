def check(win_color,color_list,number_list):

    def calc(win_color,color_list,number_list):
        num_max = 0
        max_idx = 0
        for idx,color in enumerate(color_list):
            if color == win_color:
                temp = number_list[idx]
                if temp > num_max:
                    num_max = temp
                    max_idx = idx
        return max_idx + 1

    if win_color in color_list:
        return calc(win_color,color_list,number_list)

    else:
        win_color = color_list[0]
        return calc(win_color,color_list,number_list)

_,win_color = map(int,input().split(' '))
color_list = list(map(int,input().split(' ')))
number_list = list(map(int,input().split(' ')))

print(check(win_color,color_list,number_list))