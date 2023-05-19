"""
4 500
300 900 1300 1700
"""

N,dist_time = map(int,input().split(' '))
click_time = list(map(int,input().split(' ')))

is_end = False

for idx in range(len(click_time) - 1):
    dist = click_time[idx + 1] - click_time[idx]

    if dist <= dist_time:
        is_end = True
        print(click_time[idx + 1])
        break

if not is_end:
    print(-1)