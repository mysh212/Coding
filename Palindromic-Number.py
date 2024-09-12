# Author : ysh
# 2024/08/05 Mon 11:26:23
# https://atcoder.jp/contests/abc363/tasks/abc363_d
f = []
for i in range(1,18 + 1):
    f.append((10 ** i) * 0.9)
    f.append((10 ** i) * 0.9)

f[0] = f[0] + 1
f = [int(i) for i in f]
# print(f)

n = int(input()) - 1
# if n <= 10:
#     print(n - 1)
#     quit()

for j in range(len(f)):
    i = f[j]
    if i > n:
        j = j + 1
        left = (j + 1) >> 1
        now = (j + 1) & 1
        # left = j
        right = j - 1 + now
        # print(j,left,right,n)
        ans = (10 ** (left - 1) if j != 1 else 0) + n
        print(f'{ans}{str(ans)[::-1][now ^ 1:]}')
        quit()
    else:
        n = n - i
