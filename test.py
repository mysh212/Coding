# Author : ysh
# 2025/05/19 Mon 11:03:05
from random import randint as ri

for i in range(100):
    # n = ri(1, 1000)
    n = 10 ** 5
    print(n)
    print(' '.join([str(ri(0, 10)) for _ in range(n)]))
    print('')

quit()