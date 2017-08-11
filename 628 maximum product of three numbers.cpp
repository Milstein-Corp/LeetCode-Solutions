class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxA=INT_MIN,maxB=INT_MIN,maxC=INT_MIN;
        int minA=INT_MAX,minB=INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxA)
            {
                maxC=maxB;
                maxB=maxA;
                maxA=nums[i];
            }
            else if(nums[i]>maxB)
            {
                maxC=maxB;
                maxB=nums[i];
            
            }else if(nums[i]>maxC)
            {
                maxC=nums[i];
            }
            
            if(minA>nums[i])
            {
                minB=minA;
                minA=nums[i];
            }
            else if(minB>nums[i])
            {
                minB=nums[i];
            }
            
        }
        return max(maxA*maxB*maxC,minA*minB*maxA);
    }
};