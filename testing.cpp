#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
    //GetNumOfNonWSCharacters method
    int GetNumOfNonWSCharacters(const string str){
        unsigned int i = str.size();
        int count = 0;
        int total = 0;
        for(unsigned int j = 0; j < i; j++){
            if(str[j] == ' '){
                count++;
            }
            
        }
        total = i - count;
        return total;

    }
    //end of GetNumOfNonWSCharacters method

    //Start of GetNumofWords()
    int GetNumOfWords(const string str){    
    int Num = 0;      
    char prev = ' ';
    for(unsigned int i = 0; i < str.size(); i++) {

        if(str[i] != ' ' && prev == ' ') 
        Num++;

        prev = str[i];
    }
    return Num;
    }
    //End of GetNumOfWords()

    // Beginning of FindText()
    int FindText(string WordToFind, string str){
    int count = 0;
    for (unsigned int i = 0; i <str.size()-1; i++){
        unsigned int m = 0;
        int n = i;
        for (unsigned int j = 0; j < WordToFind.size(); j++)
        {
            if (str[n] == WordToFind[j])
            {
                m++;
            }
            n++;
        }
        if (m == WordToFind.size())
        {
            count++;
        }
    
    }
        return count;
    }
    // End of FindText()

    void ReplaceExclamation(string& str){
        replace(str.begin(), str.end(), '!', '.');
    }

    void ShortenSpace(string& str){
    
    int n = str.length();
    int i = 0;
    int j = -1;
    bool spaceFound = false;
    
    while (++j < n && str[j] == ' ');
 
    // read all characters of original string
    while (j < n)
    {
        // if current characters is non-space
        if (str[j] != ' ')
        {
            // remove preceding spaces before dot,
            // comma & question mark
            if ((str[j] == '.' || str[j] == ',' || str[j] == '?') && i - 1 >= 0 && str[i - 1] == ' ')
                str[i - 1] = str[j++];
 
            else
                // copy current character at index i
                // and increment both i and j
                str[i++] = str[j++];
 
            // set space flag to false when any
            // non-space character is found
            spaceFound = false;
        }
        // if current character is a space
        else if (str[j++] == ' ')
        {
            // If space is encountered for the first
            // time after a word, put one space in the
            // output and set space flag to true
            if (!spaceFound)
            {
                str[i++] = ' ';
                spaceFound = true;
            }
        }
    }
 
    // Remove trailing spaces
    if (i <= 1)
        str.erase(str.begin() + i, str.end());
    else
        str.erase(str.begin() + i - 1, str.end());
}
 
    void PrintMenu(){
        cout << "" << endl;
        cout << "MENU" << endl;
        cout << "c - Number of non-whitespace characters\nw - Number of words\nf - Find text\nr - Replace all !'s\ns - Shorten spaces\nq - Quit\n" << endl;
        cout << "Choose an option:" << endl;

    }
    void ExecuteMenu(char input, string text){
        string i = "";
        do{
        cin >> input;
        PrintMenu();
    switch (input)
        {
        case 'c':
        //working
        cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(text) << endl;
            break;
        case 'w':
        cout << "Number of words: " << GetNumOfWords(text) << endl;
            break;
        case 'f':
        cout << "Enter a word or phrase to be found:" << endl;
        cin.ignore();
        getline (cin,i);
        cout << "\"" << i << "\"" << " instances: "<< FindText(i, text) << endl;
            break;
        case 'r':
        ReplaceExclamation(text);
        cout << "" << endl;
        cout << "Edited text: " << text << endl;
            break;
        case 's':
        ShortenSpace(text);
        cout << "" << endl;
        cout << "Edited text: " << text << endl;
            break;
        case 'q':
            break;

        default:
            cout << "Please enter a valid letter" << endl;
            break;
        }
        } 
        while(input != 'q');

    }
    // PrintMenu Method
    // void PrintMenu(){
    // // string str = "";
    // // char c;
    // // cout << "Enter a sample text:" << endl;
    // // cout << "" << endl;
    // // getline (cin,str);
    // // cout << "You entered: " << str << endl;
    // // do{
    //     cout << "" << endl;
    //     cout << "MENU" << endl;
    //     cout << "c - Number of non-whitespace characters\nw - Number of words\nf - Find text\nr - Replace all !'s\ns - Shorten spaces\nq - Quit\n" << endl;
    //     cout << "Choose an option:" << endl;
    //     // cin >> c;
    //     // ExecuteMenu(c,str);
    // // }
    // // while(c!='q');
    // }

int main() {
    string str = "";
    char c;
    cout << "Enter a sample text:" << endl;
    cout << "" << endl;
    getline(cin,str);
    cout << "You entered: " << str << endl;
    PrintMenu();
    cin >> c;
    ExecuteMenu(c, str);
    return 0;
}