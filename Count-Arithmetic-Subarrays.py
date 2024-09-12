# Author : ysh
# 2024/09/08 Sun 20:19:49
# https://atcoder.jp/contests/abc369/tasks/abc369_c
n = int(input())
f = [int(i) for i in input().split()]

l = 0
r = 0
d = 0
ans = 1

for i in range(n - 1):
    r = r + 1
    if f[r] - f[r - 1] != d:
        d = f[r] - f[r - 1]
        l = r - 1
    ans = ans + (r - l + 1)
    # print(ans,l,r)

print(ans)
quit()
