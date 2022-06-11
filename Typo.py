# Author : ysh
# 06/06/2022 Mon 18:59:39.56
# https://192.168.193.20/contest/2/problem/01
a = input()
b = input()
if a == b:
    print('Yes')
    quit()
if len(a) != len(b):
    print("No")
    quit()
for i in range(len(a)):
    if a[i:i + 1] != b[i:i + 1]:
        tmpa = a[i + 2:]
        tmpb = b[i + 2:]
        if tmpa == tmpb:
            print("Yes")
            quit()
        print("No")
        quit()
print("Yes")
quit()