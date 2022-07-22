# Author : ysh
# 07/20/2022 Wed 20:31:25.46
# https://judge.tcirc.tw/ShowProblem?problemid=d042
a = [1,5,10,50][::-1]
for i in range(int(input())):
    n = int(input())
    ans = 0
    for i in a:
        ans = ans + (n // i)
        n = n % i
    print(ans)
quit()