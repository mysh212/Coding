# Author : ysh
# 03/18/2023 Sat 22:00:21.95
from random import randint as ri
r = int(input())
print(r)
for i in range(r):
    print(5)
    for j in range(5):
        print(f'{ri(0,5)}',end = ' ')
    print('')