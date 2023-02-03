#include <iostream>
#include <vector> 
#include <string>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;

 int GetWordFrequency(vector<string> wordsList, string& currWord){
    int count=0;
    //outer loop will loop through number of elements in the list
    for(int i;i<wordsList.size(); i++){

        //Inner loop will output the number of frequency of words
        for(int j = 1; j < wordsList.size(); j++){
            //comparing two strings
            if(wordsList[i] == wordsList[j]){
                count++;
            }
            return count;
        }


    }
    return 0;
 }

int main() {

    vector<string> input_words;
    string input;

    getline(cin,input);
    // cin >> input;
    // input_words.push_back(input);

    istringstream ss(input);
    string word;

    //Seperating words by spaces
    while (ss >> word)
    {
        input_words.push_back(word);
    }
    //changing all letters to lower case
    for(int i = 0; i<input_words.size();i++){
        transform(input_words[i].begin(), input_words[i].end(), input_words[i].begin(), ::tolower);
    }
    //printing all elements in vector
    for(auto x : input_words){
        cout<< x<< endl;
    }
// string s2 = input_words[0];
//    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
//    cout<<s2<<endl;
    string currWord = input_words[0];
    GetWordFrequency(input_words,currWord);

   return 0;
}