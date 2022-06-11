# Author : ysh
# 06/05/2022 Sun  6:42:03.66
# https://192.168.193.20/contest/2/problem/024
r = 5
a = int(input())
ans = 0
while True:
    ans = ans + a // r
    r = r * 5
    if r > a:
        break
print(ans,end = '')
quit()