# Author : ysh
# 2023/11/04 Sat 10:09:22
n = int(input())
f = [(i) for i in input().split()]
assert(len(f) == n)
for i in f:
    assert(len(i) <= 5)
    for j in i:
        assert(1 <= int(j) <= 9)
quit()