class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>m;
        int n=changed.size();
        vector<int>ans;
        if(n%2!=0) return {};
        for(int i=0;i<n;i++)
        {
            m[changed[i]]++;
        }
        sort(changed.begin(),changed.end());
        for(int i=0;i<n;i++)
        {
            int num=changed[i]*2;
            
                if(m[changed[i]] == 0)
                continue;

                if(m[changed[i] * 2] == 0)
                return {};

                ans.push_back(changed[i]);
                m[changed[i]]--;
                m[num]--;
        }
        return ans;
    }
};