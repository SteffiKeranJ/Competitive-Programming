"""
Task:
Given a base-10 integer, n, convert it to binary (base-2). 
Then find and print the base-10 integer denoting the maximum number of consecutive 1's in n's binary representation.

Input Format:
A single integer, n. 

Output Format:
Print a single base-10 integer denoting the maximum number of consecutive 1's in the binary representation of n.

SAMPLE
Input: 5
Output: 1

Problem link: https://www.hackerrank.com/challenges/30-binary-numbers/problem
"""
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