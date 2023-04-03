import numpy as np
"""
3 34
1
8 13 26

13
"""
"""
7 45
2
7 11 16 20 28 34 38

12
"""
"""
3 100
1
28 54 81

46
"""
"""
3 100
2
28 54 81

26
"""
"""
20 1000
4
51 69 102 127 233 295 350 388 417 466 469 523 553 587 720 739 801 855 926 954

170
"""

class Yokan():
    def __init__(self,cut_N,length,choose,cut):
        self.cut_N = cut_N
        self.length = length
        self.choose = choose
        self.cut = cut

        self.cut_index = 0
        self.mean = length / (choose + 1)
        self.current_length = 0

        self.choice = list()

    
    def get_breakPoint(self):
        _length = self.cut[self.cut_index] - self.current_length

        while _length < self.mean:
            self.cut_index += 1
            _length = self.cut[self.cut_index] - self.current_length

        dist_up = _length - self.mean
        dist_down = self.mean - self.cut[self.cut_index - 1] - self.current_length
        if dist_down < dist_up:
            _length = self.cut[self.cut_index - 1] - self.current_length
        
        self.choice.append(_length + self.current_length)
        self.current_length += _length

    def output(self):
        self.choice.insert(0,0)
        self.choice.append(self.length)
        
        dist_arr = list()
        for index in range(len(self.choice) - 1):
            dist_arr.append(self.choice[index + 1] - self.choice[index])
        
        dist_arr = np.array(dist_arr)
        print(f'{dist_arr.min()}')



cut_N,length = map(int,input().split(' '))

choose = int(input())

cut = np.array(list(map(int,input().split(' '))))


yokan = Yokan(cut_N,length,choose,cut)

for _ in range(choose):
    yokan.get_breakPoint()

yokan.output()