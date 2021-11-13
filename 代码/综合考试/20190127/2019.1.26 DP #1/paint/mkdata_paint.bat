for /l %%i in (1,1,1) do (
	DATA_paint > paint%%i.in
	paint < paint%%i.in > paint%%i.out
)
