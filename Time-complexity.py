# Author : ysh
# 02/07/2023 Tue 15:28:51.92
# https://codeforces.com/group/H0qY3QmnOW/contest/425166/problem/C
a = 'O('
for i in range(int(input())):
    b = input()
    if b[0] != ' ':
        if(a[::-1][0] != '('):
            a = a + '+'
    b = b.replace(' ','')
    b = b.replace('for','')
    b = b.replace('(','')
    b = b.replace(')','')
    c = b.split(';')[1].split('<')[1]
    a = a + str(c)
a = a + ')'
print(a)