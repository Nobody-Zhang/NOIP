for /l %%i in (4,1,10) do (
	DATA_sum > sum%%i.in
	sum < sum%%i.in > sum%%i.out
)
