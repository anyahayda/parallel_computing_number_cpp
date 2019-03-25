#include "paralel_program.h"


std::mutex counter;

void find_solution_interval(long const from, long const to, long const n, long *res) {
    int solution = 0;
    for (long x = from + 1; x <= to; ++x) {
        for (long y = 1; y <= n * n * 2; ++y) {
            if (((x * y) / (x + y)) > n) {
                break;
            }
            if ((x * y) % (x + y) == 0) {
                if ((x * y) / (x + y) == n) {
                    solution++;
                }
            }
        }


    }

    counter.lock();
    *res += solution;
    counter.unlock();
}
