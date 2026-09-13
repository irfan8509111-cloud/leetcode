class Solution {
public:
    vector<string> letterCombinations(string digits) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (digits.empty()) return {};

        
        const string mappings[10] = {
            "",     "",     "abc",  "def", 
            "ghi",  "jkl",  "mno", 
            "pqrs", "tuv",  "wxyz"
        };

        vector<string> result;
        

        int totalCombinations = 1;
        for (char d : digits) {
            totalCombinations *= mappings[d - '0'].length();
        }
        result.reserve(totalCombinations);

        string current(digits.length(), ' ');
        backtrack(digits, 0, current, result, mappings);

        return result;
    }

private:
    void backtrack(const string& digits, int index, string& current, 
                   vector<string>& result, const string mappings[]) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        const string& letters = mappings[digits[index] - '0'];
        for (char c : letters) {
            current[index] = c;
            backtrack(digits, index + 1, current, result, mappings);
        }
    }
};