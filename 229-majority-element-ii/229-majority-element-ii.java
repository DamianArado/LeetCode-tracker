class Solution {
    public List<Integer> majorityElement(int[] nums) {
        var majorityElem = new ArrayList<Integer>();
        int elem1 = -1, count1 = 0, elem2 = -1, count2 = 0, n = nums.length;
        for(int num : nums) {
            if(elem1 == num) count1++;
            else if(elem2 == num) count2++;
            else if(count1 == 0) {
                elem1 = num;
                count1++;
            } 
            else if(count2 == 0) {
                elem2 = num;
                count2++;
            } 
            else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for(int num : nums) {
            if(elem1 == num) count1++;
            if(elem2 == num) count2++;
        }
        if(count1 > n / 3) majorityElem.add(elem1);
        if(count2 > n / 3 && elem2 != elem1) majorityElem.add(elem2);
        return majorityElem;
    }
}