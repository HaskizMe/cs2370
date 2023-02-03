#include <iostream>
#include <vector> 
#include <string>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;

 int GetWordFrequency(vector<string> wordsList, string currWord){
    int count = 0;

    transform(currWord.begin(), currWord.end(), currWord.begin(), ::tolower);
    for(int i = 0; i<wordsList.size();i++){
        transform(wordsList[i].begin(), wordsList[i].end(), wordsList[i].begin(), ::tolower);
        }
        for(unsigned int j = 0; j < wordsList.size(); j++){
            if(currWord == wordsList[j]){
                count++;
            }
        }

    return count;
    }

int main() {

    vector<string> input_words;

    string input;
    int number_of_words;

    cin >> number_of_words;

    getline(cin,input);

    istringstream ss(input);
    string word;

    //Seperating words by spaces
    while (ss >> word)
    {
        input_words.push_back(word);
        
    }

    for(int k = 0; k < number_of_words; k++)
    {
        string currWord = input_words[k];
        cout << currWord << " " << GetWordFrequency(input_words,currWord) << endl;
        // cout<< GetWordFrequency(input_words, currWord) << endl;
    }

   return 0;
}