# Author : ysh
# 02/06/2023 Mon 11:37:30.54
import random

n = int(input())
print(1)
print(n)
a = [i + 1 for i in range(n)]
random.shuffle(a)
for i in a:
    print(i,end = ' ')
quit()