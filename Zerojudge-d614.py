a = int(input())
for i in range(a):
    ans = 0
    for j in input().split(" + "):
        ans = ans + int(j)
    print(ans)