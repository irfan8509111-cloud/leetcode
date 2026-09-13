#include <string>

class Solution {
public:
    std::string intToRoman(int num) {
        static const std::string M[]  = {"", "M", "MM", "MMM"};
        static const std::string C[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        static const std::string X[]  = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        static const std::string I[]  = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        std::string result;
        result.reserve(16);

        result += M[num / 1000];
        result += C[(num % 1000) / 100];
        result += X[(num % 100) / 10];
        result += I[num % 10];

        return result;
    }
};