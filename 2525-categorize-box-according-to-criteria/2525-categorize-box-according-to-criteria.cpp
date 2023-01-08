class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        vector<string> cat;
        if(length >= 1e4 or width >= 1e4 or height >= 1e4 or mass >= 1e4 or (((long long)length * width * height) >= 1e9)) cat.push_back("Bulky");
        if(mass >= 100) cat.push_back("Heavy");
        if(cat.size() == 2) return "Both";
        if(cat.empty()) return "Neither";
        return cat[0];
    }
};