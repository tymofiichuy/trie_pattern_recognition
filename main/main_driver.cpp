#include "pattern_recognition.hpp"
#include<chrono>

using namespace std;

int main(int argc, char *argv[]){
    if(argc > 2){
        cerr << "Unsupported signature";
        return 1;
    }

    pattern_recognition ptr;
    if(argc == 2){
        if(strcmp(argv[1], "--gen") == 0){
            ptr.generate_input("input.dat");
        }
        else{
            cerr << "Unsupported parameter";
            return 1;
        }
    }

    chrono::milliseconds trie_generation(0);
    chrono::milliseconds recognition(0);
    chrono::steady_clock::time_point start;
    chrono::steady_clock::time_point end;

    ifstream in("input.dat");
    ofstream out("output.dat");

    start = chrono::high_resolution_clock::now();
    ptr.read_line(in);
    end = chrono::high_resolution_clock::now();
    cout << "Trie generation time: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << " ms\n";

    start = chrono::high_resolution_clock::now();
    ptr.find_patterns(in, out);
    end = chrono::high_resolution_clock::now();
    cout << "Pattern recognition time: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << " ms";

    return 0;
}