# Author : ysh
# 2026/10/24 Sat 20:02:47
a, b = [int(i) for i in input().split()]
f = [int(i) for i in input().split()]

ans = 0
last = f[0]
for i in f:
    if (i - b) * (b - last) > 0:
        ans += 1
    if i == b:
        ans += 1
    last = i

print(ans)
quit()