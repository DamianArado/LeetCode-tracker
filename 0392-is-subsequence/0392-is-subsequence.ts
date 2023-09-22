function isSubsequence(s: string, t: string): boolean {
    let idx1: number = 0, idx2: number = 0;
    const n1: number = s.length, n2: number = t.length;
        while (idx1 < n1 && idx2 < n2) {
            if (s[idx1] == t[idx2])
                ++idx1, ++idx2;
            else 
                ++idx2;
        }
        return idx1 == n1;
};