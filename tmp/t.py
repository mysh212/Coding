# Author : ysh
# 02/03/2023 Fri 13:55:11.37
from random import randint as ri
import random

for i in range(int(input())):
    f = open(f'{i + 1}.in','w')
    a = '1234567890'
    for j in range(10):
        f.write(str(ri(0,9)))
    f.write(' ')
    for k in range(3):
        f.write(str(ri(0,9)))
    f.close()
quit()