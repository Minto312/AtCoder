# import time
import numpy as np
# start = time.time()

#種類数　幅　奥行　四隅ジャマブロックの1辺　高さ
'''4 1120 680 30 1200
355 360 285 3 Y Y
155 210 120 1 Y Y
510 820 380 1 Y N
370 710 330 1 Y Y
'''
#d w h c r u
class Item:
    def __init__(self,id,depth,width,height,count,role,cantup):
        self.id = id
        self.depth = round(int(depth) / 10)
        self.depthGap = int(depth) % 10
        self.width = round(int(width) / 10)
        self.widthGap = int(width) % 10
        self.height = round(int(height) / 10)
        self.heightGap = int(height) % 10
        self.count = int(count)
        self.is_cantRole = True if role == 'N' else False
        self.is_cantUp = True if cantup == 'N' else False

    def check_cantUp(self):
        if self.is_cantUp:
            return True
        
    def placement(self):
        self._w = 0
        self._d = 0
        self._h = 0
        self._height_gap = 0

        #範囲内にブロックがあるか
        _output = ''
        for _ in range(self.count):
            while np.any(container[self._w:self._w + self.width,self._d:self._d + self.depth,self._h:self._h + self.height] >= 0):
                self._w += items[container[self._w,self._d,self._h]].width
                if self._w + self.width >= container_width:
                    self._w = 0

                    self._d += items[container[self._w,self._d,self._h]].depth
                    if self._d + self.depth >= container_depth:
                        self._d = 0

                        self._height_gap += items[container[self._w,self._d,self._h]].heightGap
                        self._h += items[container[self._w,self._d,self._h]].height
                        if self._h + self.height >= container_height:
                            self._h = 0



            container[self._w:self._w + self.width,self._d:self._d + self.depth,self._h:self._h + self.height] = self.id
            _output += f'{self.id} 0 {self._w * 10} {self._d * 10} {self._h * 10 - self._height_gap}\n'

        return _output
                        

            


kind_count,container_width,container_depth,box_bold,container_height = input().split(' ')

container_width = round(int(container_width) / 10)
container_depth = round(int(container_depth) / 10)
container_height = round(int(container_height) / 10)
box_bold = round(int(box_bold) / 10)

kind_count = int(kind_count)


container = np.full((container_width,container_depth,container_height),-1)

container[:box_bold,:box_bold,:] = kind_count
container[:box_bold,-1:-box_bold-1:-1,:] = kind_count
container[-1:-box_bold-1:-1,:box_bold,:] = kind_count
container[-1:-box_bold-1:-1,-1:-box_bold-1:-1,:] = kind_count

# print(container[111][67][119])


items = list()
cant_ups = set()

for id in range(kind_count):
    args = input().split(' ')
    items.append(Item(id,*args))
    if items[id].check_cantUp():
        cant_ups.add(id)

items.append(Item(kind_count,box_bold * 10,box_bold * 10,container_height,0,'N','N'))

canUp_iter = [x for x in range(kind_count) if x not in cant_ups]

#id role width depth height\n
output = ''

for id in canUp_iter:
    output += items[id].placement()

for id in cant_ups:
    output += items[id].placement()
print(container)
print(output)
# print(time.time() - start)