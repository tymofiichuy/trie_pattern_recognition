#include<fstream>
#include "trie.hpp"

class pattern_recognition{
    private:
        trie suffixes;
    public:
        void read_words(std::ifstream& in_file);    
        void read_line(std::ifstream& in_file);
        void write_trie(std::ofstream& out_file);

        void find_patterns(std::ifstream& patterns, std::ofstream& out_file);
};