class Solution {
public:
    string removeKdigits(string num, int k) {
        // tc and sc: O(n)
        if(num.size() == k) return "0";
        string ans = "";
        for(char &c : num) {
            // Step 1: check if the last element in string is greater than the one we are standing at
            //         and if yes, remove it
            while(!ans.empty() and ans.back() > c and k)
                 --k, ans.pop_back();
            // Step 2: otherwise add elements to our answer
            // ans.size() > 0 just to make sure that we consider the trailing zeroes as well
            if(!ans.empty() or c != '0') 
                ans.push_back(c);
        }
        // just if we already have k left
        while(!ans.empty() and k--)
            ans.pop_back();
        return ans == "" ? "0" : ans;
    }
};