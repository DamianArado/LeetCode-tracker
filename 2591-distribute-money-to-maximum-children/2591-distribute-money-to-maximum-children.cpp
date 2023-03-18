class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children) return -1;
        if(money < 8) return 0;
        int ans = 0;
        while(money > 0 and children > 0 and money - 8 >= (children - 1)) {
            ++ans;
            money -= 8;
            --children;
        }
        if(money == 4 and children == 1 or (money > 0 and children == 0)) --ans;
        return ans;
    }
};