#include "Vector.h"
#include "test.h"
#include <stdexcept>
using namespace std;


int main() {
//     // Test exceptions
    // Vector v;
    // for(int i = 0; i < 5; i++){
    //     v.push_back(i);
    //     cout << v[i] << ", ";
    // }
//     // v.push_back(2);
//     // v.push_back(3);
//     // v.push_back(4);
//     // v.push_back(5);
//     // v.push_back(6);
//     // v.push_back(7);
//     // v.push_back(8);
//     // v.push_back(8);
//     // v.push_back(8);
//     // v.push_back(1);
//     // v.push_back(5);
//     // v.push_back(52541);
//     // // v.erase(2);
//     // v.insert(0,645);
//     // // v.insert(3,65414);
//     // for(int i = 0; i < v.size(); i++){
//     //     cout << v[i] << ", ";
//     // }
//     // v.print();
//     // cout << v.size() << endl;

//     // // cout << v.front() << endl;
//     // // int *a = v.front()
//     // cout << v.size() << endl;
//     // // cout << v.printad() << endl;
//     //     // auto iter1 = v.end();

//     // // v.print();
//     // // v.clear();
//     // // v.print();
//     // // cout << v.size() << endl;
//     // cout << v.at(20) << endl;

//     // auto iter = v.end();
//     // cout << v.size() << endl;



//     // // cout << *iter << endl;
//     // cout << *iter1 << endl;
//     // cout << v.size() << endl;

//     // cout<< v.at(0) << endl;
//     // // cout<< v.[0] << endl;
//     // cout<< v.back() << endl;
//     // cout << v.empty() << endl;

//     // v.push_back(1);
//     // cout << v.erase(0) << endl;
//     // cout << v.size() << endl;
//     throw_(v.at(0), range_error);
//     throw_(v.pop_back(), range_error);
//     throw_(v.erase(0), range_error);
//     throw_(v.front(), range_error);
//     throw_(v.back(), range_error);

//     // // Test adding an element
//     v.push_back(1);
//     test_(v.size() == 1);
//     test_(v.at(0) == 1);
//     test_(v[0] == 1);
//     test_(v.front() == 1);
//     test_(v.back() == 1);
//     test_(!v.empty());

//     // // // Add another
//     // v.push_back(2);
//     // test_(v.size() == 2);
//     // test_(v.at(0) == 1);
//     // test_(v.at(1) == 2);
//     // test_(v[0] == 1);
//     // test_(v[1] == 2);
//     // test_(v.front() == 1);
//     // test_(v.back() == 2);
//     // test_(!v.empty());

//     // // cout << v[0] << endl;
//     // // // Test iterators
//     // // auto iter = v.begin();
//     // // test_(*iter == 1);
//     // // ++iter;
//     // // test_(*iter == 2);
//     // // ++iter;
//     // // test_(iter == v.end());

//     // // // Test copy and == 
//     // Vector v2 = v;
//     // // v2.print();
    
//     // // cout << v2.size() << endl;
//     // test_(v2.size() == 2);
//     // test_(v2.at(0) == 1);
//     // test_(v2.at(1) == 2);
//     // test_(v2[0] == 1);
//     // test_(v2[1] == 2);
//     // test_(v2.front() == 1);
//     // test_(v2.back() == 2);
//     // test_(!v2.empty());
//     // test_(v == v2);

//     // // iter = v2.begin();
//     // // test_(*iter == 1);
//     // // ++iter;
//     // // test_(*iter == 2);
//     // // ++iter;
//     // // test_(iter == v2.end());

//     // // // Test assignment
//     Vector v3;
//     v3 = v;
//     // test_(v3.size() == 2);
//     // test_(v3.at(0) == 1);
//     // test_(v3.at(1) == 2);
//     // test_(v3[0] == 1);
//     // test_(v3[1] == 2);
//     // test_(v3.front() == 1);
//     // test_(v3.back() == 2);
//     // test_(!v3.empty());

//     // // iter = v3.begin();
//     // // test_(*iter == 1);
//     // // ++iter;
//     // // test_(*iter == 2);
//     // // ++iter;
//     // // test_(iter == v3.end());

//     // // // Test assignment
//     // v[1] = -2;
//     // test_(v.back() == -2);
//     // test_(v.at(1) == -2);
//     // test_(v[1] == -2);

//     // // // Test pop_back
//     // v.pop_back();
//     // test_(v.size() == 1);
//     // test_(v.front() == 1);
//     // test_(v.back() == 1);
//     // test_(v.at(0) == 1);
//     // test_(v[0] == 1);

//     // // // Test clear and !=
//     // // v.clear();
//     // // test_(v.size() == 0);
//     // // test_(v.empty());
//     // // cout << v.size() << endl;
//     // // throw_(v.at(0), range_error);
//     // // throw_(v.pop_back(), range_error);
//     // // throw_(v.erase(0), range_error);
//     // // throw_(v.front(), range_error);
//     // // throw_(v.back(), range_error);
//     // // test_(v != v2);

//     // // // Test erase
//     // v3.erase(0);
//     // test_(v3.size() == 1);
//     // test_(v3.at(0) == 2);
//     // test_(v3[0] == 2);
//     // test_(v3.front() == 2);
//     // test_(v3.back() == 2);

//     // // // Test insert
//     // v3.print();

//     v3.insert(0,1);
//     // v3.print();
//     for(int i = 0; i < v3.size(); i++){
//         cout << v3[i] << ", ";
//     }
//     test_(v3.size() == 2);
//     test_(v3.at(0) == 1);
//     test_(v3[0] == 1);
//     test_(v3[1] == 2);
//     test_(v3.front() == 1);
//     test_(v3.back() == 2);

//     // // Test grow
    Vector v4;
    for (int i = 1; i <= 10; ++i)
        v4.push_back(i);
    test_(v4.size() == 10);
    test_(v4.front() == 1);
    test_(v4.back() == 10);
    v4.insert(10,11);
    test_(v4.size() == 11);
    test_(v4.front() == 1);
    test_(v4.back() == 11);


    report_();
}













