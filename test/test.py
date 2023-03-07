# Author : ysh
# 03/07/2023 Tue 11:44:48.89
from random import randint as ri
for i in range(1,int(input()) + 1):
    f = open(f'{i}.in','w')
    n = 100
    k = ri(1,(n * (n + 1)) >> 1)
    f.write(f'{n} {k}\n')
    for j in range(n):
        f.write(f'{ri(-1e9,1e9)} ')
    f.close()