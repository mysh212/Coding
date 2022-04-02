#https://192.168.193.20/problem/18
a = int(input())
for i in range(a):
    ans = 0
    for j in input().split():
        ans = ans + int(j)
    print(ans)