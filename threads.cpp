#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>

std::mutex mtx;  // mutex to protect shared resources

int total_primes = 0;
std::vector<int> primes_found(4, 0);

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void find_primes(int thread_num, int start_num, int end_num) {
    for (int i = start_num; i <= end_num; i++) {
        if (is_prime(i)) {
            std::lock_guard<std::mutex> lock(mtx);
            std::ofstream outfile("primes.dat", std::ios_base::app);
            outfile << i << std::endl;
            total_primes++;
            primes_found[thread_num]++;
        }
    }
}

int main() {
    std::vector<std::thread> threads;
    int start_num = 2;
    int end_num = 1000000;
    int subrange_size = (end_num - start_num + 1) / 4;
    for (int i = 0; i < 4; i++) {
        int subrange_start = start_num + i * subrange_size;
        int subrange_end = (i == 3) ? end_num : subrange_start + subrange_size - 1;
        threads.emplace_back(find_primes, i, subrange_start, subrange_end);
    }
    for (auto& t : threads) {
        t.join();
    }
    std::cout << "Total primes found: " << total_primes << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "Thread " << i+1 << " found " << primes_found[i] << " primes." << std::endl;
    }
    return 0;
}