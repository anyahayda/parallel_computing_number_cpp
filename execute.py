import os

import sys


def get_min_time(threads, file, n=500, computations=10):
    min_res = 0
    result = 0

    for _ in range(computations):
        data = os.popen("{} {} {}".format(file, str(threads), str(n))).read()
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

    print("\tNO ERRORS\nNumber of threads: {}\nN: {}\nMin Time: {}\nResult {}".format(threads, n, min_res, result))


if __name__ == '__main__':

    if len(sys.argv) < 3:
        print("""$ python {}                  # Не вказано необхідні аргументи
Usage:  {} th file n computations 
Where:  th -- number of threads used
        file -- path to the execution file
        n -- n in the equation 1/x+1/y=1/n (optional 500 default)
        computations -- number of computations to find the min value (optional 10 default)
        example:\n
        python3 {} 4 ./<build_path>/lab_2 500 10
        """.format(sys.argv[0], sys.argv[0], sys.argv[0]))
        exit()
    threads = int(sys.argv[1])
    n = 500
    computations = 10
    if (len(sys.argv) > 3):
        n = int(sys.argv[3])

    file = sys.argv[2]
    if (len(sys.argv) > 3):
        computations = int(sys.argv[4])

    get_min_time(threads, file, n, computations)
