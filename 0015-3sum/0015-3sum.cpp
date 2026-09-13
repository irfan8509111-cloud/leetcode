class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        if (n < 3) return {};

            
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        result.reserve(n);

        const int* base = nums.data();

        for (int i = 0; i < n - 2; ++i) {
            int valI = base[i];


            if (valI > 0) break;

            
            if (i > 0 && valI == base[i - 1]) continue;

            
            if (valI + base[n - 1] + base[n - 2] < 0) continue;

            
            if (valI + base[i + 1] + base[i + 2] > 0) break;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = valI + base[left] + base[right];

                if (sum == 0) {
                    result.push_back({valI, base[left], base[right]});

                    int leftVal = base[left];
                    int rightVal = base[right];


                    while (left < right && base[left] == leftVal) ++left;
                    while (left < right && base[right] == rightVal) --right;
                } 
                else if (sum < 0) {
                    ++left;
                    while (left < right && base[left] == base[left - 1]) ++left;
                } 
                else {
                    --right;
                    while (left < right && base[right] == base[right + 1]) --right;
                }
            }
        }

        return result;
    }
};