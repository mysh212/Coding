# Author : ysh
# 2024/09/30 Mon 00:30:12
a,b = [int(i) for i in input().split()]

f = [[int(i) for i in input().split()] for j in range(int(input()))]
mmin = 10 ** 10
for k in f:
    mmin = min(((a - k[0]) ** 2) + ((b - k[1]) ** 2), mmin)

ans = (([i for i in f if ((a - i[0]) ** 2) + ((b - i[1]) ** 2) == mmin][0]))
print(ans[0], ans[1])

quit()