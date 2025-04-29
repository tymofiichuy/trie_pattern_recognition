#include "trie.hpp"
#include "pattern_recognition.hpp"
#include<chrono>

using namespace std;

int main(){
    pattern_recognition ptr;
    ptr.generate_patterns("input.dat");

    ifstream in("input.dat");
    ptr.read_words(in);
    ptr.write_trie("output.dat");

    return 0;
}