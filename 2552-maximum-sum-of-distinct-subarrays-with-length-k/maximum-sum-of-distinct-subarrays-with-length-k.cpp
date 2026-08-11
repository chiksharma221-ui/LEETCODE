class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        long long sum = 0;
        long long maxi = 0;

        int first = 0, second = 0;

        unordered_map<int, int> m;

        while(second < n)
        {
            m[nums[second]]++;
            sum += nums[second];

            // Window size k se zyada ho gayi
            while(second - first + 1 > k)
            {
                m[nums[first]]--;

                if(m[nums[first]] == 0)
                    m.erase(nums[first]);

                sum -= nums[first];
                first++;
            }

            // Window size exactly k AND all elements distinct
            if(second - first + 1 == k && m.size() == k)
            {
                maxi = max(maxi, sum);
            }

            second++;
        }

        return maxi;
    }
};