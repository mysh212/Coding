# Author : ysh
# 2023/12/11 Mon 14:29:40
while True:
    try:
        a = int(input())
        ans = 0
        while a != 0:
            ans = ans + a // 5
            a = a // 5
        print(ans)
    except:
        break
quit()