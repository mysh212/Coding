# Author : ysh
# 08/25/2022 Thu 19:25:53.23
# NA
while True:
    try:
        a = input()
        last = 0
        ans = 0
        for i in [int(i) for i in input().split()]:
            if i <= last:
                ans = ans + 1
            last = i
        print(ans + 1)
    except:
        break
quit()