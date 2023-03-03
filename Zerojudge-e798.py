# Author : ysh
# 03/03/2023 Fri 16:43:41.14
n = int(input())
a = []
for i in range(n):
    a.append([int(i) for i in input().split()])
for i in range(0,n,2):
    for j in range(0,n,2):
        print(max(max(a[i][j],a[i + 1][j]),max(a[i][j + 1],a[i + 1][j + 1])),end = ' ')
    print('')
quit()