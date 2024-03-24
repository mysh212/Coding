# Author : ysh
# 2024/01/23 Tue 23:23:05
a,b,c = [int(i) for i in input().split()]
assert(1 <= a <= 10 ** 5)
assert(b <= a)
assert(1 <= c <= a * 5)

for i in range(b):
    n,m,k = input().split()
    assert(n == '+')
    m = int(m)
    k = int(k)
    assert(1 <= m <= a)
    assert(0 <= k <= 10 ** 9)

for j in range(c):
    n,m,r,k = input().split()
    assert(n == '-')
    m = int(m)
    r = int(r)
    k = int(k)
    assert(1 <= m <= a)
    assert(1 <= r <= a)
    assert(0 <= k <= 10 ** 9)

try:
    n = input()
except EOFError:
    quit()

assert(False)
quit()
    