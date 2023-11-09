# Author : ysh
# 2023/09/21 Thu 22:42:17
for i in range(int(input())):
    n = int(input())
    f = sorted([int(i) for i in input().split()])
    f[0] = f[0] + 1
    ans = 1
    for i in f:
        ans = ans * i
    print(ans)
quit()