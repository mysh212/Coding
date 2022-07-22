# Author : ysh
# 07/22/2022 Fri  6:19:41.81
a = input()
b = [int(i) for i in input().split()]
mmin = b[0]
ans = 0
for i in b:
    mmin = min(mmin,i)
    ans = max(ans,i - mmin)
    # print(ans,end = ' ')
print(ans)