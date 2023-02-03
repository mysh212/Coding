# Author : ysh
# 02/03/2023 Fri 22:21:31.76
# https://codeforces.com/gym/425267
n = int(input())
last = 0
ans = 0
for i in sorted([int(i) for i in input().split()]):
    if last == 0:
        last = i
        continue
    if i <= last:
        ans = ans + ((last + 1) - i)
        last = last + 1
    else:
        last = i
print(ans)