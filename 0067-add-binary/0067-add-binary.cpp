class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = size(a) - 1, j = size(b) - 1, carry = 0;
        while(i >= 0 or j >= 0 or carry == 1) {
            int val = carry;
            if(i >= 0) val += a[i--] - '0';
            if(j >= 0) val += b[j--] - '0';
            ans += (val % 2 + '0');
            carry = val / 2;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};