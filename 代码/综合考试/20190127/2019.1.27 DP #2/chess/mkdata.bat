for /l %%i in (5,1,6) do (
	DATA_chess > chess%%i.in
	chess < chess%%i.in > chess%%i.out
)
