#include "pattern_recognition.hpp"
#include<chrono>

using namespace std;

int main(){
    chrono::milliseconds trie_generation(0);
    chrono::steady_clock::time_point start;
    chrono::steady_clock::time_point end;

    pattern_recognition ptr;
    ptr.generate_patterns("input.dat");

    ifstream in("input.dat");
    start = chrono::high_resolution_clock::now();
    ptr.read_words(in);
    ptr.write_trie("output.dat");    
    end = chrono::high_resolution_clock::now();
    cout << "Trie generation time: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << " ms";

    return 0;
}