for /l %%i in (1,1,2) do (
	DATA_sheep > sheep%%i.in
	sheep < sheep%%i.in > sheep%%i.out
)
