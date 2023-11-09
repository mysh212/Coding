# Author : ysh
# 2023/08/29 Tue 10:43:45

n = input().replace('"','').split(';')
r = 50
for i in n:
    print('#define ',end = '')
    if r == 90:
        r = r + 2
    for _ in range(r):
        print('_',end = '')
    print(' "' + i + '"')
    r = r + 1