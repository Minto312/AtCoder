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
        self.length_list = np.array(list(),dtype='int')


        self.choose_index = np.arange(choose,dtype='int')
        init_choose_dist = (cut_N + 1) // (choose + 1)
        for idx in range(choose):
            self.choose_index[idx] = init_choose_dist * (idx + 1)
        
        self.moved_number = set()

        self.choice_length = np.arange(choose + 1,dtype='int')
        self.choice_length = np.insert(self.choice_length,0,-1)
        self.choice_length = np.append(self.choice_length,-1)

        self.max_score = 0
        self.max_index = np.arange(choose,dtype='int')



    
    def get_length(self):
        self.cut = np.insert(self.cut,0,0)
        self.cut = np.append(self.cut,self.length)
        for index in range(self.cut_N + 1):
            self.length_list = np.append(self.length_list,self.cut[index + 1] - self.cut[index])

    def chosen(self):
        def calculate_length():
            self.choice_length[1] = self.length_list[:self.choose_index[0] + 1].sum()

            if self.choose != 1:
                for idx in range(2,self.choose):
                    self.choice_length[idx] = self.length_list[idx - 2:idx - 1].sum()
            
            self.choice_length[self.choose + 1] = self.length_list[self.choose_index[self.choose - 1]:].sum()

        calculate_length()

        max_score = sorted(self.choice_length)[3]
        if max_score > self.max_score:
            self.max_score = max_score

        min_score_index = np.where(self.choice_length == sorted(self.choice_length)[2])[0]
        min_score_index = min_score_index[0]

        if min_score_index - 2 in self.moved_number and min_score_index - 1 in self.moved_number:
            return True
        
        if self.choice_length[min_score_index - 1] > self.choice_length[min_score_index + 1]:
            current_idx = min_score_index - 2

            
            if self.choose_index[current_idx] not in self.moved_number:
                if self.choose_index[current_idx] != -1:
                    self.choose_index[current_idx] -= 1
                    self.moved_number.add(self.choose_index[current_idx])

            else:
                current_idx += 1
                if self.choose_index[current_idx] != -1:
                    self.choose_index[current_idx] += 1
                    self.moved_number.add(self.choose_index[current_idx])

        else:
            current_idx = min_score_index - 1

            if self.choose_index[current_idx] not in self.moved_number:
                if self.choose_index[current_idx] != -1:
                    self.choose_index[current_idx] += 1
                    self.moved_number.add(self.choose_index[current_idx])
                    
            else:
                current_idx -= 1
                if self.choose_index[current_idx] != -1:
                    self.choose_index[current_idx] -= 1
                    self.moved_number.add(self.choose_index[current_idx])

        return False



    def output(self):
        
        print(self.max_score)

def main():
    cut_N,length = map(int,input().split(' '))

    choose = int(input())

    cut = np.array(list(map(int,input().split(' '))))


    yokan = Yokan(cut_N,length,choose,cut)

    yokan.get_length()

    is_end = False
    while not is_end:
        is_end = yokan.chosen()

    yokan.output()


main()