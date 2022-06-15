# Author : ysh
# 06/15/2022 Wed  9:56:27.35
import os
a = {}
os.system('dir /B *.cpp>cpp.tmp')
os.system('dir /B *.py>py.tmp')
f = open('cpp.tmp','r')
for i in f:
    ff = open(i,'r')
    for j in ff:
        for k in j:
            a[k] = a.get(k,0) + 1
    ff.close()
f.close()
f = open('py.tmp','r')
for i in f:
    ff = open(i,'r')
    for j in ff:
        for k in j:
            a[k] = a.get(k,0) + 1
    ff.close()
f.close()
for i in a.keys():
    print(str(i) + a.get(i,0))
quit()