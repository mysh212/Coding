# Author : ysh
# 06/19/2022 Sun 16:37:16.65
while True:
    try:
        a = [int(i) for i in input().split()][1:]
        b = len(a)
        if sum(a) / b > 59:
            print('no')
            continue
        print('yes')
    except:
        break
quit()