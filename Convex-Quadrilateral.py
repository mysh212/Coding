# Author : ysh
# 08/27/2022 Sat 20:55:26.75
# https://atcoder.jp/contests/abc266/tasks/abc266_c
# NF
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]
d = [int(i) for i in input().split()]
aa = 0
bb = 0
x = a[0] - c[0]
y = a[0] - c[0]
aa = y / x
bb = a[1] - aa * a[0]
if (aa * b[0] + bb - b[1]) * (aa * d[0] + bb - d[1]) >= 0:
    print("Yes")
    quit()
tmp = a
a = b
b = tmp
tmp = c
c = d
d = tmp
aa = 0
bb = 0
x = a[0] - c[0]
y = a[0] - c[0]
aa = y / x
bb = a[1] - aa * a[0]
if (aa * b[0] + bb - b[1]) * (aa * d[0] + bb - d[1]) >= 0:
    print("Yes")
    quit()
print("No")
quit()