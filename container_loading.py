input_data = '''4 1120 680 30 1200
355 360 285 3 Y Y
155 210 120 1 Y Y
510 820 380 1 Y N
370 710 330 1 Y Y
'''

data = iter(input_data.splitlines())

kind_count,container_width,container_depth,box_bold,container_height = int(next(data).split(' '))
item = dict()

for id in range(kind_count):
    depth,width,height,count,role,cantup = next(data).split(' ')
    item['id'] = id
    item['item_depth'] = depth
    item['item_width'] = width
    item['item_height'] = height
    item['item_count'] = count
    item['is_cantRole'] = role
    item['is_cantUp'] = cantup
    print(id,item)