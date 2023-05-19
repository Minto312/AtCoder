
A,B = map(int,input().split(' '))

count = 0
while A != B:
    if A > B:
        if B < 1:
            dist = A // B
            A -= B * dist
            count += dist
        else:
            A -= B
            count += 1
    else:
        if A < 1:
            dist = B // A
            B -= A * dist
            count += dist
        else:
            B -= A
            count += 1
print(count)
