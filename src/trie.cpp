#include "trie.hpp"

using namespace std;

trie_node::trie_node(char ch, bool term):terminator(term),value(ch){
    edges = new trie_node*[alphabet_size]();
}

trie_node::trie_node(const trie_node& in):terminator(in.terminator), value(in.value), alphabet_size(in.alphabet_size){
    edges = new trie_node*[alphabet_size];
    for(int i = 0; i < alphabet_size; i++){
        if(in.edges[i]){
            edges[i] = new trie_node(*in.edges[i]);
        }
        else{
            edges[i] = nullptr;
        }
    }
}

void trie_node::delete_node(){
    for(int i = 0; i < alphabet_size; i++){
        if(edges[i]){
            delete edges[i];
        }
    }
    delete[] edges;
}

trie_node::~trie_node(){
    delete_node();
}

int trie_node::get_char_index(char ch){
    switch(ch){
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
        default:
            throw invalid_argument("Invalid character: " + string(1, ch));
    }
}

int trie_node::add_edge(char ch, bool term){
    int index;
    try{
        index = get_char_index(ch);
    }
    catch(invalid_argument err){
        throw err;
    }
    if(edges[index] == nullptr){
        trie_node* node = new trie_node(ch, term);
        edges[index] = node; 
    }
    else{
        edges[index]->terminator = edges[index]->terminator || term;
    }
    return index;   
}

trie::trie(){
    root = new trie_node('#', false);
}

trie::trie(const trie& in){
    root = new trie_node(*in.root);
}

trie::~trie(){
    root->delete_node();
}

void trie::insert_word(string word){
    int index;
    string::iterator last = word.end() - 1;
    trie_node* curr = root;
    for(string::iterator iter = word.begin(); iter != word.end(); iter++){
        try{
            if(iter == last){
                index = curr->add_edge(*iter, true);
            }
            else{
                index = curr->add_edge(*iter, false);
            }                
        }
        catch(invalid_argument){
            throw;
        }
        curr = curr->edges[index];
    }
}

void trie_node::print_word_from_asc(string& prev){
    if(value != '#'){
        prev += value;
        if(terminator){
            cout << prev << "\n";
        }       
    }
    for(int i = 0; i < alphabet_size; i++){
        if(edges[i]){
            edges[i]->print_word_from_asc(prev);
        }
    }
    if(!prev.empty()){
        prev.pop_back();        
    }
}

void trie_node::print_word_from_desc(string& prev){
    if(value != '#'){
        prev += value;    
    }
    for(int i = alphabet_size-1; i >= 0; i--){
        if(edges[i]){
            edges[i]->print_word_from_desc(prev);
        }
    }
    if(terminator){
        cout << prev << "\n";
    }   
    if(!prev.empty()){
        prev.pop_back();        
    }
}

void trie_node::print_tree_from(int width, bool silent){
    vector<int> next;
    if(!silent){
        for(int i = 0; i < width; i++){
            cout << " ";
        }
        cout << "|-" << value;
        if(terminator){
            cout << ".\n";
        }
        else{
            cout <<"\n";
        }        
    }
    for(int i = 0; i < alphabet_size; i++){
        if(edges[i]){
            next.push_back(i);
        }
    }
    while(next.size() > 1){
        int call = next.back();
        next.pop_back();
        edges[call]->print_tree_from(width+2, false);
    }
    if(next.size() == 1){
        int call = next.back();
        next.pop_back();
        edges[call]->print_tree_from(width+2, false);
    }
}

void trie::print_all_words(string order){
    string prev = "";
    if(order != "DESC"){
        root->print_word_from_asc(prev);        
    }
    else{
        root->print_word_from_desc(prev);
    }
}

void trie::print_tree(){
    cout << "#\n";
    root->print_tree_from(-2, true);
}