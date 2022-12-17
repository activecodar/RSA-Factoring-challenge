#!/usr/bin/python3
import math
import argparse
from typing import List


def get_factors(n: int) -> List:
    factors = []
    for num in range(1, int(math.sqrt(n)) + 1):
        if len(factors) > 1: # we just want the first two results
            break
        if n%num == 0:
            factors.append((num, n // num))
    return factors

def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument('file', help='The file to be read')
    args = parser.parse_args()
    with open(args.file, 'r') as f:
        for line in f:
            factors = get_factors(int(line))
            print(f"{line.strip()}={factors[1]}*{factors[0]}")
    return

if __name__ == "__main__":
    main()

