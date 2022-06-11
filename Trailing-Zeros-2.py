# Author : ysh
# 06/05/2022 Sun  7:18:27.43
# https://192.168.193.20/contest/2/problem/024
a = int(input())
ans = 0
while a != 0:
    ans = ans + a // 5
    a = a // 5
print(ans,end = '')
quit()