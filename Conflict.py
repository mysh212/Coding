# Author : ysh
# 2025/06/11 Wed 10:27:44
# https://atcoder.jp/contests/abc409/tasks/abc409_a
n = int(input())
a, b = [[i == 'o' for i in input()] for _ in range(2)]

for i in range(n):
    if a[i] and b[i]:
        print('Yes')
        quit()

print('No')
quit()