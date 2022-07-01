# Author : ysh
# 06/30/2022 Thu 12:46:07.07
from curses.ascii import isdigit
def check(i):
    if i == '+' or i == '-' or i == '*' or i == '/' or i == '%':
        return True
    return False
for j in range(int(input())):
    t = ''
    for i in input():
        if isdigit(i):
            if i == '0':
                if check(t[len(t) - 1:]):
                    continue
            t = t + i
        if check(i):
            t = t + i
    print(eval(t.replace('/','//')))