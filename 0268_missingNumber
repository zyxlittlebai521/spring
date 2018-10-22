class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int size = nums.size();
        vector<int>vec(size+1,-1);
        for(int i = 0;i < size;++i)
        {
            vec[nums[i]]= i;
        }
        
        for(int i = 0;i < vec.size();++i)
        {
            if(vec[i] == -1)
            {
                return i;
            }
        }
        
    }
};
