class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>freq;
        int n=ransomNote.size();
        int m=magazine.size();

        for(int i=0;i<n;i++)
        {
            freq[ransomNote[i]]++;
        }
        for(int i=0;i<m;i++)
        {
            freq[magazine[i]]--;
        }
        for(int i=0;i<n;i++)
        {
            if(freq[ransomNote[i]]>0) return 0;
        }
        
        return 1;
    }
};