class T {
    public:
        string name, city;
        int amount, time;
        T(string s) {
            stringstream ss(s); string str;
            vector<string>v;
            while(getline(ss, str, ','))
                v.push_back(str);
            name = v[0], city = v[3];
            time = stoi(v[1]), amount = stoi(v[2]);
        }
        
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transaction) {
        vector<bool> invalid(transaction.size());
        vector<T>details;
        unordered_map<string, vector<int>>m;
        int i = 0;
        for(auto s : transaction) {
            T a = T(s);
            invalid[i] = a.amount > 1000;
            if(m.find(a.name) != m.end()) {
                vector<int>indexes = m[a.name];
                for(auto ind : indexes)
                    if(details[ind].city != a.city and abs(a.time - details[ind].time) <= 60) 
                        invalid[ind] = true, invalid[i] = true;
            }
            m[a.name].push_back(i);
            details.push_back(a);
            i++;
        }
        vector<string>ans;
        for(int i = 0; i < transaction.size(); i++) {
            if(invalid[i])
                ans.push_back(transaction[i]);
        }
        return ans;
    }
};