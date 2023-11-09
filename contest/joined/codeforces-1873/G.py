# Author : ysh
# 2023/09/21 Thu 23:46:12
for i in range(int(input())):
    n = input()
    ans = 0
    c = False
    while not n == '':
        tmp = n.find('B')
        if tmp == -1:
            break
        if tmp