# Author : ysh
# 2024/01/10 Wed 11:45:55
import sys

input = sys.stdin.readline
print = sys.stdout.write

R = 10007
def fl(x) -> int:
    ans = 1
    for i in range(1,x + 1):
        ans = ans * i
    return ans

def ck(a,b) -> int:
    if b == 0: return 1;
    tmp = ck(a,b >> 1)
    if b & 1: return (((tmp * tmp) % R) * a) % R;
    return (tmp * tmp) % R

def rv(x) -> int:
    return ck(x,R- 2)

def check(a,b) -> int:
    return (((fl(a) * rv(fl(b))) % R) * rv(fl(a - b))) % R

a,b,c,d,e = [int(i) for i in input().split()]
print(str((((check(c,d) * ck(a,d)) % R) * ck(b,e)) % R))
quit()