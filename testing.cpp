#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include <algorithm>
using namespace std;
int main() {
    vector<string> my_vector_items_txt;
    my_vector_items_txt.push_back("hello");
    cout << my_vector_items_txt.at(0) << endl;
    cout << "Hello World!";
    return 0;
}