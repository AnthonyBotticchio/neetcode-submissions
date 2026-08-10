class Solution {
   public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        
        for(size_t i = 2; i < nums.size(); ++i) {
            if(i != 2)
                nums[i] = nums[i] + std::max(nums[i - 2], nums[i - 3]);
            else
                nums[i] = nums[i] + nums[i - 2];
        }

        return std::max(nums[nums.size() - 1], nums[nums.size() - 2]);
    }
};
