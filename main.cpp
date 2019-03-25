// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "sequential_program.h"
#include "paralel_program.h"




inline std::chrono::high_resolution_clock::time_point get_current_time_fenced() {
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}

template<class D>
inline long long to_us(const D &d) {
    return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
}


int main(int argc, char *argv[]) {
    using std::cout;
    using std::endl;
    using std::thread;
    using std::vector;
    using std::mutex;
    vector<std::thread> vecOfThreads;


    long result = 0;
    // default config
    long threads = 1;
    long n = 100;

    if (argc >= 2) {

        threads = strtol(argv[1], nullptr, 10);
    }

    if (argc == 3) {

        n = strtol(argv[2], nullptr, 10);
    }

    auto stage1_start_time = get_current_time_fenced();
    //creating threads
    long range = n * n * 2;

    if (threads > 1) {
        for (int i = 0; i < threads; ++i) {
            vecOfThreads.emplace_back(&find_solution_interval, ((range * i) / threads),
                                      (((range * (i + 1)) / threads)), n,
                                      &result);
        }
        for (auto &vecOfThread : vecOfThreads) {
            vecOfThread.join();
        }
    } else {
        find_solution_interval_sequential(range, n, &result);
    }
    auto finish_time = get_current_time_fenced();
    auto total_time = finish_time - stage1_start_time;
    std::ofstream out_file("result.txt", std::ofstream::app);
    out_file << "N: " << n << "\tRES: " << result << "\tTIME: " << to_us(total_time) << "\tTHREADS: " << threads
             << endl;

    //    output time and result for python script
    cout << to_us(total_time) << "\t" << result << endl;
    return 0;
}

