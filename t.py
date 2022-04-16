# Author : ysh
# 04/12/2022 Tue 21:42:17.67
a = 0
while True:
    try:
        for i in input().split():
            if i == '':
                break
            a = a + int(i)
    except:
        print(a)
        break