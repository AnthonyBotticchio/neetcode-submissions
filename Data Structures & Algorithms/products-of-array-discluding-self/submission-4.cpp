class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> res(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++)
        {
            res[i] = nums[i - 1] * res[i - 1];
        }

        int postFix = 1;
        for(int i = static_cast<int>(nums.size()) - 1; i >= 0; i--)
        {
            res[i] *= postFix;
            postFix *= nums[i];
        }

        return res;
    }
};
