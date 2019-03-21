import os

import sys


def get_min_time(threads, n):
    min_res = 0
    for g in range(10):
        data = os.popen("{} {} {}".format("./cmake-build-release/lab_2", str(threads), str(n))).read()
        current = int(data.strip())
        if min_res:
            if min_res > current:
                min_res = current
        else:
            min_res = int(data.strip())

    print(min_res)



    return 1


if __name__ == '__main__':
    n = sys.argv[2]
    threads = sys.argv[1]
    result = get_min_time(threads, n)
