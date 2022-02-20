#!/usr/bin/python3
"""
0x09 UTF-8 Validation
"""


def validUTF8(data):
    """
    check valid UTF-8
    """

    c = 0
    for n in data:
        m = 1 << 7
        if not c:
            while n & m:
                c = c + 1
                m >>= 1
            if c > 4:
                return False
        elif n >> 6 != 2:
            return False
        if c:
            c = c - 1
    return c == 0
