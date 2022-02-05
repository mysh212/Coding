
setlocal EnableDelayedExpansion
for /f %%a in (1) DO (
	call set b=%%a
	echo !b!
	call set b=!b:.exe=.cpp!
	echo !b!
	move !b! test
)