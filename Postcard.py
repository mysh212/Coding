# Author : ysh
# 2023/09/13 Wed 13:21:16
# https://codeforces.com/problemset/problem/1099/C
a = input()
pos = (a.count('*'))
neg = (a.count('*')) + (a.count('?'))
n = len(a) - (a.count('*') + a.count('?'))
m = int(input())
det = m - n
if n - neg <= m <= n or (m >= n and pos > 0):
    if det > 0:
        last = ''
        for i in a:
            if i == '*' and det > 0:
                while det > 0:
                    print(last,end = '')
                    det = det - 1
                continue
            if i == '*' or i == '?':
                continue
            print(i,end = '')
            last = i
    else:
        ans = ''
        c = False
        for i in a[::-1]:
            if (i == '?' or i == '*') and det < 0:
                c = True
                det = det + 1
                continue
            if c:
                c = False
                continue
            if i == '*' or i == '?':
                continue
            ans = ans + i
        print(ans[::-1])
else:
    print('Impossible')
quit()