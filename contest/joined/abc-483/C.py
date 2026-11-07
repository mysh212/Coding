# Author : ysh
# 2026/11/07 Sat 20:08:31
from collections import defaultdict

mark = defaultdict(dict)

n, m = [int(i) for i in input().split()]
f = [[int(i) for i in input().split()] for _ in range(m)]

ct = [0 for _ in range(n + 1)]

for j, i in f:
    mark[j][i] = mark[j].get(i, 0) + 1

# print(mark)

for j, i in f:
    ct[j] += 1

mmax = max(ct)
d = -1
for j, i in enumerate(ct):
    if i == mmax:
        d = j
        break

# print(ct, d)
# print(mark)

for i in range(1, n + 1):
    pre = []
    for j, i in zip(mark[i].keys(), mark[i].values()):
        if ct[j] + i > mmax:
            pre.append([j, ct[j] + i])
    # print('pre', pre)
    if len(pre) == 0:
        if i == d:
            tmp = [[ct[i], i] for i in range(n + 1)]
            print(sorted(tmp)[::-1][1][1])
            continue
        print(d)
    else:
        pre = sorted(pre)
        _d = -1
        _mmax = 0
        for j, i in pre:
            if i > _mmax:
                _mmax = i
                _d = j
        print(_d)

quit()