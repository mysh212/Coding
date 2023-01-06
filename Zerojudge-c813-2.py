# Author : ysh
# 01/01/2023 Sun 22:06:04.85
while True:
    try:
        n = input()
        if n == '0':
            break
        if int(n) % 9 == 0:
            print(9)
            continue
        print(int(n) % 9)
    except:
        break
quit()