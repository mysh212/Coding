copy export-md\*.md C:\Users\ysh00\Documents\實驗室\blog\source\_posts\ /Y
set now=%cd%
del C:\Users\ysh00\Documents\實驗室\blog\source\_posts\template.md
cd C:\Users\ysh00\Documents\實驗室\blog\source\_posts\
hexo g && hexo d && cd %now% && set now=