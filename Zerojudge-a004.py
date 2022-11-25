# Author : ysh
# 11/24/2022 Thu 21:54:12.31
while True:
    try:
        a = int(input())
        if a % 400 == 0:
            print('閏年')
            continue
        if a % 100 == 0:
            print('平年')
            continue
        if a % 4 == 0:
            print('閏年')
            continue
        print('平年')
    except:
        break
quit()