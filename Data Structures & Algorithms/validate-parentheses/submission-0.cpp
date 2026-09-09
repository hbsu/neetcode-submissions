class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack; //stack

        for(int i = 0; i < s.length(); i++){
            //iterate through the string, push opening brackets onto the stack, only pop if closing bracket matches opening bracket type.
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') stack.push(s[i]);
            else if (!stack.empty() && s[i] == ')' && stack.top() == '(') stack.pop();
            else if (!stack.empty() && s[i] == '}' && stack.top() == '{') stack.pop();
            else if (!stack.empty() && s[i] == ']' && stack.top() == '[') stack.pop();
            else return false;
        }
        return stack.empty();
    }
};
