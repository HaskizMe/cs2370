#include <bitset>
#include <iostream>
#include <cmath>
using namespace std;

int convert(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}
int main() {
    cout << "Enter the integer that holds the bits: ";
    unsigned int n;
    cin >> n;

    cout << "Enter the rightmost bit position: ";
    unsigned int k;
    cin >> k;

    cout << "Enter the leftmost bit position: ";
    unsigned int m;
    cin >> m;
    bitset<32> b(n);
    bitset<32> b1(n>>k);



    string str = b1.to_string<char,string::traits_type,std::string::allocator_type>();
    
    //this is the correct substring
    str = str.substr(str.size() - (m-1));

    bitset<32> b2 (convert(stoi(str)));
    cout << "Extracting bits " << k << " through " << m << " from " << n << " = " << b << ":\n"
    << "Result = " << convert(stoi(str)) << " = " << b2 << endl;
}