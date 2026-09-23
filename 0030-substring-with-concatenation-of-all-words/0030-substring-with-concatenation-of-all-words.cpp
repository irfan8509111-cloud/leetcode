class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int wordLen = words[0].length();
        int numWords = words.size();
        int substringLen = wordLen * numWords;
        int n = s.length();
        
        if (n < substringLen) return result;
        
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }
        
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int right = i;
            unordered_map<string, int> windowSeen;
            int validWords = 0;
            
            while (right + wordLen <= n) {
                string currentWord = s.substr(right, wordLen);
                right += wordLen;
                
                if (wordCount.find(currentWord) != wordCount.end()) {
                    windowSeen[currentWord]++;
                    validWords++;
                    
                    while (windowSeen[currentWord] > wordCount[currentWord]) {
                        string leftWord = s.substr(left, wordLen);
                        windowSeen[leftWord]--;
                        validWords--;
                        left += wordLen;
                    }
                    
                    if (validWords == numWords) {
                        result.push_back(left);
                    }
                } else {
                    windowSeen.clear();
                    validWords = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};