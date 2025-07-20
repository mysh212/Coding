# Author : ysh
# 2025/07/06 Sun 22:02:16
a, b = [int(i) for i in input().split()]
f = [int(i) for i in input().split()]

def check(x: int) -> bool:
    sig = 0
    for i in f:
        if i <= x:
            continue
        sig += (i - x)
    return sig >= b

def ck(l: int, r: int) -> int:
    if l + 1 == r:
        return l
    
    mid = (l + r) >> 1
    if check(mid):
        return ck(mid, r)
    else:
        return ck(l, mid)

print(ck(0, max(f)))