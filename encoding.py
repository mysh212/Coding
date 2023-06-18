# Author : ysh
# 06/05/2023 Mon 21:02:39.81
# while True:
#     try:
#         n = input()
#         print(n.split()[0],n.split()[2],n.split()[1])
#     except:
#         break
# quit()

# t = 1
# while True:
#     try:
#         print(f'#define {input()} ',end = '')
#         for i in range(t):
#             print('_',end = '')
#         print('')
#         t = t + 1
#     except:
#         quit()



# from curses.ascii import isalpha


t = {}
o = input()
while True:
    try:
        n = input()
        k = ''
        for i in n:
            if 'Z' >= i >= 'A' or 'z' >= i >= 'a' or i == '_':
                k = k + i
            elif k != '':
                t[k] = 1
                k = ''
        if k != '':
            t[k] = 1
    except:
        r = 1
        for i in t:
            if o == '1':
                print(f'#define ',end = '')
            else:
                print(f'#define {i} ',end = '')
            for _ in range(r):
                print('_',end = '')
            if o == '1':
                print(' ' + str(i),end = '')
            print('')
            r = r + 1
        quit()