# Author : ysh
# 07/20/2022 Wed 20:36:24.04
a = input()
a = 0
last = 0
b = sorted([int(i) for i in input().split()])
for i in b:
    a = a + (last + i)
    last = last + i
print(a)
quit()