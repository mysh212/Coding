# Author : ysh
# 2023/08/25 Fri 21:58:53
# https://codeforces.com/group/bzV2fc45zy/contest/463655/problem/E
for i in range(int(input())):
    n = int(input())
    f = []
    while n != 0:
        f.append(n % 9)
        n = n // 9
    for j in f[::-1]:
        if j >= 7:
            print(j + 1,end = '')
        else:
            print(j,end = '')
    print('')
quit()