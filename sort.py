#https://192.168.193.20/problem/15
a = []
n = int(input())
tmp = 0
for i in input().split():
    if i != '':
        a.append(int(i))
a = sorted(a)
for i in a:
    print(str(i),end=' ')
print('')