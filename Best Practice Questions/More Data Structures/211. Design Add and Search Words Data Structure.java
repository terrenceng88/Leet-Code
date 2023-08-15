/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
*/


//Runs in O(n) time using trie



//Hash Map Approach =========================================================================
class WordDictionary {
    private HashSet<String> map;


    public WordDictionary() {
        map = new HashSet<>();        
    }
   
    public void addWord(String word) {
        map.add(word);
    }
   
    public boolean search(String word) {
        if(map.contains(word)) { //exact match
            return true;
        }
        if(word.contains(".")) {//check if match with '.'
            for(String curr: map) { //traverse each word in map
                if(word.length() == curr.length()) { //different size = different word
                    for(int i = 0; i < word.length(); i++) {
                        char ch1 = word.charAt(i); //for traversing word
                        char ch2 = curr.charAt(i); //for traversing current word in map


                        if(ch1 != ch2 && ch1 != '.') { //different letter and no dot
                            break; //not same word
                        }


                        //reaches last char in both word and curr without differences
                        if(i == word.length() - 1) {
                            return true;
                        }
                    }
                }
            }
        }
        return false; //not in dictionary
    }
}


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */




a
//Trie Approach =============================================================================


class WordDictionary {
    private WordDictionary[] children;
    boolean isEndOfWord;
   
    public WordDictionary() {
        children = new WordDictionary[26]; //create children nodes, each letter of alphabet
        isEndOfWord = false; //initialize boolean
    }
   
    public void addWord(String word) {
        WordDictionary curr = this; //start at top node and crawl through WordDictionary
        char[] charArr = word.toCharArray(); //convert word to char array
        for(char chr: charArr) {
            int index = chr - 'a'; //convert to index of letter in alphabet
            if(curr.children[index] == null) { //if node does not exist yet
                curr.children[index] = new WordDictionary(); //add child
            }
            curr = curr.children[index]; //move to next node in trie
        }
        curr.isEndOfWord = true;
    }
   
    public boolean search(String word) {
        WordDictionary curr = this; //start at top node and crawl through WordDictionary
        char[] charArr = word.toCharArray(); //convert word to char array
        for(int i = 0; i < word.length(); i++) {
            char chr = word.charAt(i);
            int index = chr - 'a'; //convert to index of letter in alphabet
            if(chr == '.'){
                for(WordDictionary ch: curr.children) //iterate through every letter child of current node
                    if(ch != null && ch.search(word.substring(i + 1))) { //if child exists, skip 1 iteration and look for next letter
                        return true;
                    }
                return false;
            }
            if(curr.children[index] == null) { //if can't find next letter of word
                return false;
            }
            curr = curr.children[index]; //move to next node in trie
        }
        if(curr.isEndOfWord == true) {
            return true;
        }
        return false;
    }
}


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */