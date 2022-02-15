#!/usr/bin/python3
"""
In a text file, there is a single character H. Your text editor can execute
only two operations in this file: Copy All and Paste. Given a number n,
write a method that calculates the fewest number of operations needed to
result in exactly n H characters in the file.
"""


def minOperations(n):
    """
    Function
    """
    div, operator, localN = 2, 0, n

    if n <= 1:
        return 0
    while localN > 1:
        if (localN % div) == 0:
            localN = localN // div
            operator += div
        else:
            div += 1
    return operator
