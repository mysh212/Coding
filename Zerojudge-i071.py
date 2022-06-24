# Author : ysh
# 06/19/2022 Sun 16:50:29.54
a = [int(i) for i in input().split()][1]
last = -1
ans = -1
b = [int(i) for i in input().split()]
for j in b[(a - 1):]:
    # print(last,end = ' ')
    if j > last:
        ans = ans + 1
    last = max(last,j)
last = b[a - 1]
for j in b[:(a - 1)][::-1]:
    # print(last,end = ' ')
    if j > last:
        ans = ans + 1
    last = max(last,j)
print(ans)
quit()