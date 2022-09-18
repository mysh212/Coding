n = int(input())
for _ in range(n):
    m = input().split()
    if m[0] == '4':
        r = m[1].split('.')
        out = True
        if len(r) != 4:
            print('QAQ')
            out = False
            continue
        for j in r:
            # print(j)
            if out == False:
                break
            if j == '':
                print('QAQ')
                out = False
                break
            if j == '0':
                continue
            if j[0] == '0':
                print('QAQ')
                out = False
                break
            for k in j:
                if out == False:
                    break
                if k < '0' or k > '9':
                    print('QAQ')
                    out = False
                    break
            if out == True:
                if int(j) > 255 or int(j) < 0:
                    print('QAQ')
                    out = False
                    break
        if out == True:
            print('Valid_IP')
    if m[0] == '6':
        r = m[1].split(':')
        out = True
        if len(r) != 8:
            out = False
        for i in r:
            if len(i) < 1 or len(i) > 4:
                out = False
            for j in i:
                if j <= 'F' and j >= 'A':
                    continue
                if j <= 'f' and j >= 'a':
                    continue
                if j <= '9' and j >= '0':
                    continue
                out = False
        if out == False:
            print('QAQ')
        else:
            print('Valid_IP')

