dir /AD /B>1.tmp
del /F /AH desktop.ini
for /f %%a in (1.tmp) DO (
	cd %%a
	call "C:\Users\user\Coding\.git\clean.cmd"
	cd ..
)
del 1.tmp
goto :eof