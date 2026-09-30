def solve_case(_):
    # The argument is unused; map() just needs something to pass so that
    # this runs once per test case, in order, reading its own input lines.
    x = int(input())
    ys = list(map(int, input().split()))
    # If the count doesn't match X, the answer is -1. The whole line has
    # already been read, so the next test case stays aligned.
    if len(ys) != x:
        return -1
    # Sum y^4 for non-positive values only.
    return sum(map(lambda y: y ** 4, filter(lambda y: y <= 0, ys)))


def main():
    n = int(input())
    results = list(map(solve_case, range(n)))
    # Print only after all input is consumed, as required.
    print("\n".join(map(str, results)))


if __name__ == "__main__":
    main()