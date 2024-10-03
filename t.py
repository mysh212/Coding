# Author : ysh
# 2024/09/23 Mon 16:33:15
import requests
from bs4 import BeautifulSoup as bs

url = 'https://jmj.cmgsh.tp.edu.tw/Problems?tag=Prof.%20Wu'
html = requests.get(url)

soup = bs(html.text, 'html.parser')
now = (soup.select_one('table', _class = 'table table-hover').find_all('a'))

# print([i.text.strip() for i in now])

ans = []
for i in range(0,len(now),4):
    ans.append([now[i].text, now[i]['href'].replace('.', 'https://jmj.cmgsh.tp.edu.tw')])

for i in ans[:1]:
    p = (requests.get(i[1]).text)
    sp = bs(p, 'html.parser')
    print(len(sp.find_all('panel-body')))