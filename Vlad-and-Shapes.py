# Author : ysh
# 2024/02/20 Tue 09:18:16
# https://codeforces.com/contest/1926/problem/B
for i in range(int(input())): (lambda n: print(['TRIANGLE','SQUARE'][len(list(set([i.count(1) for i in [[int(j) for j in input()] for i in range(n)]]))) <= 2]))(int(input()))