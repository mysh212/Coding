# Author : ysh
# 04/14/2022 Thu 22:13:28.39
while True:
    try:
        a = int(input())
        print((a*(a-1) // 2) + 1)
    except:
        break