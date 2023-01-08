class DataStream {
private:
    int counter;
    int val, k;
public:
    DataStream(int value, int k) {
        this->val = value;
        this->k = k;
        counter = 0;
    }
    bool consec(int num) {
        if(num == val) ++counter;
        else counter = 0;
        return counter >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */