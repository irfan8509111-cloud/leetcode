class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        if (n < 4) return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        const int* p = nums.data();

        for (int i = 0; i < n - 3; ++i) {
            
            if (i > 0 && p[i] == p[i - 1]) continue;

            
            long long min1 = (long long)p[i] + p[i + 1] + p[i + 2] + p[i + 3];
            if (min1 > target) break;

            
            long long max1 = (long long)p[i] + p[n - 1] + p[n - 2] + p[n - 3];
            if (max1 < target) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                
                if (j > i + 1 && p[j] == p[j - 1]) continue;

                // Min-bound pruning for second loop
                long long min2 = (long long)p[i] + p[j] + p[j + 1] + p[j + 2];
                if (min2 > target) break;

                // Max-bound pruning for second loop
                long long max2 = (long long)p[i] + p[j] + p[n - 1] + p[n - 2];
                if (max2 < target) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)p[i] + p[j] + p[left] + p[right];

                    if (sum == target) {
                        result.push_back({p[i], p[j], p[left], p[right]});

                        int leftVal = p[left];
                        int rightVal = p[right];

                        while (left < right && p[left] == leftVal) ++left;
                        while (left < right && p[right] == rightVal) --right;
                    } 
                    else if (sum < target) {
                        ++left;
                    } 
                    else {
                        --right;
                    }
                }
            }
        }

        return result;
    }
};