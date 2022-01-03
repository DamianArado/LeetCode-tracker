Creating new strings will take up too much space. Let's use string references.
​
Earlier -
The idea is intuitive. Use two integers to count the remaining left parenthesis (n) and the right parenthesis (m) to be added. At each function call add a left parenthesis if n >0 and add a right parenthesis if m>0. Append the result and terminate recursive calls when both m and n are zero.
```
class Solution {
public:
vector<string> generateParenthesis(int n) {
vector<string> res;
addingpar(res, "", n, 0);
return res;
}
void addingpar(vector<string> &v, string str, int n, int m){
if(n==0 && m==0) {
v.push_back(str);
return;
}
if(m > 0){ addingpar(v, str+")", n, m-1); }
if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
}
};
```