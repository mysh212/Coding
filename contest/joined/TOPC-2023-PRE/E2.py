# Author : ysh
# 2023/09/16 Sat 11:51:56
a,b = [int(i) for i in input().split()]

i,j,k = a,a * a - 4,2

def check(a,j,k):
    if j == 1:
        return a
    tmp = check(a,j >> 1,k)