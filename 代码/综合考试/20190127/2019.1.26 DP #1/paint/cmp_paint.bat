@echo off
for /l %%i in (1,1,10000000) do (
	DATA_paint > paint.in
	BAOLI_paint < paint.in > BAOLI_paint.out
	paint < paint.in > paint.out
	fc BAOLI_paint.out paint.out
	if errorlevel 1 (
		echo WAAAAAAAAAAA
		pause
	)
	echo #%%i
	echo.
	echo Accepted !!!
)
