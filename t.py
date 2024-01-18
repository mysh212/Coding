# Author : ysh
# 2024/01/14 Sun 20:56:16
n,m = [int(i) for i in input().split()]
assert(1 <= n <= 26 and 1 <= n <= 1000)
f = {}
ans = 0.0
for i in range(n):
    a,b = input().split()
    assert(f.get(a,-1) == -1)
    f[a] = 1
    ans = ans + float(b)
assert(abs(ans - 1) <= 0.000001)
assert(len(input()) <= 10)
quit()