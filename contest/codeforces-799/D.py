# Author : ysh
# 06/14/2022 Tue 23:01:05.10
n = int(input())
for i in range(n):
    a = [i for i in input().split()]
    b = int(a[0][:2])
    c = int(a[0][3:])
    # bb = b
    # cc = c
    dd = str(str(b) + str(c))
    if b // 10 == 0:
        dd = '0' + dd
    if c // 10 == 0:
        dd = dd[:2] + '0' + dd[2:]
    ans = 0
    # print(b,end = ' ')
    # print(c,end = ' ')
    while True:
        c = c + int(a[1])
        b = b + c // 60
        b = b % 24
        c = c % 60
        s = str(str(b) + str(c))
        if b // 10 == 0:
            s = '0' + s
        if c // 10 == 0:
            s = s[:2] + '0' + s[2:]
        if s[::-1] == s:
            ans = ans + 1
        if s == dd:
            print(ans)
            break
