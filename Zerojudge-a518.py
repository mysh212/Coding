# Author : ysh
# 06/20/2022 Mon 11:51:42.21
while True:
    try:
        a = sorted([int(i) for i in input().split()])
        if(a[0] == -1 and a[1] == -1):
            break
        print(min(a[1] - a[0],(a[0] + 100) - a[1]))
    except:
        break
quit()