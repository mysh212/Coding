# Author : ysh
# 2024/01/12 Fri 12:39:08
import requests
from bs4 import BeautifulSoup

def get_page_html(url):
    response = requests.get(url)
    return response.text

def parse_page_html(html,tag):
    soup = BeautifulSoup(html, 'html.parser')
    problems = soup.select(tag)
    return problems

def get_problem_tags(url):
    html = parse_page_html(get_page_html(url),'span.tag-box')
    tags = []
    for i in html:
        tags.append(i.text.replace('\n','')[4:])

    contest_name = parse_page_html(get_page_html(url),'table.rtable')[0].select_one('th.left').text
    contest_url = 'https://codeforces.com' + parse_page_html(get_page_html(url),'table.rtable')[0].select_one('th.left').select_one('a').get('href')
    return tags, contest_name, contest_url

def parse_tags_text(url: str) -> str:
    try:
        tags, contest_name, contest_url = get_problem_tags(url)
        s = '{% note warning %}\n***Codeforces***\n\n`出處` [***<contest_name>***](<contest_url>)\n`難度` `<difficulty>`\n`標籤` <tags>\n\n{% endnote %}'
        s = s.replace('<contest_name>',contest_name)
        s = s.replace('<contest_url>',contest_url)
        tag = ''
        difficulty = 0
        for i in tags:
            tag = f'{tag} `{i.replace('\n','').replace('\r','')}`'
            if i.find('*') != -1: difficulty = i.replace('\n','').replace('\r','').replace('*','');
        s = s.replace('<difficulty>',difficulty)
        s = s.replace('<tags>',tag)
        return s
    except:
        return ''