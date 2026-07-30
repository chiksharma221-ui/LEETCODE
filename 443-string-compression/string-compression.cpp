class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0,index=0;
        while(i<n)
        {
            char curr_char=chars[i];
            int count=0;
            while(i<n && chars[i]==curr_char)
            {
                count++;
                i++;
            }
            chars[index]=curr_char;
            index++;

            if(count>1)
            {
                string s=to_string(count);
                for(char &ch :s)
                {
                    chars[index]=ch;
                    index++;
                }
            }
        }
        return index;
    }
};