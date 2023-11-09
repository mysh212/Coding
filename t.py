# Author : ysh
# 2023/10/02 Mon 16:16:22
n = int(input())
while True:
    try:
        n = int(input())
        if n % 400 == 0:
            print('a leap year')
        elif n % 100 == 0:
            print('a normal year')
        elif not n & 3:
            print('a leap year')
        else:
            print('a normal year')
    except:
        break
quit()