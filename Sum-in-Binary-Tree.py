# Author : ysh
# 2023/06/21 Wed 07:27:55
# https://codeforces.com/contest/1843/problem/C
for i in range(int(input())):
    n = int(input())
    ans = 0
    while n != 1:
        ans = ans + n
        n = n >> 1
    print(ans + n)
quit()