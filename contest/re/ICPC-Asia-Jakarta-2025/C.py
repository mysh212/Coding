# Author : ysh
# 2026/10/29 Thu 16:41:54
n, m = [int(i) for i in input().split()]
f = [[0 for _ in range(m)] for _ in range(n)]

pre = [int(i) for i in input().split()]

def make(a, b, r):
    t = [0 for _ in range(b)]
    for i in range((1 if r == 1 else 0), a << 1, 2):
        t[i] = 1
    return t

def check(x):
    ans = []
    for i in pre:
        ans.append(make(i, m, x))
        x = 0 if x == 1 else 1

    for i in ans:
        for j in i:
            print(j, end = ' ')
        print('')

    return

ok = True
l, r = m >> 1, (m + 1) >> 1
for j, i in enumerate(pre):
    if j & 1 and i > l:
        ok = False
        break
    if not (j & 1) and i > r:
        ok = False
        break

if ok:
    check(0)

for j, i in enumerate(pre):
    if j & 1 and i > r:
        ok = False
        break
    if not (j & 1) and i > l:
        ok = False
        break

if not ok:
    print(-1)
    quit()

check(1)