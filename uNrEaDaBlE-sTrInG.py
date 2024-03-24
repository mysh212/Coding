# Author : ysh
# 2024/01/21 Sun 21:09:48
# https://atcoder.jp/contests/abc192/tasks/abc192_b
from curses.ascii import islower, isupper


n = 1
for i in input():
    if n & 1:
        if isupper(i):
            print('No')
            quit()
    else:
        if islower(i):
            print('No')
            quit()
    n = n + 1
print('Yes')
quit()