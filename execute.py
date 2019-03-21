import os

import sys


def get_min_time(threads, n):
    min_res = 0
    result = 0

    for g in range(10):
        data = os.popen("{} {} {}".format("./cmake-build-release/lab_2", str(threads), str(n))).read()
        curren_result_time, curren_result = data.split()
        if min_res:
            if min_res > curren_result_time:
                min_res = curren_result_time
        else:

            result = curren_result
            min_res = curren_result_time
        if result != curren_result:

            print("Error")
            exit()


    print("\tNO ERRORS\nNumber of threads: {}\nN: {}\nMin Time: {}\nResult {}".format(threads, n, min_res,result))


if __name__ == '__main__':

    if len(sys.argv) < 3:
        print("""$ python {}                  # Не вказано необхідні аргументи
Usage:  {} th [digits]
Where:  th -- number of threads used
digits -- digits in lucky ticket number (optional)
        """.format(sys.argv[0], sys.argv[0]))
        exit()
    n = int(sys.argv[2])
    threads = int(sys.argv[1])
    get_min_time(threads, n)
