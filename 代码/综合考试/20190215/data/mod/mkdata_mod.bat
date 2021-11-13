for /l %%i in (1,1,3) do (
	DATA_mod > mod%%i.in
	mod < mod%%i.in > mod%%i.out
)
