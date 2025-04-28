#include "pattern_recognition.hpp"

using namespace std;

void pattern_recognition::read_words(ifstream& in_file){
    string word;
    int size, iter = 0;

    getline(in_file, word);
    size = stoi(word);

    while(getline(in_file, word) && iter<size){
        suffixes.insert_word(word, iter);
        iter++;
    }
}

void pattern_recognition::read_line(ifstream& in_file){
    string line, word;
    int len;

    getline(in_file, line);
    len = line.length();

    for(int i = 0; i < len; i++){
        suffixes.insert_word(line.substr(i), i);
    }
}