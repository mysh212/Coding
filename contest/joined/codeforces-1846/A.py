# Author : ysh
# 2023/07/07 Fri 22:36:57
for i in range(int(input())):
    n = []
    ans = 0
    for j in range(int(input())):
        n.append([int(i) for i in input().split()])
        if n[j][0] - n[j][1] > 0:
            ans = ans + 1
    print(ans)
quit()