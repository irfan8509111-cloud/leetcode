class Solution {
public:
    bool isValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);


        if (s.length() % 2 != 0) return false;


        char st[10000];
        int top = -1;

        for (char c : s) {
            if (c == '(') {
                st[++top] = ')';
            } else if (c == '{') {
                st[++top] = '}';
            } else if (c == '[') {
                st[++top] = ']';
            } else {
                if (top == -1 || st[top--] != c) {
                    return false;
                }
            }
        }

        return top == -1;
        
    }
};