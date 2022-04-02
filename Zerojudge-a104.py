while True:
    try:
        a = []
        n = int(input())
        tmp = 0
        a = [int(i) for i in (input().split(' '))]
        a = sorted(a)
        for i in a:
            print(str(i),end=' ')
        print('')
    except:
        break