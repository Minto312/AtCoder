
import numpy as np

def check():
    N = int(input())

    temp = list()
    for _ in range(N):
        temp.append(input().split(' '))
    
    A_arr = np.array(temp)

    temp = list()
    for _ in range(N):
        temp.append(input().split(' '))
    
    B_arr = np.array(temp)

    count = 0
    while not is_collect(A_arr,B_arr,N):
        roll_arr = A_arr.copy()
        for row in range(N):

            for column in range(N):

                roll_arr[column][N-1 - row] = A_arr[row][column]
        A_arr = roll_arr

        if count == 4:
            return 'No'
        count += 1

    return 'Yes'

def is_collect(A,B,N):
    for row in range(N):
        for column in range(N):
            if A[row][column] == '1' and B[row][column] == '0':
                return False
            
    return True

print(check())
