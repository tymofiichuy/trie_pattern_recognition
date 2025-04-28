#include<iostream>
#include<vector>
#include<string>

using namespace std;

class trie_node{
    private:
        char value;
        trie_node** edges;
        bool terminator;
        int alphabet_size = 4;
        //alphabet: A, C, G, T
        static int get_char_index(char ch);
    public:
        int add_edge(char ch, bool term);
        void print_word_from_asc(string& prev);
        void print_word_from_desc(string& prev);
    
        void print_tree_from(int width, bool silent);
        void delete_node();
    
        trie_node(char ch, bool term = true);
        trie_node(const trie_node& in);    
        ~trie_node();
    
        friend class trie;
};

class trie{
    private:
        trie_node* root;
    public:
        void insert_word(string word);
        void print_all_words(string order = "NULL");
        void print_tree();
    
        trie();
        trie(const trie& in);
        ~trie();
    
        friend class dictionary;
    };