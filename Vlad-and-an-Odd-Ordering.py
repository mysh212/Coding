# Author : ysh
# 2024/02/22 Thu 17:51:46
# https://codeforces.com/contest/1926/problem/E
import sys
input = sys.stdin.readline
print = sys.stdout.write

def check(n,x):
    pre = (n + 1) >> 1
    if x - pre <= 0:
        return (x << 1) - 1
    return (check(n >> 1,x - pre) << 1)

for i in range(int(input())):
    a,b = [int(i) for i in input().split()]
    print(f'{check(a,b)}\n')