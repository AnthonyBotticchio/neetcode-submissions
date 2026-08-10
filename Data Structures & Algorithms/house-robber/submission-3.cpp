class Solution {
    std::unordered_map<int, int> dfs_values;

   public:
    int rob(vector<int>& nums) {
        size_t n = nums.size();
        dfs_values.reserve(n);

        if (n == 1) {
            return nums[0];
        }

        int first = 0, second = nums[0], helper;

        for(int i = 1; i < nums.size(); i++) {
            helper = std::max(first + nums[i], second);
            first = second;
            second = helper;
        }
        
        return second;
    }

    int dfs(std::vector<int>& nums, int i){
        if (i >= nums.size()) {
            return 0;
        }

        if (const auto& it = dfs_values.find(i); it != std::end(dfs_values)) {
            return it->second;
        } else {
            const int res = std::max(dfs(nums, i + 1), nums[i] + dfs(nums, i + 2));
            dfs_values.emplace(i, res);
            return res;
        }
    };
};
