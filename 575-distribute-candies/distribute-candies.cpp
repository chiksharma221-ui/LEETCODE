class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_map<int,int>map;
        for(int i=0;i<n;i++)
        {
            map[candyType[i]]++;
        }
        int eats=n/2;
        int a=map.size();
        return min(a,eats);
    }
};