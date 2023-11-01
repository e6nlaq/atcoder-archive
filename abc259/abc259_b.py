# ------------------------------------------------------------
#
#
# 	   Welcome to my program!
# 	   DON'T HACK PLEASE!!!!!!!!
#
# 	　　∧＿∧        AtCoder / Codeforces
# 	　 ( 　･ω･)
# 	＿(__つ/￣￣￣ /  MIT License
# 	　　＼/　　　　 /  Python 3.10.12
# 	　　　　￣￣￣￣￣
# 		   Let's write Code!
#
#
# ------------------------------------------------------------

import numpy as np
import collections
import math


def rotate(a, b, d):
    """
    点 (a,b) を原点を中心として反時計回りに d 度回転させた点を求める

    Args:
      a: 点の x 座標
      b: 点の y 座標
      d: 回転角度 (度)

    Returns:
      回転後の点の座標 (x, y)
    """

    # 回転行列
    c = math.cos(math.radians(d))
    s = math.sin(math.radians(d))

    # 回転後の点の座標
    x = a * c - b * s
    y = a * s + b * c

    return x, y


if __name__ == "__main__":
    a, b, d = map(int, input().split())
    # 回転後の点の座標
    x, y = rotate(a, b, d)

    # 出力
    print(x, y)
