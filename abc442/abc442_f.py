import sys
from itertools import accumulate
from operator import add

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    N = int(input_data[0])
    S = input_data[1:]
    
    dp = [0] * (N + 1)
    
    for row in S:
        dp = list(accumulate(reversed(dp), min))[::-1]
        
        base_cost = row.count('.')
        diffs = (1 if char == '#' else -1 for char in row)
        row_costs = accumulate(diffs, initial=base_cost)
        
        dp = list(map(add, dp, row_costs))
        
    print(min(dp))

if __name__ == "__main__":
    solve()