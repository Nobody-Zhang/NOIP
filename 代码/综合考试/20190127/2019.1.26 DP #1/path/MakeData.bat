for /l %%i in (6,1,10) do (
	DATA_path > path%%i.in
	path.exe < path%%i.in > path%%i.out
)
