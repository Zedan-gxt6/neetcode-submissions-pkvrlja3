class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> s;

        for(string token : tokens){
            if(token == "+"){
                int b = s.back(); s.pop_back();
                int a = s.back(); s.pop_back();
                s.push_back(a + b);
            }
            else if(token == "*"){
                int b = s.back(); s.pop_back();
                int a = s.back(); s.pop_back();
                s.push_back(a * b);
            }
            else if(token == "-"){
                int b = s.back(); s.pop_back();
                int a = s.back(); s.pop_back();
                s.push_back(a - b);
            }
            else if(token == "/"){
                int b = s.back(); s.pop_back();
                int a = s.back(); s.pop_back();
                s.push_back(a / b);
            }
            else{
                s.push_back(stoi(token));
            }
        }

        return s.back();
    }
};