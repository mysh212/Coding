# Author : ysh
# 11/24/2022 Thu 21:54:12.31
while True:
    try:
        a = int(input())
        if a % 400 == 0:
            print('�|�~')
            continue
        if a % 100 == 0:
            print('���~')
            continue
        if a % 4 == 0:
            print('�|�~')
            continue
        print('���~')
    except:
        break
quit()