class Solution {
   public:
    int rob(vector<int>& nums) {
        size_t n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        std::vector<int> nums1(nums.begin() + 1, nums.end());
        std::vector<int> nums2(nums.begin(), nums.end() - 1);
        return std::max(helper(nums1), helper(nums2));
    }

   private:
    int helper(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        for (size_t i = 2; i < nums.size(); i++) {
            if (i != 2)
                nums[i] = nums[i] + std::max(nums[i - 2], nums[i - 3]);
            else
                nums[i] = nums[i] + nums[i - 2];
        }

        return std::max(nums[nums.size() - 1], nums[nums.size() - 2]);
    }
};
