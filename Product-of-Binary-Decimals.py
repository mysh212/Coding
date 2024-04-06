# Author : ysh
# 2024/04/01 Mon 20:20:43
# https://codeforces.com/contest/1950/problem/D
import sys
input = sys.stdin.readline
print = sys.stdout.write

f = []
R = 10 ** 5

def check(now = ''):
    if int([now,'0'][now == '']) > R or len(now) > 6: return;
    if now != '': f.append(int(now));
    check(now + '0')
    check(now + '1')
    return

def unique(x):
    ans = []
    for i in x:
        if len(ans) != 0 and ans[len(ans) - 1] == i: continue;
        ans.append(i)
    return ans

check()
f = unique(sorted(f))
s = set(f)

def ck(c = 1,now = 2):
    if c > R: return;
    s.add(c)
    for i in range(now,len(f)):
        ck(c * f[i],i)
    return

ck()

for i in range(int(input())):
    if int(input()) in s: print('YES')
    else: print('NO')
    print('\n')
quit()