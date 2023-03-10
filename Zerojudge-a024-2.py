# Author : ysh
# 03/10/2023 Fri 14:19:03.54
def gcd(a,b):
    if a < b:
        a,b = b,a
    if b == 0:
        return a
    return gcd(b,a % b)

a = [int(i) for i in input().split()]
print(gcd(a[0],a[1]))
quit()