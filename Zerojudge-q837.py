# Author : ysh
# 2025/06/18 Wed 18:43:45
a, b, c = [int(i) for i in input().split()]
f = [input() for _ in range(a)]

ans = 0
for pre in [[int(j) for j in input().split()] for _ in range(c)]:
    now = f
    for i in range(a):
        pre[i] %= b
        now[i] = now[i][-pre[i]:] + now[i][:-pre[i]]
    # print(now)
    pre = [[j[i] for j in now] for i in range(b)]
    # print(pre)
    for i in pre:
        mmax = 0
        for j in set(i):
            mmax = max(mmax, i.count(j))
        # print(i, mmax)
        ans += mmax

print(ans)
quit()