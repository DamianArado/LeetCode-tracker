class WordDictionary {
private:
    vector<WordDictionary*> linkNext;
    bool isEndOfString;
public:
    WordDictionary() {
        linkNext = vector<WordDictionary*>(26, NULL);
        this->isEndOfString = false;
    }
    
    void addWord(string word) {
        WordDictionary* current = this;
        for(int i = 0; i < size(word); ++i) {
            if(current->linkNext[word[i] - 'a'] == NULL)
                current->linkNext[word[i] - 'a'] = new WordDictionary();
            current = current->linkNext[word[i] - 'a'];
        }
        current->isEndOfString = true;
    }
    bool search(string word) {
        WordDictionary* current = this;
        for(int i = 0; i < size(word); ++i) {
            if(word[i] == '.') {
                for(const auto &ch : current->linkNext) 
                    if(ch != NULL and ch->search(word.substr(i + 1)))
                        return true;
                return false;
            }
            if(current->linkNext[word[i] - 'a'] == NULL) return false;
            current = current->linkNext[word[i] - 'a'];
        }
        return current != NULL and current->isEndOfString;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */