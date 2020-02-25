#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the fibonacciModified function below.
def fibonacciModified(t1, t2, n):
    l = [0 for i in range(n + 1)]
    l[1] = t1
    l[2] = t2
    for i in range(3, n + 1):
        l[i] = l[i - 2] + l[i - 1] * l[i - 1]
    return l[n]

if __name__ == '__main__':

    t1T2n = input().split()

    t1 = int(t1T2n[0])

    t2 = int(t1T2n[1])

    n = int(t1T2n[2])

    result = fibonacciModified(t1, t2, n)

    print(result)