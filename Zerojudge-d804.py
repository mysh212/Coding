# Author : ysh
# 07/26/2022 Tue 19:52:52.74
a = [int(i) for i in input().split()]
b = sorted([int(i) for i in input().split()])[::-1]
last = 0
ans = 0
for i in b:
    ans = ans + 1
    last = last + i
    if last >= a[1]:
        print(ans)
        quit()
print('OAQ')
quit()