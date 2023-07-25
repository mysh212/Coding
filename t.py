# Author : ysh
# 2023/07/25 Tue 17:24:23
for i in range(int(input())):
    n = int(input())
    a = input()
    while len(a) > 1:
        if a[0] != a[::-1][0]:
            a = a[1:len(a) - 1]
        else:
            break
    print(len(a))
quit()