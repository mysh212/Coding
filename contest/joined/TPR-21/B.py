# Author : ysh
# 05/29/2022 Sun 15:05:47.33
from tkinter import E
from numpy import gcd


a = [int(i) for i in input().split()]
c = a[0]
d = a[1]
if c > d:
    e = c
    c = d
    d = e
if d - c == 1:
    print(-1)
    quit()
print(d - c)
quit()