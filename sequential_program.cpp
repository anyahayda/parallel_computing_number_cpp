#include "sequential_program.h"

void find_solution_interval_sequential(long const range, long n, long *res) {
    int solution = 0;
    for (long x = 1; x <= range; ++x) {
        for (long y = 1; y <= range; ++y) {
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
    *res += solution;
}