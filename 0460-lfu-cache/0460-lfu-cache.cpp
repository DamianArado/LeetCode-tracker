// Clean and Perfect Code! :D
class LFUCache {
private:
    struct Node {
        int key, value, freq;
        Node *next, *prev;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            this->freq = 1;
        }
    };
    struct List {
        Node *head, *tail;
        int size;
        List() {
            this->head = new Node(-1, -1);
            this->tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            this->size = 0;
        }
            
        void addFront(Node* node) {
            Node *temp = head->next;
            node->next = temp;
            temp->prev = node;
            head->next = node;
            node->prev = head;
            ++(this->size);
        }
        
        void removeEnd(Node *toBeDeleted) {
            Node *delPrev = toBeDeleted->prev, *delNext = toBeDeleted->next;
            delPrev->next = delNext;
            delNext->prev = delPrev;
            --(this->size);
        }
    };
    int maxSizeCache, minFreq, currentSize;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;
public:
    LFUCache(int capacity) {
        this->maxSizeCache = capacity;
        this->minFreq = 0, this->currentSize = 0;
    }
    
    void updateFreqListMap(Node *node) {
        keyNode.erase(node->key);
        freqListMap[node->freq]->removeEnd(node);
        if(node->freq == this->minFreq and freqListMap[node->freq]->size == 0)
            ++(this->minFreq);
        List *nextHigherFreqList = new List();
        if(freqListMap.count(node->freq + 1))
            nextHigherFreqList = freqListMap[node->freq + 1];
        ++(node->freq);
        nextHigherFreqList->addFront(node);
        freqListMap[node->freq] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.count(key)) {
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(this->maxSizeCache == 0) return;
        if(keyNode.count(key)) {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        } else {
            if(this->currentSize == this->maxSizeCache) {
                List *list = freqListMap[this->minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeEnd(list->tail->prev);
                --(this->currentSize);
            }
            ++(this->currentSize);
            this->minFreq = 1;
            List *listFreq = new List();
            if(freqListMap.count(minFreq))
                listFreq = freqListMap[minFreq];
            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */