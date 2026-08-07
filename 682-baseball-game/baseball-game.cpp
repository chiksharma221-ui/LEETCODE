class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> s;

        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i] == "C")
            {
                s.pop();
            }
            else if(operations[i] == "D")
            {
                s.push(2 * s.top());
            }
            else if(operations[i] == "+")
            {
                int a = s.top();
                s.pop();

                int b = s.top();

                s.push(a);          // wapas daal diya
                s.push(a + b);
            }
            else
            {
                s.push(stoi(operations[i]));
            }
        }

        int total = 0;

        while(!s.empty())
        {
            total += s.top();
            s.pop();
        }

        return total;
    }
};