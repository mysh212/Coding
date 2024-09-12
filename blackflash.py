# Author : ysh
# 2024/07/08 Mon 00:20:28
# https://codeforces.com/group/j50SrY6hsZ/contest/533977/problem/A
print([2,4,8,6,1][(lambda x: (x - 1) % 4 if x != 0 else 4)(int(input()))])