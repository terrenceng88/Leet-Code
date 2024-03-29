/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
*/



//runs in O(n) time complexity using trie traversal (n = length of string being searched)




class TrieNode {
    private TrieNode[] children;
    private boolean isEndOfWord;


    public TrieNode() {
        isEndOfWord = false; //marks end of a word in trie
        children = new TrieNode[26]; //create children nodes, each letter of alphabet


        for(int i = 0; i < 26; i++) {
            children[i] = null;
        }
    }


    public boolean isEndOfWord() {
        return isEndOfWord;
    }


    public void setEnd() {
        isEndOfWord = true;
    }


    public TrieNode getChild(int index) {
        if(children[index] != null) {
            return children[index];
        }
        return null;
    }


    public void addChild(int index) {
        if(children[index] != null) {
           return; 
        }
        children[index] = new TrieNode();
    }
}




class Trie {
    TrieNode root;


    public Trie() {
        root = new TrieNode();   
    }
    
    public void insert(String word) {
        TrieNode crawler = root;
        char[] chArr = word.toCharArray(); //toCharArray converts a string to an array of char's
        for(char chr: chArr) { 
            int index = chr - 'a';
            crawler.addChild(index);
            crawler = crawler.getChild(index); //move to next node in trie and letter in word (make new node)
        }
        crawler.setEnd(); //done adding this word
    }
    
    public boolean search(String word) {
        TrieNode crawler = root;
        char[] chArr = word.toCharArray(); //toCharArray converts a string to an array of char's
        for(char chr: chArr) {
            int index = chr - 'a';
            if(crawler.getChild(index) == null) {
                return false;
            }
            crawler = crawler.getChild(index); //move to next node in trie and letter in word (make new node)
        }
        if(crawler.isEndOfWord()) {
            return true;
        }
        return false;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode crawler = root;
        char[] chArr = prefix.toCharArray(); //toCharArray converts a string to an array of char's
        for(char chr: chArr) {
            int index = chr - 'a';
            if(crawler.getChild(index) == null) {
                return false;
            }
            crawler = crawler.getChild(index); //move to next node in trie and letter in word (make new node)
        }
        return true;
    }
}


/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */



