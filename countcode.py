# Author : ysh
# 06/15/2022 Wed  9:56:27.35
import os
a = {}
os.system('dir /B *.cpp>cpp.tmp')
os.system('dir /B *.py>py.tmp')
f = open('cpp.tmp','r')
for i in f:
    ff = open(i[:(len(i) - 1)],'r',encoding = 'ANSI')
    print(i)
    try:
        for j in ff:
            for k in j:
                a[k] = a.get(k,0) + 1
    except:
        ff.close()
        ff = open(i[:(len(i) - 1)],'r',encoding = 'UTF-8')
        for j in ff:
            for k in j:
                a[k] = a.get(k,0) + 1
    ff.close()
f.close()
f = open('py.tmp','r',encoding = 'ANSI')
for i in f:
    print(i)
    ff = open(str(i)[:len(i) - 1],'r',encoding = 'ANSI')
    try:
        for j in ff:
            for k in j:
                a[k] = a.get(k,0) + 1
    except:
        ff.close()
        ff = open(i[:(len(i) - 1)],'r',encoding = 'UTF-8')
        for j in ff:
            for k in j:
                a[k] = a.get(k,0) + 1
    ff.close()
f.close()
n = 0
sig = 0
for i in sorted(a.keys()):
    print(str(i) + ' ' + str(a.get(i,0)),end = '\t')
    sig = sig + a.get(i,0)
    n = n + 1
    if n == 10:
        n = 0
        print('')
ff = open('count.info','r')
a = ''
for i in ff:
    a = i
print('\ncharacter count: ' + str(sig))
print('\ncharacter increasing rate: ' + str(sig - int(a)))
ff.close()
ff = open('count.info','a')
ff.write(str(sig) + '\n')
ff.close()
quit()