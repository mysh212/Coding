# Author : ysh
# 04/22/2022 Fri 21:51:47.98
f = []
def mk(a,b):
    tmp = 0
    for i in range(b):
        tmp += f[i] * f[b - 1 - i]
        tmp = tmp % (int(1e9) + 9)
    f.append(tmp)
    if a > b :
        mk(a,b + 1)
n = int(input())
f.append(1)
mk(n,1)
# for i in f:
#     print(i)
print(f[n])
quit()