n = int(input())
for j in range(n):
    a = 0
    ans = 0
    c = False
    for i in input().split():
        if c == False:
            c = True
            continue
        ans += int(i)
        a += 1
    # print(ans)
    aans = round(((ans) / a),2)
    print(aans,end = '')
    if aans * 100 // 10 == aans * 10:
        print(0,end = '')
    print('')
quit()