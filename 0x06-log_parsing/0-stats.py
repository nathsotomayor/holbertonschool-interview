#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.
"""

import sys


def parser(log, counter, file_size, status):
    try:
        if log[-1].isdigit():
            file_size[0] += int(log[-1])
        if log[-2].isdigit():
            status[int(log[-2])] += 1
        if counter[0] == 9:
            _print(file_size, status)
            counter[0] = 0
        else:
            counter[0] += 1
    except Exception:
        pass


def _print(file_size, status):
    print("File size: {}".format(file_size[0]))
    for stat in sorted(status.keys()):
        if status[stat] != 0:
            print("{}: {}".format(stat, status[stat]))


if __name__ == "__main__":
    file_size = [0]
    counter = [0]
    status = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

    while True:
        try:
            log = input().split()
            parser(log, counter, file_size, status)
        except (KeyboardInterrupt, EOFError):
            _print(file_size, status)
            exit()