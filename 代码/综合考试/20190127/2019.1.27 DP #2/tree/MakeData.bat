for /l %%i in (6,1,10) do (
	DATA_tree > tree%%i.in
	tree.exe < tree%%i.in > tree%%i.out
)
