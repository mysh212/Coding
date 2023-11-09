# Author : ysh
# 2023/09/16 Sat 09:08:45
f = input().split()
a = f[0]
b = int(f[1])

last = b
now = ''
ans = 0
z = ''
for i in a[::-1]:
    tmp = now
    now = i + now
    # print(now)
    if int(now) > last:
        if int(now[1:]) == 0:
            print('NO WAY')
            quit()
        ans = ans + 1
        last = int(tmp)
        for j in now[1:]:
            if j != '0':
                break
            z = z + '0'
        now = i + z
        z = ''
        # print(now)
        if int(now) > last:
            print('NO WAY')
            quit()
    if last < int(i):
        print('NO WAY')
        quit()
# print(now)
print(ans)
quit()