class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        if(n == 0) return true;
        int sz = flowerbed.length;
        if(sz == 1) {
            if(flowerbed[0] == 0 && n == 1) return true;
            return false;
        }
        if(flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n -= 1;
        }
        for(int i = 1; i < sz - 1; ++i) {
            if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                n -= 1;
            }
            if(n == 0) return true;
        }
        if(flowerbed[sz - 2] == 0 && flowerbed[sz - 1] == 0 && n > 0) n -= 1;
        return n == 0;
    }
}