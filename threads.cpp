#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;  // mutex to protect shared resources

int total_primes = 0;  // total number of primes found
vector<int> primes_per_thread(4, 0);  // number of primes found by each thread

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= n / 2; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void find_primes(int thread_id) {
    int num = thread_id + 2;
    while (num <= 2000000) {
        if (is_prime(num)) {
            lock_guard<mutex> lock(mtx);  // lock the mutex
            ofstream out("primes.dat", std::ios::app);
            out << num << "\n";  // write to file
            out.close();
            total_primes++;  // update total count
            primes_per_thread[thread_id]++;  // update count for this thread
        }
        num += 4;  // move to next number that this thread should check
    }
}

int main() {
    ofstream out("primes.dat");
    out.close();  // create an empty file
    vector<thread> threads;
    for (int i = 0; i < 4; i++) {
        threads.emplace_back(find_primes, i);  // create and start threads
    }
    for (auto& thread : threads) {
        thread.join();  // wait for all threads to finish
    }
    cout << "Total primes found: " << total_primes << "\n";
    for (int i = 0; i < 4; i++) {
        cout << "Thread " << i+1 << " found " << primes_per_thread[i] << " primes\n";
    }
    return 0;
}