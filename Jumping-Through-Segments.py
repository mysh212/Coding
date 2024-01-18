# Author : ysh
# 2023/12/27 Wed 01:00:47
# https://codeforces.com/problemset/problem/1907/D

for i in range(int(input())):
    n = int(input())
    f = [[int(i) for i in input().split()] for j in range(n)]

    def check(x) -> bool:
        l = r = 0
        for i in f:
            l = l - x
            r = r + x
            l = max(l,i[0])
            r = min(i[1],r)
            if l > i[1] or r < i[0]:
                return False
        return True
    
    l = 0
    r = int(1e10)
    while l != r:
        mid = (l + r) >> 1
        if check(mid):
            r = mid
        else:
            l = mid + 1

    print(l)

quit()
