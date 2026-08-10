class Solution {
    std::vector<int> dfs_values;

   public:
    int rob(vector<int>& nums) {
        size_t n = nums.size();
        dfs_values.resize(n, -1);

        if (n == 1) {
            return nums[0];
        }

        return dfs(nums, 0);
    }

    int dfs(std::vector<int>& nums, int i){
        if (i >= nums.size()) {
            return 0;
        }

        if (dfs_values[i] != -1) {
            return dfs_values[i];
        } else {
            dfs_values[i] = std::max(dfs(nums, i + 1), nums[i] + dfs(nums, i + 2));
            return dfs_values[i];
        }
    };
};
