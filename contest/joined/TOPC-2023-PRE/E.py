# Author : ysh
# 2023/09/16 Sat 09:53:19
import os

def eg(a,b):
    if a == 0:
        return (b,0,1)
    g,y,x = eg(b % a,a)
    return (g,x - (b // a) * y,y)

def rv(a,b):
    t,x,_ = eg(a,b)
    # assert(t == 1)
    return x % b

r = 0
d = {}
def check(i,j):
    # os.system('pause')
    if d.get(j,-1) != -1:
        return d.get(j,-1)
    print(i,j)
    # print(j)
    if j == 1:
        return i
    tmp = check(i,j >> 1)
    tmp = (tmp * tmp - 2) % r

    if j & 1:
        d[j] = (tmp * check(a,1) - check(i,j - 2)) % r;
        # d[j] = (((tmp + check(i,j + 1)) * rv(check(i,1),r))) % r
        return d[j]
    d[j] = tmp
    return tmp

a,b,r = [int(i) for i in input().split()]
print(check(a,b))
print(d)