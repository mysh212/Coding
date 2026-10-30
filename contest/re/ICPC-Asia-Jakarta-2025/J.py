# Author : ysh
# 2026/10/29 Thu 17:15:42
n, a, b = [int(i) for i in input().split()]

last = 0
ct = 0
f = []
while n != 0:
    now = n & 1
    if last != now and ct != 0:
        f.append([ct, last])
        ct = 0
    last = now
    ct += 1
    n = n >> 1

f = f[1:]
pre = [len([i for i in f if i[1] == j and i[0] == 1]) != 0 for j in range(2)]

if (pre[0] and pre[1]):
    print('NO')
    quit()

# print(f)

if a == b and a >= 1 and b >= 1:
    print('YES')
else:
    print('NO')