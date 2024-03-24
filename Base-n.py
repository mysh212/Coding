# Author : ysh
# 2024/01/21 Sun 22:14:02
# https://atcoder.jp/contests/abc192/tasks/abc192_d
a = int(input())
b = int(input())

def check(x:int) -> bool:
    last = 0
    for i in str(a):
        last = last * x + int(i)
        if last > b:
            return False
    return True

def ck(l: int,r: int) -> int:
    if l + 1 == r: return l;
    mid = (l + r) >> 1
    if check(mid): return ck(mid,r)
    else: return ck(l,mid)

if len(str(a)) == 1:
    if a <= b:
        print(1)
    else:
        print(0)
    quit()

print(ck(max([int(i) for i in str(a)]),10 ** 20) - max([int(i) for i in str(a)]))
quit()