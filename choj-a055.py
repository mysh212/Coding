# Author : ysh
# 04/23/2022 Sat 22:12:02.23
# http://e.co/problem/a055
a = []
for i in input().split():
    if i == '0':
        break
    a.append(int(i))
for i in range(int(input())):
    n = input()
    if n.find(' ') != -1:
        a.append(int(n[4:]))
    if n == "Qry":
        if len(a) == 0:
            print("Empty")
            continue
        for j in a:
            print(j,end = ' ')
        print('')
    if n == "Del":
        try:
            tmp = a.pop()
        except:
            print("Error")
    if n == "Clear":
        a.clear()