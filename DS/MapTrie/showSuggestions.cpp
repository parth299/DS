#include <iostream>
using namespace std;

class TrieNode{
    public:
        char value;
        TrieNode* children[26];
        bool isTerminal;
    
    TrieNode(char val){
        this->value = val;
        for(int i=0; i<26; i++){
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = true;
        return ;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        //Already present
        child = root->children[index];
    }
    else{
        //Character is not yet present
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));

}

bool searchWord(TrieNode* root, string word){

    if(word.length() == 0){
        if(root->isTerminal)
            return true;
        else
            return false;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        return false;
    }

    return searchWord(child, word.substr(1));
}

int main(){

    TrieNode* root= new TrieNode('-');

    insertWord(root, "car");
    insertWord(root, "cat");
    insertWord(root, "name");
    insertWord(root, "camel");
    insertWord(root, "number");
    // cout << "Insertion done" << endl;

    if(searchWord(root, "named")){
        cout << "Found";
    }
    else{
        cout << "Not found" << endl;
    }

    return 0;
}