class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ans = new ArrayList<>();
        int n = s.length(), k = p.length(), i = 0, j = 0;
        HashMap<Character, Integer> mp = new HashMap<>();
        for(int idx = 0; idx < p.length(); ++idx) {
            if(mp.containsKey(p.charAt(idx))) 
                mp.put(p.charAt(idx), mp.get(p.charAt(idx)) + 1);
            else
                mp.put(p.charAt(idx), 1);
        }
        
        int chars = mp.size();
        
        while(j < n) {
            if(mp.containsKey(s.charAt(j))) {
                mp.put(s.charAt(j), mp.get(s.charAt(j)) - 1);
                if(mp.get(s.charAt(j)) == 0) chars--;
            }
            if(j - i + 1 < k) j++;
            else if(j - i + 1 == k) {
                if(chars == 0)
                    ans.add(i);
                if(mp.containsKey(s.charAt(i))) {
                    mp.put(s.charAt(i), mp.get(s.charAt(i)) + 1);
                    if(mp.get(s.charAt(i)) == 1) chars++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
}