# Author : ysh
# 2024/01/11 Thu 13:14:02
import os
import requests, bs4
from datetime import datetime
from problem_special import *
import codeforces

template = 'export-md\\export-md\\template.md'
sp = {'zerojudge': 'Zerojudge', 'cses': 'CSES', 'AP325': 'AP325', 'tcirc': 'TCIRC', 'tioj': 'TIOJ', 'codeforces': 'Codeforces', 'luogu': '洛谷', 'atcoder': 'AtCoder', 'kattis': 'Kattis'}
ignore = {}

def get_special(url: str) -> str:
    if get_judge(url) == 'Codeforces':
        return codeforces.parse_tags_text(url)
    if get_judge(url) == 'Zerojudge' or get_judge(url) == 'TCIRC':
        return '{% note info %}\n' + f'***{get_judge(url)}***\n[**解題紀錄**]({url.replace("ShowProblem","Submissions")}&account=mysh212@gmail.com)\n' + '{% endnote %}'
    return ''

def get_judge(url: str):
    for i in sp:
        if url.find(i) != -1:
            return sp.get(i,'')
    return 'Others'

def parse_date(date: str):
    try:
        date = date[:23]
        day = datetime.strptime(date, '%m/%d/%Y %a %H:%M:%S')
        return str(day)
    except:
        date = date[:23]
        day = datetime.strptime(date, '%Y/%m/%d %a %H:%M:%S')
        return str(day)

def get_title(name: str,url: str):
    if url.find('codeforces.com') != -1:
        return f'{get_judge(url)} - {name.replace('.cpp','').replace('.py','')}'
    if url.find('luogu.') != -1:
        return f'{get_judge(url)} - {name.replace('luogu-','').replace('.cpp','').replace('.py','')}'
    # if url.find('tioj') != -1:
    #     return f'{get_judge(url)} - {name.replace('tioj-','').replace('TIOJ-','').replace('.cpp','').replace('.py','')}'
    try:
        url = url.replace('choj.me','oj.chsh.chc.edu.tw')
        r = requests.get(url)
        html = bs4.BeautifulSoup(r.text,"html.parser")
        if html.title.text == 'OnlineJudge': return;
        return html.title.text
    except:
        return

def geturl(x):
    if x.find('Zerojudge') != -1:
        return f'https://zerojudge.tw/ShowProblem?problemid={x[10:14]}'
    if x.find('tcirc') != -1:
        return f'https://judge.tcirc.tw/ShowProblem?problemid={x[6:10]}'
    if x.find('AP325') != -1:
        return f'https://judge.tcirc.tw/ShowProblem?problemid={x[6:10]}'
    if x.find('tioj') != -1:
        return f'https://tioj.ck.tp.edu.tw/problems/{x[5:9]}'
    try:
        g = open(x,'r')
        t = 0
        for i in g:
            t = t + 1
            if t == 3:
                if i[:7] == '// http':
                    return i[3:].replace('\n','')
                if i[:6] == '# http':
                    return i[2:].replace('\n','')
                return
        return
    except:
        return
    
def export_tags(x):
    if tags.get(x,[]) == []:
        return ''
    else:
        ans = ''
        for i in tags.get(x,[]):
            ans = f'{ans},\'{i}\''
        return ans[0:]
    return
    
def readfile(x):
    try:
        f = open(x,'r')
        ans = ''
        for i in f:
            ans = ans + i
        return ans
    except:
        return
    
tp = readfile(template)
    
def makefile(title:str,name:str,date:str,tag:str,code:str,url:str = '',judge = ''):
    print(f'Making file for {name}...\n')
    ans = tp.replace('<name>',name)
    ans = ans.replace('<title>',title)
    ans = ans.replace('<date>',date)
    ans = ans.replace('<tag>',tag)
    ans = ans.replace('<code>',code)
    ans = ans.replace('<url>',url)
    t = 'cpp'
    if name.find('.py') != -1:
        t = 'py'
    ans = ans.replace('<type>',t)
    ans = ans.replace('<judge>',judge)
    ans = ans.replace('<special>',if_bad_problem(code) + get_special(url))
    return ans

def file_exist(x: str) -> bool:
    try:
        f = open(x,'r')
        return True
    except:
        return False
        
def writefile(a,b):
    ff = open(a,'w')
    ff.write(b)
    ff.close()
    return

f = open('tags.info','r')
mc = open('mc.info','r')
igr = open('ignore.info','r')

tags = {}
url = {}

for i in f:
    # os.system(f'title Parsing {i}')
    a,b = [j.replace('\n','') for j in i.split('\t')]
    if tags.get(a,[]) == []:
        tags[a] = [b]
    else:
        tags[a].append(b)

lines = readfile('mc.info').count('\n')
line = 0

for i in igr:
    ignore[i.split()[0]] = 1
igr.close()
        
for i in mc:
    a,b = [j.replace('\n','') for j in i.split('        ')]
    print(f'Exporting... {line} / {lines}')
    line = line + 1
    if file_exist('export-md\\export-md\\' + b + '.md'): continue
    if ignore.get(b,-1) != -1: continue;
    if b[:5] == 'APCS-':
        if tags.get(b,[]) == []: continue
        if readfile(b) is None: continue
        writefile('export-md\\export-md\\' + b + '.md',makefile(f'APCS - {b[5:]}',b,parse_date(a),export_tags(b),readfile(b),'','APCS'))
        continue
    if geturl(b) is not None:
        url[b] = geturl(b)
        if tags.get(b,[]) == []: continue
        if readfile(b) is None: continue
        if get_title(b,url[b]) is None:
            f = open('ignore.info','a')
            f.write(f'{b} {url[b]}\n')
            f.close()
            continue
        
        writefile('export-md\\export-md\\' + b + '.md',makefile(get_title(b,url[b]),b,parse_date(a),export_tags(b),readfile(b),url[b],get_judge(url[b])))
quit()