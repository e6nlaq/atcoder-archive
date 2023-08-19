<########################################################################



	   Welcome to my program!

	　　∧＿∧        AtCoder / Codeforces
	　 ( 　･ω･)
	＿(__つ/￣￣￣ /  MIT License
	　　＼/　　　　 /  C++ GCC 11.3.0 + Boost 1.82.0
	　　　　￣￣￣￣￣
		   Let's write Code!



########################################################################>

$inp = [System.Console]::ReadLine() -split " "
$L = [int]$inp[0]
$R = [int]$inp[1]

$atc = [String]"atcoder"

Write-Output $atc.Substring($L - 1, $R - $L + 1)
