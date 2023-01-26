// CPP program to find if a sentence is
// palindrome
#include <bits/stdc++.h>
using namespace std;
  
// To check sentence is palindrome or not
bool isPalindrome(string str)
{
    // Transforming to lowercase
    transform(str.begin(), str.end(), str.begin(), ::tolower);
     
    // Removing the white-spaces
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    // Creating the copy to string
    string s1 = str;
    string s2 = str;
    // Reversing the string s1
    reverse(s1.begin(), s1.end());
     
    // Evaluating Result
    return s1 == s2;
}
  
// Driver program to test sentencePalindrome()
int main()
{
    // string str = "Too hot to hoot";
    string str;
    getline (cin,str);
    if (isPalindrome(str))
        cout << "palindrome: " << str << endl;
    else
        cout << "not a palindrome: " << str << endl;
  
    return 0;
}