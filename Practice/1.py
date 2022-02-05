n=int(input())
num=[]
temp=input().split()
for i in range(n):
    num.append(temp[i])
a,b=map(int,input().split())
print(sum([int(num[i]) for i in range(a-1,b)]))