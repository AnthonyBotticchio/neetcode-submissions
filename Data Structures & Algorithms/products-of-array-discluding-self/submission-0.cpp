class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> fStore(nums.size(), 1);
        std::vector<int> rStore(nums.size(), 1);
        std::vector<int> res(nums.size(), 1);

        for(size_t i = 1; i < nums.size(); i++)
        {
            fStore[i] = nums[i - 1] * fStore[i - 1];
        }

        for(int i = nums.size() - 2; i >= 0; i--)
        {
            rStore[i] = nums[i + 1] * rStore[i + 1];
        }

        for(size_t i = 0; i < res.size(); i++)
        {
            res[i] = fStore[i] * rStore[i];
        }

        return res;
    }
};
