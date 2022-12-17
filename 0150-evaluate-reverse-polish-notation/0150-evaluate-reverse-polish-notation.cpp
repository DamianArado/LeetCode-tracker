typedef long long ll;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<ll> s;
        for(string &token : tokens) {
            if(token != "+" and token != "-" and token != "*" and token != "/") s.emplace(stoi(token));
            else {
                ll second = s.top(); s.pop();
                ll first = s.top(); s.pop();
                ll res;
                if(token == "+") res = first + second;
                else if(token == "-") res = first - second;
                else if(token == "*") res = first * second;
                else res = first / second;
                s.emplace(res);
            }
        }
        return ((int)s.top());
    }
};