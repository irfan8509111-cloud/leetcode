#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int n = img1.size();
        std::vector<std::pair<int, int>> nonZero1, nonZero2;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) nonZero1.push_back({r, c});
                if (img2[r][c] == 1) nonZero2.push_back({r, c});
            }
        }

        std::unordered_map<int, int> shiftCount;
        int maxOverlap = 0;

        for (const auto& p1 : nonZero1) {
            for (const auto& p2 : nonZero2) {
                int dr = p2.first - p1.first;
                int dc = p2.second - p1.second;
                
                int key = (dr + 100) * 1000 + (dc + 100);
                
                shiftCount[key]++;
                maxOverlap = std::max(maxOverlap, shiftCount[key]);
            }
        }

        return maxOverlap;
    }
};