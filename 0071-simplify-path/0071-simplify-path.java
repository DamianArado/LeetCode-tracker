class Solution {
    public String simplifyPath(String path) {
        var s = new Stack<String>();
        String[] dirs = path.split("/");
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < dirs.length; ++i) {
            if (!s.isEmpty() && dirs[i].equals("..")) s.pop();
            else if (!dirs[i].equals("") && !dirs[i].equals(".") && !dirs[i].equals(".."))
                s.push(dirs[i]);
        }
        if (s.isEmpty()) return "/";
        while (!s.isEmpty())
            ans.insert(0, s.pop()).insert(0, "/");
        return ans.toString();
    }
}