n = int(input())
a = []
for i in range(1,n):
    a.append(0)
    a.append(i)
for i in range(1,n):
    a.append(0)
    a.append(i)
a.append(0)
print(len(a))
for i in a:
    print(i,end = ' ')
quit()