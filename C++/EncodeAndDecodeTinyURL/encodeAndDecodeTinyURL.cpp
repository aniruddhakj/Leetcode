// Author : Aniruddha Krishna Jha
// Date : 23/04/2022

/*******************************************************************************
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

There is no restriction on how your encode/decode algorithm should work. 
You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Implement the Solution class:

Solution() Initializes the object of the system.
String encode(String longUrl) Returns a tiny URL for the given longUrl.
String decode(String shortUrl) Returns the original long URL for the given shortUrl. 
It is guaranteed that the given shortUrl was encoded by the same object.
 

Example 1:

Input: url = "https://leetcode.com/problems/design-tinyurl"
Output: "https://leetcode.com/problems/design-tinyurl"

Explanation:
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after deconding it.
*******************************************************************************/

class Solution {
public:
    const string ch = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string, string> original, tinyUrl;
    // Encodes a URL to a shortened URL.
    string encHelper(){
        string res = "";
        for(int i = 0; i < 6; i++){
            res +=  ch[rand() % 62];
        }
        return "http://tinyurl.com/" + res;
    }
    string encode(string longUrl) {
        //if not found return
        if(tinyUrl.find(longUrl) != tinyUrl.end())
            return tinyUrl[longUrl];
        string enc = encHelper();
        while(original.find(enc) != original.end())
            enc = encHelper();
        original[enc] = longUrl;
        tinyUrl[longUrl] = enc;
        return enc;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return original[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
