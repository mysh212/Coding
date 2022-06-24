# Author : ysh
# 06/23/2022 Thu 15:06:34.68
a = {}
c = {}
f = open("mc.info","r")
ff = open("tags.info","r")
b = ""
for j in ff:
    b = b + j
ff.close()
for i in f:
    if b.find(i[34:len(i) - 1]) != -1:
        c[i[:10]] = c.get(i[:10],0) + 1
    a[i[:10]] = a.get(i[:10],0) + 1
for j in sorted(a.keys()):
    print(j + ' ' + str(a.get(j)) + ' ' + str(c.get(j,0)))
f.close()
quit()