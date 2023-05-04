# Author : ysh
# 03/17/2023 Fri 19:25:11.57
import os,io,sys
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
isprime = [True for i in range((1 << 16))]
prime = []

for i in range(2,1 << 16):
    if  isprime[i]:
        prime.append(i)
    for j in prime:
        if i * j >= (1 << 16):
            break
        isprime[i * j] = False
        if i % j == 0:
            break

while True:
    try:
        n = int(input())
        if n < (1 << 16):
            sys.stdout.write(['非質數\n','質數\n'][isprime[n]])
            continue
        now = 0
        c = True
        while True:
            if prime[now] ** 2 > n:
                break
            if n % prime[now] == 0:
                c = False
                break
            now = now + 1
        sys.stdout.write(['非質數\n','質數\n'][c])
    except:
        break
