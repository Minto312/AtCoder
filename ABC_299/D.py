class Data():
    N = int(input())
    pre_idx = 2
    last_idx = N-1

    def check(self):

        self.string = list()
        self.string.append('2')
        self.string.append('0')

        for _ in range(self.N-2):
            self.string.append('2')
        self.string.append('1')

        is_pre = True
        for _ in range(22):
            res = False
            if is_pre:
                print(f'? {self.pre_idx}')
                self.string[self.pre_idx] = input()
                self.pre_idx += 1
                if self.string[self.pre_idx-1] != self.string[self.pre_idx-2]:
                    res = self.pre_idx - 2
            else:
                print(f'? {self.last_idx}')
                self.string[self.last_idx] = input()
                self.last_idx -= 1
                if self.string[self.last_idx+1] != self.string[self.last_idx+2]:
                    res = self.last_idx+1

            is_pre = not is_pre
            # res = self.test()
            if res != False:
                print(f'! {res}')
                return
        return

    # def test(self):
        
        
    #     else:
    #         return False

obj = Data()
obj.check()