# Author : ysh
# 06/27/2022 Mon  7:46:24.01
while True:
    try:
        a = input()
        b = [i for i in input().split()]
        c = b[0].find(b[1])
        if c == -1:
            print("No")
            continue
        print("Yes\npos: " + str(c))
    except:
        break
quit()