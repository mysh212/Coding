# Author : ysh
# 2026/10/24 Sat 20:07:44
s = {}
now = 1
for _ in range(int(input())):
    n = input()
    if n in s:
        print(s.get(n))
    else:
        s[n] = now
        print(now)
        now += 1

quit()