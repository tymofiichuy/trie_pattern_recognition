#pragma once

#include "trie.hpp"
#include<random>

class pattern_recognition{
    private:
        trie suffixes;
    public:
        void generate_patterns(std::string out_file);
        void generate_input(std::string out_file);

        void read_words(std::ifstream& in_file);    
        void read_line(std::ifstream& in_file);
        void write_trie(std::string out_file);
        //maybe later
        //void write_trie_structure(std::string out_file);

        void find_patterns(std::ifstream& patterns, std::ofstream& out_file);
};