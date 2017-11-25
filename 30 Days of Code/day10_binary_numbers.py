import sys
from itertools import groupby
def len_iter(items):
    return sum(1 for _ in items)
def consecutive_ones(data):
    return max(len_iter(run) for val, run in groupby(data) if val)
    
n = int(input())
l = bin(n).lstrip('-0b')
data = [d for d in str(l)]
print(consecutive_ones(data))