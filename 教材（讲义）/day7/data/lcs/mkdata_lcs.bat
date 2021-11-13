for /l %%i in (4,1,10) do (
	DATA_lcs > lcs%%i.in
	lcs < lcs%%i.in > lcs%%i.out
)
