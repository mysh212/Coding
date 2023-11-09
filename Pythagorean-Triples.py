# Author : ysh
# 2023/10/25 Wed 21:32:42
# https://codeforces.com/problemset/problem/1487/D
from math import sqrt
import sys
input = sys.stdin.readline
print = sys.stdout.write
for i in range(int(input())):
    print(f'{((int(sqrt((int(input()) << 1) - 1)) + 1) >> 1) - 1}\n')
quit()