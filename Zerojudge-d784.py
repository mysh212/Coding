# Author : ysh
# 06/10/2022 Fri 14:00:20.65
for i in range(int(input())):
    a = [int(k) for k in input().split()]
    r = len(a)
    sig = 0
    mmax = -1e9
    for j in range(1,r):
        sig = max(a[j],sig + a[j])
        mmax = max(mmax,sig)
    print(mmax)
quit()