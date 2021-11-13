echo off
for /l %%i in (1,1,10000000) do (
	DATA_sum > sum.in
	BAOLI_sum < sum.in > BAOLI_sum.out
	sum < sum.in > sum.out
	fc BAOLI_sum.out sum.out
	if errorlevel 1 (
		echo WAAAAAAAAAAA
		pause
	)
	echo #%%i
	echo.
	echo Accepted !!!
)
