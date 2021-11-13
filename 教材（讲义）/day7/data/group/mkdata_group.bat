for /l %%i in (7,1,10) do (
	DATA_group > group%%i.in
	group < group%%i.in > group%%i.out
)
