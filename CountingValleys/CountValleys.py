import math
import os
import random
import re
import sys

#
# Complete the 'countingValleys' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER steps
#  2. STRING path
#

def countingValleys(steps, path):
    downDist = 0
    upDist = 0
    valCount = 0
    travel = 0

    for index, step in enumerate(path):
        
        if step == 'U':
            travel += 1
            upDist += 1
            print("path[%d]: %s, travel: %d" % (index, step, travel))
        elif step =='D':
            downDist += 18
            travel -= 1
            print("path[%d]: %s, travel: %d" % (index, step, travel))
        if travel == 0 and index > 0 and path[index] == 'U' and upDist > 0:
            valCount += 1
            print("path[%d]: %s, travel: %d valley ++" % (index, step, travel))
    return valCount


if __name__ == '__main__':
    

    steps = 8

    path = 'UDDDUDUU'

    result = countingValleys(steps, path)
    print(result)
