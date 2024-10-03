# Author : ysh
# 2024/09/28 Sat 00:00:35

for i in range(int(input())):
    a,b = [int(i) for i in input().split()]
    f = [int(i) for i in input().split()]

    def check(x: int) -> bool:
        now = f.copy()
        for i in range(x):
            

    def ck(l: int, r: int) -> int:
        if l == r:
            return l
        
        mid = (l + r) >> 1
        if check(mid): return ck(mid + 1,r)
        else: return ck(l,mid)

    pre = max(f)
    