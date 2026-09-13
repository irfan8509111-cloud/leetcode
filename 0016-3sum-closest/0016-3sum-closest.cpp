class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        sort(nums.begin(), nums.end());

        const int* p = nums.data();
        int closestSum = p[0] + p[1] + p[2];

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && p[i] == p[i - 1]) continue;


            int minSum = p[i] + p[i + 1] + p[i + 2];
            if (minSum > target) {
                if (abs(minSum - target) < abs(closestSum - target)) {
                    closestSum = minSum;
                }
                break;
            }

            
            int maxSum = p[i] + p[n - 1] + p[n - 2];
            if (maxSum < target) {
                if (abs(maxSum - target) < abs(closestSum - target)) {
                    closestSum = maxSum;
                }
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = p[i] + p[left] + p[right];

                
                if (sum == target) return target;

                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                if (sum < target) {
                    ++left;
                    while (left < right && p[left] == p[left - 1]) ++left; 
                } else {
                    --right;
                    while (left < right && p[right] == p[right + 1]) --right; 
                }
            }
        }

        return closestSum;
    }
};