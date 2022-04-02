a = False
b = False
ans = 0
j = ""
for i in input().split():
    if a == False:
        ans = int(i)
    elif b == True:
        if j == "+":
            print(ans + int(i))
        if j == "*":
            print(ans * int(i))
        if j == "/":
            print(ans // int(i))
        if j == "-":
            print(ans - int(i))
    else:
        j = i
        b = True
    a = True