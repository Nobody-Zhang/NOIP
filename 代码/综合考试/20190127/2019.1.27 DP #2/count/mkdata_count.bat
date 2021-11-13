for /l %%i in (1,1,2) do (
	DATA_count > count%%i.in
	count < count%%i.in > count%%i.out
)
