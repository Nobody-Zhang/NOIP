for /l %%i in (1,1,2) do (
	DATA_match > match%%i.in
	match < match%%i.in > match%%i.out
)
