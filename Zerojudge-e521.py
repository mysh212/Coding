# Author : ysh
# 10/20/2022 Thu  8:30:58.25
for i in range(int(input())):
    r = sorted([int(i) for i in input().split()])
    if r[0] + r[1] > r[2]:
        print('1',end = ' ')
        if r[0] == r[1] or r[1] == r[2]:
            print(1)
            continue
        print(0)
        continue
    print(0)
quit()