# Author : ysh
# 11/12/2022 Sat 13:10:29.79
from random import randint as ri
n = int(input())
print(n)
for i in range(n):
    if ri(0,1) == 1:
        print(1,end = ' ')
    else:
        print(-1,end = ' ')
print('')
m = int(input())
print(m)
for i in range(m):
    print(ri(1,n),end = ' ')
    print(ri(1,n))
quit()