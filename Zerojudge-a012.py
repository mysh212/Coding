# Author : ysh
# 02/23/2023 Thu 16:02:49.18
while True:
    try:
        a = [int(i) for i in input().split()]
        print(abs(a[0] - a[1]))
    except:
        break
quit()