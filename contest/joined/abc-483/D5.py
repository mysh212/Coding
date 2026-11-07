# Author : ysh
# 2026/11/07 Sat 22:18:06
n = int(input())
f = [int(i) for i in input().split()]

g = f.copy()

for i in range(1, n):
    f[i] += f[i - 1]

l = [[0, 0] for _ in range(n)]
r = l.copy()

l[0] = [min(f[0], 0), max(0, f[0])]
# print(f)
# print(f[0])
# print(l)
r[-1] = [f[-1], f[-1]]

for i in range(1, n):
    l[i] = [min(l[i - 1][0], f[i]), max(l[i - 1][1], f[i])]

for i in range(n - 1)[::-1]:
    r[i] = [min(r[i + 1][0] , f[i]), max(r[i + 1][1], f[i])]

# print(l)
# print(r)

ans = abs(f[-1])
for i in range(n):
    ll = min(l[i - 1][0] if i != 0 else 10 ** 10, (r[i][0] + ((-g[i]) << 1)))
    rr = max(l[i - 1][1] if i != 0 else -(10 ** 10), (r[i][1] + ((-g[i]) << 1)))

    # print(i, ll, rr)

    ans = max(ans, rr - ll)

print(ans + 1)
quit()