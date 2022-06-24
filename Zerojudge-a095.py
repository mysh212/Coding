# Author : ysh
# 06/21/2022 Tue  8:21:58.16
while True:
    try:
        a = [int(i) for i in input().split()]
        if a[0] == a[1]:
            print(a[1])
            continue
        print(a[1] + 1)
    except:
        break
quit()