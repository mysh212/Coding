# Author : ysh
# 06/14/2022 Tue 22:36:26.42
for i in range(int(input())):
    a = [int(i) for i in input().split()]
    ans = 0
    for j in range(1,4):
        # print(j)
        if a[j] > a[0]:
            ans = ans + 1
    print(ans)