// #include "Vector.h"
// #include "test.h"
// #include <stdexcept>
// using namespace std;

// int main() {
//     // Test exceptions
//     Vector v;
//     // throw_(v.at(0), range_error);
//     // throw_(v.pop_back(), range_error);
//     // throw_(v.erase(0), range_error);
//     // throw_(v.front(), range_error);
//     // throw_(v.back(), range_error);

//     // Test adding an element
//     v.push_back(1);
//     test_(v.size() == 1);
//     test_(v.at(0) == 1);
//     test_(v[0] == 1);
//     test_(v.front() == 1);
//     test_(v.back() == 1);
//     test_(!v.empty());

//     // Add another
//     v.push_back(2);
//     test_(v.size() == 2);
//     test_(v.at(0) == 1);
//     test_(v.at(1) == 2);
//     test_(v[0] == 1);
//     test_(v[1] == 2);
//     test_(v.front() == 1);
//     test_(v.back() == 2);
//     test_(!v.empty());

//     // Test iterators
//     // auto iter = v.begin();
//     // test_(*iter == 1);
//     // ++iter;
//     // test_(*iter == 2);
//     // ++iter;
//     // test_(iter == v.end());

//     // Test copy and ==
//     Vector v2 = v;
//     test_(v2.size() == 2);
//     test_(v2.at(0) == 1);
//     test_(v2.at(1) == 2);
//     test_(v2[0] == 1);
//     test_(v2[1] == 2);
//     test_(v2.front() == 1);
//     test_(v2.back() == 2);
//     test_(!v2.empty());
//     test_(v == v2);

//     // iter = v2.begin();
//     // test_(*iter == 1);
//     // ++iter;
//     // test_(*iter == 2);
//     // ++iter;
//     // test_(iter == v2.end());

//     // Test assignment
//     Vector v3;
//     v3 = v;
//     test_(v3.size() == 2);
//     test_(v3.at(0) == 1);
//     test_(v3.at(1) == 2);
//     test_(v3[0] == 1);
//     test_(v3[1] == 2);
//     test_(v3.front() == 1);
//     test_(v3.back() == 2);
//     test_(!v3.empty());

//     // iter = v3.begin();
//     // test_(*iter == 1);
//     // ++iter;
//     // test_(*iter == 2);
//     // ++iter;
//     // test_(iter == v3.end());

//     // Test assignment
//     v[1] = -2;
//     test_(v.back() == -2);
//     test_(v.at(1) == -2);
//     test_(v[1] == -2);

//     // Test pop_back
//     v.pop_back();
//     test_(v.size() == 1);
//     test_(v.front() == 1);
//     test_(v.back() == 1);
//     test_(v.at(0) == 1);
//     test_(v[0] == 1);

//     // Test clear and !=
//     v.clear();
//     test_(v.size() == 0);
//     test_(v.empty());
//     // throw_(v.at(0), range_error);
//     // throw_(v.pop_back(), range_error);
//     // throw_(v.erase(0), range_error);
//     // throw_(v.front(), range_error);
//     // throw_(v.back(), range_error);
//     test_(v != v2);

//     // Test erase
//     v3.erase(0);
//     test_(v3.size() == 1);
//     test_(v3.at(0) == 2);
//     test_(v3[0] == 2);
//     test_(v3.front() == 2);
//     test_(v3.back() == 2);

//     // Test insert
//     v3.insert(0,1);
//     test_(v3.size() == 2);
//     test_(v3.at(0) == 1);
//     test_(v3[0] == 1);
//     test_(v3[1] == 2);
//     test_(v3.front() == 1);
//     test_(v3.back() == 2);
//     for(int i = 1; i <= 15; i++){
//         v3.push_back(i);
//         cout << v3[i] << ", ";
//     }

//     // Test grow
//     Vector v4;
//     // for(int i = 1; i <= 10; i++){
//     //     v4.push_back(i);
//     //     cout << v4[i] << ", ";
//     // }

//     // cout << v3.size() << endl;
//     // test_(v4.size() == 10);
//     // test_(v4.front() == 1);
//     // test_(v4.back() == 10);
//     // v4.insert(10,11);
//     // test_(v4.size() == 11);
//     // test_(v4.front() == 1);
//     // test_(v4.back() == 11);


//     report_();
// }