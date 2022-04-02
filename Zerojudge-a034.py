while True:
    try:
        a = int(input())
        b = []
        c = 0
        while True:
            b.append(a % 2)
            c = c + 1
            a = a // 2
            if a == 0:
                break
        for i in range(c):
            print(b[c-i-1],end='')
        print('')
    except:
        break