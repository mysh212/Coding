# Author : ysh
# 2024/04/01 Mon 19:56:16
# https://codeforces.com/contest/1950/problem/A
for i in range(int(input())):
    a,b,c = [int(i) for i in input().split()]
    if a < b < c: print('STAIR');
    elif a < b > c: print('PEAK')
    else: print('NONE')
quit()