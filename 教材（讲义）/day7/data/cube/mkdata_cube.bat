for /l %%i in (4,1,10) do (
	DATA_cube > cube%%i.in
	cube < cube%%i.in > cube%%i.out
)
