# Author : ysh
# 2024/02/01 Thu 16:51:03
# https://codeforces.com/problemset/problem/1925/B
# TLE
from math import sqrt

def get(x) -> int:
    ans = 1
    for i in x:
        ans = ans * i
    return ans

def unique(x):
    x = sorted(x)
    f = []
    last = None
    for i in x:
        if last and i == last: continue;
        f.append(i)
    return f

ans = []
def check(a,b,now):
    if b == 0: ans = []
    if b == len(a):
        if not len(now) == 0:
            ans.append(get(now))
        return
    now.append(a[b])
    check(a,b + 1,now)
    ans.pop()
    check(a,b + 1,now)
    return

for i in range(int(input())):
    a,b = [int(i) for i in input().split()]
    f = []
    for i in range(2,int(sqrt(a))):
        if a < i: break;
        while a % i == 0:
            a = a // i
            f.append(i)
    check(f,0,[])

    print(a // b)
quit()