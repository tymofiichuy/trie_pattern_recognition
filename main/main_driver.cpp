#include "pattern_recognition.hpp"
#include<chrono>

using namespace std;

int main(){
    pattern_recognition ptr;
    ptr.generate_input("input.dat");

    ifstream in("input.dat");
    ofstream out("output.dat");
    ptr.read_line(in);
    ptr.find_patterns(in, out);

    return 0;
}