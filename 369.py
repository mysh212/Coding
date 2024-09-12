# Author : ysh
# 2024/09/08 Sun 17:52:19
# https://atcoder.jp/contests/abc369/tasks/abc369_a
a,b = [int(i) for i in input().split()]

if a == b:
    print(1)
    quit()

if (a + b) & 1:
    print(2)
    quit()

print(3)
quit()