for /l %%i in (5,1,10) do (
	DATA_plant > plant%%i.in
	plant < plant%%i.in > plant%%i.out
)
