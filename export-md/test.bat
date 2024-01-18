copy export-md\*.md C:\Users\ysh00\Documents\實驗室\blog\source\_posts\ /Y
set now=%cd%
del C:\Users\ysh00\Documents\實驗室\blog\source\_posts\template.md
cd C:\Users\ysh00\Documents\實驗室\blog\source\_posts\
start hexo s
cd %now% && set now=