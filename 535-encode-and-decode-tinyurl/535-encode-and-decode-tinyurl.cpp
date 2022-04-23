class Solution {
public:
    unordered_map<string,string> m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string enc;
        srand(time(NULL));
        char c='a'+(rand()%26);
        enc+=c;
        while(m.find(enc)!=m.end())
        {
            c='a'+(rand()%26);
            enc+=c;
        }
        m[enc]=longUrl;
        return enc;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));