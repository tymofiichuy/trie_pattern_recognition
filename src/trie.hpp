#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

class trie_node{
    private:
        char value;
        trie_node** edges;
        bool terminator;
        std::vector<int> numbers;
        int alphabet_size = 4;
        //alphabet: A, C, G, T

        static int get_char_index(char ch);
        static char get_char_from_index(int ind);
    public:
        int add_edge(char ch, bool term, int num);

        void print_edges_from(int curr, int& next, std::ofstream& out);

        void print_word_from_asc(std::string& prev);
        void print_word_from_desc(std::string& prev);
    
        void print_tree_from(int width, bool silent);
        void delete_node();
    
        trie_node(char ch, bool term = true);
        trie_node(const trie_node& in);    
        ~trie_node();
    
        friend class trie;
        friend class pattern_recognition;
};

class trie{
    private:
        trie_node* root;
    public:
        void insert_word(std::string word, int num);
        void print_all_words(std::string order = "NULL");

        void print_edges(std::ofstream& out_file);
        void print_tree();
    
        trie();
        trie(const trie& in);
        ~trie();

        friend class pattern_recognition;
};