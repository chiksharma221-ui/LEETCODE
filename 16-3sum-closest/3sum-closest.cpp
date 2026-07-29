class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        int closest=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            //if(nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(target-sum)<abs(target-closest))
                {
                    closest=sum;
                }
                
                if(sum<target) j++;
                else if(sum>target) k--;
                else{
                    return sum;
                }
                
            }
        }
        return closest;
    }
};