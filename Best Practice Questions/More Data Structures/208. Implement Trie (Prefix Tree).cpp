/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
*/



//runs in O(n) time complexity using trie traversal (n = length of string being searched)




class Trie {
public:
    struct trieNode {
        bool isEndOfWord; //marks end of a word in trie
        trieNode* children[26]; //each letter of the alphabet
    };
    
    trieNode* getNode() { //creates a new Trie node
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false; //not end of word because node was just created
        for(int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }


    trieNode* root;


    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* crawler = root; //used to traverse trie
        for(char chr: word) {
            int index = chr - 'a'; //get the current letter's place in the alphabet
            if(crawler->children[index] == NULL) { //if letter doesn't exist for this prefix yet
                crawler->children[index] = getNode();
            }
            crawler = crawler->children[index]; //move to next node in trie and letter in word
        }
        crawler->isEndOfWord = true; //done adding this word
    }
    
    bool search(string word) {
        trieNode* crawler = root; //used to traverse trie
        for(char chr: word) {
            int index = chr - 'a'; //get the current letter's place in the alphabet
            if(crawler->children[index] == NULL) { //trie does not contain letter in word
                return false; //word doesn't exist in trie
            }
            crawler = crawler->children[index];//move to next node in trie and letter in word
        }
        if(crawler->isEndOfWord) { //word exists in trie if all letters exist and it has been added before
            return true;
        }
        return false; //word was not inserted before
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = root;
        for(char chr: prefix) {
            int index = chr - 'a'; 
            if(crawler->children[index] == NULL) {
                return false;
            }
            crawler = crawler->children[index]; //move to next node in trie and letter in word
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


