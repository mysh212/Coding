# Author : ysh
# 2024/04/01 Mon 20:02:59
# https://codeforces.com/contest/1950/problem/C

def zt(x,n):
    x = str(x)
    while len(x) < n: x = '0' + x;
    return x

for _ in range(int(input())):
    a,b = [int(i) for i in input().split(':')]
    if a // 12 == 1:
        a = a - 12
        print(f'{[zt(a,2),"12"][a == 0]}:{zt(b,2)} PM')
    else:
        print(f'{[zt(a,2),"12"][a == 0]}:{zt(b,2)} AM')
