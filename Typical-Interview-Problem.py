# Author : ysh
# 03/01/2023 Wed 11:34:41.07
# https://codeforces.com/contest/1796/problem/A
a = ''
for i in range(1,31):
    if i % 3 == 0:
        a = a + 'F'
    if i % 5 == 0:
        a = a + 'B'
a = a + a
for j in range(int(input())):
    r = input()
    r = input()
    print(['NO','YES'][a.find(r) != -1])
quit()