class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<2) return true;
        int start=1,end=num/2;
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            long long square=mid*mid;

            if(square==num)
            {
                return true;
                break;
            }
            else if(square<num) start=mid+1;
            else end=mid-1;
        }
        return 0;
    }
};