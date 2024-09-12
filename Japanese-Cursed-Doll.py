# Author : ysh
# 2024/08/05 Mon 11:09:50
# https://atcoder.jp/contests/abc363/tasks/abc363_b
n,a,b = [int(i) for i in input().split()]
f = sorted([int(i) for i in input().split()])[::-1]

print(max(0,a - f[b - 1]))