# Author : ysh
# 2024/07/10 Wed 00:34:47
# https://codeforces.com/group/j50SrY6hsZ/contest/528706/problem/A
n = int(input())
print(''.join([str(i) for i in sorted([int(i) for i in input().split()])[::-1]]))