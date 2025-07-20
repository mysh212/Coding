# Author : ysh
# 2025/04/09 Wed 17:04:54
# https://codeforces.com/contest/2084/problem/A
for _ in range(int(input())):
    n = int(input())
    if not n & 1:
        print(-1)
    else:
        print(n, end = ' ')
        for i in range(1, n):
            print(i, end = ' ')
        print('')
quit()