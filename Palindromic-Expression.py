# Author : ysh
# 2024/08/05 Mon 16:21:54
# https://atcoder.jp/contests/abc363/tasks/abc363_f
pre = []
for i in range(10000):
    # if i == 1: continue;
    if str(i).find('0') != -1: continue;
    pre.append([int(str(i) + str(i)[::-1]),int(str(i) + str(i)[::-1]),-1])
    pre.append([int(str(i) + str(i)[::-1][1:]),int(str(i) + str(i)[::-1][1:]),-1])
    pre.append([i * int(str(i)[::-1]),i,int(str(i)[::-1])])

pre = sorted(pre)
while pre[0][0] == 1: pre = pre[1:];

last = 0
for i in pre:
    assert(i[0] >= last)
    last = i[0]

def check(x: int,now: bool) -> list:
    # print(x)
    if x == 1:
        return []
    ans = [-1]
    for i in pre:
        if i[0] > x:
            # print(i[0],x)
            return [-1]
        if x % i[0] != 0:
            continue
        if now and i[2] == -1:
            continue
        ans = check(x // i[0],1 if i[2] == -1 else now)
        if ans != [-1]:
            break
    if ans != [-1]: ans.append(i[1:]);
    return ans
    

n = int(input())
p = check(n,False)
# print(p)

if n == 1:
    print(1)
    quit()

if p == [-1]:
    print(-1)
    quit()

left = []
right = []
for i in p:
    if i[1] == -1:
        right = right[::-1]
        right.append(i[0])
        right = right[::-1]
        continue
    left.append(i[0])
    right.append(i[1])

ans = []
for i in left[::-1]:
    ans.append(i)

for j in right:
    ans.append(j)

print('*'.join([str(i) for i in ans]))
quit()