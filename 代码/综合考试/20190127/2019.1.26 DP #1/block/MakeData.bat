for /l %%i in (2,1,2) do (
	DATA_block > block%%i.in
	block < block%%i.in > block%%i.out
)
