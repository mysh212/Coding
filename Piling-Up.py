# Author : ysh
# 2024/08/05 Mon 11:05:55
# https://atcoder.jp/contests/abc363/tasks/abc363_a
import bisect


f = [100,200,300,400]

n = int(input())
for i in f:
    if i > n:
        print((i - n))
        quit()

print(-1)
quit()