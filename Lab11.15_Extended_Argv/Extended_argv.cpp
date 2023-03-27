#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;


string delete_sign(string word){
    word.erase(word.begin());
    return word;
}


int main(int argc, char* argv[]){
    string word;
    string file_name;
    vector<string> words;
    vector<string> first_words;
    vector<string> second_words;

    ifstream file("./argfile.dat");
    // cout << "arg value index " << argv[2] << endl;
    while(file >> word){
        words.push_back(word);
    }
    file.close();

    //Looking through each word to see if there is a '@' sign
    int index = 0;
    for(int i = 0; i < words.size(); i++){
        for(int j = 0; j < words.at(i).size(); j++){
            if(words.at(i)[j] == '@'){
            // words.erase(words.begin());
            file_name = delete_sign(words.at(i));
            // cout << "found word: " << file_name << endl;
            index = i;
            }
        }

    }
    // cout << "index " << index << endl;

    // Splitting words vector
    // Adding words up until the file name to new vector called first words.
    for(int i = 0; i < index; i++){
        first_words.push_back(words.at(i));
    }

    // Adding words after file name to second words list
    for(int i = index+1; i < words.size(); i++){
        second_words.push_back(words.at(i));
    }

    // printing first words vector
    // for(int i = 0; i < first_words.size(); i++){
    //     cout << first_words.at(i) << endl;
    // }
    
    file_name = "./"+file_name;
    // cout << file_name << endl;
    ifstream file2(file_name);
    words.clear();
    while(file2 >> word){
        words.push_back(word);
    }
    file2.close();
    for(int i = 0; i < words.size(); i++){
        for(int j = 0; j < words.at(i).size(); j++){
            if(words.at(i)[j] == '@'){
            // words.erase(words.begin());
            file_name = delete_sign(words.at(i));
            // cout << "found word: " << file_name << endl;
            index = i;
            }
        }

    }
     for(int i = 0; i < index; i++){
        first_words.push_back(words.at(i));
    }

    // Adding words after file name to second words list
    for(int i = index+1; i < words.size(); i++){
        second_words.push_back(words.at(i));
    }

    // printing first words vector
    // for(int i = 0; i < first_words.size(); i++){
    //     cout << first_words.at(i) << endl;
    // }




    file_name = "./"+file_name;
    // cout << file_name << endl;
    ifstream file3(file_name);
    words.clear();
    while(file3 >> word){
        words.push_back(word);
    }

    file3.close();
    // cout << "words first index " <<words.at(0) << endl;
    // for(int i = 0; i < words.size(); i++){
    //     for(int j = 0; j < words.at(i).size(); j++){
    //         if(words.at(i)[j] == '@'){
    //         // words.erase(words.begin());
    //         file_name = delete_sign(words.at(i));
    //         // cout << "found word: " << file_name << endl;
    //         index = i;
    //         }
    //     }

    // }
    //  for(int i = 0; i < index; i++){
    //     first_words.push_back(words.at(i));
    // }

    // // Adding words after file name to second words list
    // for(int i = index+1; i < words.size(); i++){
    //     second_words.push_back(words.at(i));
    // }


    // Adding words up until the file name to new vector called first words.
    for(int i = 0; i < words.size(); i++){
        first_words.push_back(words.at(i));
    }


    // printing first words vector
    string arg1 = argv[1];
    string arg3 = argv[2];
    first_words.insert(first_words.begin(),arg1);
    vector<string> temp;
    for(int i = 0; i < 3; i++){
        temp.push_back(second_words.at(i));
    }
    second_words.erase(second_words.begin(),second_words.begin()+3);;

    for(int i = 0; i < temp.size(); i++){
        second_words.push_back(temp.at(i));
    }
    second_words.push_back(arg3);
    cout << first_words.size() + second_words.size() << " items:\n" << endl;

    // first_words.insert(first_words.end(),"hi");

    // second_words.insert(second_words.end(), argv[3]);
    for(int i = 0; i < first_words.size(); i++){
        cout << first_words.at(i) << endl;
    }



    // vector<string> temp;
    // for(int i = 0; i < 3; i++){
    //     temp.push_back(second_words.at(i));
    // }
    // second_words.erase(second_words.begin(),second_words.begin()+3);;

    // for(int i = 0; i < temp.size(); i++){
    //     second_words.push_back(temp.at(i));
    // }

    for(int i = 0; i < second_words.size(); i++){
        cout << second_words.at(i) << endl;
    }
    // printing total words list
    // for(int i = 0; i < words.size(); i++){
    //     cout << words.at(i) << endl;
    // }
    
}