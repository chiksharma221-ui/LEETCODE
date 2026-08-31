class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        freq=[0]*256
        first=0
        second=0
        count=0
        while second<len(s):
            freq[ord(s[second])]+=1

            while(freq[ord(s[second])]>1):
                freq[ord(s[first])]-=1
                first+=1
            count=max(count,second-first+1)
            second+=1
        return count