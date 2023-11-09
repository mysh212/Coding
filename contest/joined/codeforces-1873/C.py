# Author : ysh
# 2023/09/21 Thu 22:45:23
for i in range(int(input())):
    f = []
    f.append(input())
    for i in range(len(f[0]) - 1):
        f.append(input())
    ans = 0
    for i in range(len(f)):
        for j in range(len(f)):
            if f[i][j] == 'X':
                x = min(i + 1,(len(f) - (i + 1)) + 1)
                y = min(j + 1,(len(f) - (j + 1)) + 1)
                ans = ans + min(x,y)
    print(ans)
quit()