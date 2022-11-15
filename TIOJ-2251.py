# Author : ysh
# 2022/11/15 Tue  9:47:03.77
n = input()
ans = 0
last = 0
for i in sorted([int(i) for i in input().split()]):
    last = last + i
    ans = ans + last
print(ans)
quit()