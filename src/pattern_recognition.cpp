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
    len = static_cast<int>(line.length());

    for(int i = 0; i < len; i++){
        suffixes.insert_word(line.substr(i), i);
    }
}

void pattern_recognition::write_trie(string out_file){
    ofstream out(out_file);
    if(!out.is_open()){
        throw invalid_argument("Unable to open out_file");
    }
    if(out.fail()){
        throw invalid_argument("out_file is corrupted");
    }
    suffixes.print_edges(out);
    out.close();
}

void pattern_recognition::generate_patterns(string out_file){
    ofstream out(out_file);
    if(!out.is_open()){
        throw invalid_argument("Unable to open out_file");
    }
    if(out.fail()){
        throw invalid_argument("out_file is corrupted");
    }

    random_device rd;
    mt19937 mt (rd());
    uniform_int_distribution<int> num_dist (1, 100);
    uniform_int_distribution<int> len_dist (1, 100);
    uniform_int_distribution<int> char_dist (0, 3);

    int number = num_dist(mt);
    out << number << "\n";
    for(int i = 0; i < number; i++){
        int len = len_dist(mt);
        for(int j = 0; j < len; j++){
            int ind = char_dist(mt);
            out << trie_node::get_char_from_index(ind);
        }
        if(i != number-1){
            out << "\n";            
        }
    }
    out.close();
}

void pattern_recognition::generate_input(string out_file){
    ofstream out(out_file);
    if(!out.is_open()){
        throw invalid_argument("Unable to open out_file");
    }
    if(out.fail()){
        throw invalid_argument("out_file is corrupted");
    }

    random_device rd;
    mt19937 mt (rd());
    uniform_int_distribution<int> text_len_dist (1, 10000);
    uniform_int_distribution<int> num_dist (1, 5000);
    uniform_int_distribution<int> len_dist (1, 100);
    uniform_int_distribution<int> char_dist (0, 3);

    int len = text_len_dist(mt);
    for(int i = 0; i < len; i++){
        int ind = char_dist(mt);
        out << trie_node::get_char_from_index(ind);
    }
    out << "\n";

    int number = num_dist(mt);
    out << number << "\n";

    for(int i = 0; i < number; i++){
        len = len_dist(mt);
        for(int j = 0; j < len; j++){
            int ind = char_dist(mt);
            out << trie_node::get_char_from_index(ind);
        }
        if(i != number-1){
            out << "\n";            
        }
    }
    out.close();
}