class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code;
        while (url2code.find(longUrl) == url2code.end()) {
            random_shuffle(alphabets.begin(), alphabets.end());
            code = alphabets.substr(0, 6);
            if (code2url.find(code) == code2url.end()) {
                code2url[code] = longUrl;
                url2code[longUrl] = code;
            }
        }
        return "http://tinyurl.com/" + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int p = shortUrl.find_last_of("/");
        return code2url[shortUrl.substr(p + 1)];
    }
private:
    string alphabets = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string, string> url2code, code2url;
};