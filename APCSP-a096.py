# Author : ysh
# 05/06/2022 Fri  8:04:51.03
# nc
from numpy import gcd


a = input()
b = input()
ah = int(a[0:2])
am = int(a[3:5])
ac = int(a[6:8])
bh = int(b[0:2])
bm = int(b[3:5])
bc = int(b[6:8])
s = gcd((ah * 3600 + am * 60 + ac) - (bh * 3600 + bm * 60 + bc))
ss = s % 60
s = s / 60
mm = s % 60
s = s / 60
hh = s
