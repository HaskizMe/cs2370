#include <iostream>
using namespace std;


void addprint() {
    static int s = 1;
    cout << ++s;
}

int main() {
    addprint();
    addprint();
    addprint();
}