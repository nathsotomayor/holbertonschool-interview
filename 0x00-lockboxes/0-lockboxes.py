#!/usr/bin/python3
"""
Module of canUnlockAll
"""


def canUnlockAll(boxes):
    """ Determine if the boxes can unlock
    """
    if (type(boxes) is not list):
        return False

    if (len(boxes) == 0):
        return False

    keys = [0]
    for i in keys:
        for j in boxes[i]:
            if j not in keys and j != i and j < len(boxes) and j != 0:
                keys.append(j)
    if len(keys) == len(boxes):
        return True
    return False
