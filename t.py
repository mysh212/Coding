# Author : ysh
# 2024/03/05 Tue 18:04:01
mark = ['1111110','0110000','1101101','1111001','0110011','1011011','1011111','1110000','1111111','1111011']
for i in range(len(mark)):
    mark[i] = mark[i].replace('1','2').replace('0','1').replace('2','0')

for i in range(1 <<4)[::-1]:
    print(f'else if(in[{i}]) BCD = 4\'b{format(i,'b')}')