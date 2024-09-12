# Author : ysh
# 2024/08/15 Thu 00:13:58
# https://codeforces.com/group/j50SrY6hsZ/contest/542817/problem/A
R = 10 ** 9 + 7

def check(a: int,b: int) -> int:
    if b == 0: return 1;
    tmp = check(a,b >> 1)
    tmp = tmp * tmp % R

    return tmp * a % R if b & 1 else tmp

def rev(x: int) -> int:
    return check(x,R - 1 - 1)

n,m = [int(i) for i in input().split()]

def lt(a,b):
    return [i % R for i in [a[0] * b[0] + a[1] * b[1] * (n - 1),a[1] * b[0] + a[0] * b[1] + a[1] * b[1] * (n - 2)]]

def ck(a,b: int):
    if b == 1: return a;
    tmp = ck(a,b >> 1)
    tmp = lt(tmp,tmp)

    return lt(tmp,a) if b & 1 else tmp

tmp = rev(n - 1)
left = [0,tmp]
right = [1,0]

print(lt(ck(left,m),right)[0])
quit()