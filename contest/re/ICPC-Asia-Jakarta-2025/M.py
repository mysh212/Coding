# Author : ysh
# 2026/10/29 Thu 17:42:39
n, m, k = [int(i) for i in input().split()]
f = [[int(i) for i in input().split()] for _ in range(k)]

R = (998244353)

def fp(a: int, b: int) -> int:
    if b == 0:
        return 1

    now = fp(a, b >> 1)
    now = (now * now) % R

    return (now if not b & 1 else (now * a) % R)

def rev(x: int) -> int:
    return fp(x, R - 1 - 1)

ans = pow(m, n - k, R)
# ans = (ans * fp(rev(m), k)) % R

print(ans)