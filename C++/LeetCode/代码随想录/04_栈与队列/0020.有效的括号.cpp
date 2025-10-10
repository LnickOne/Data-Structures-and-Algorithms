#include "../../include/utils.h"
class Solution
{
public:
  bool isValid(string s)
  {
    if (s.empty())
      return true;
    stack<char> stack;
    for (char ch : s)
    {
      if (ch == '(' || ch == '{' || ch == '[')
      {
        stack.push(ch);
      }
      else if (ch == ')' || ch == '}' || ch == ']')
      {
        if (stack.empty())
          return false;
        if (!stack.empty())
        {
          char top = stack.top();
          stack.pop();
          if (top == '(' && ch != ')')
            return false;
          else if (top == '{' && ch != '}')
            return false;
          else if (top == '[' && ch != ']')
            return false;
        }
      }
    }
    return stack.empty();
  }
};

int main()
{
  Solution s;
  cout << s.isValid("()[]{}") << endl;
  cout << s.isValid("(]") << endl;
  cout << s.isValid("([)]") << endl;
  cout << s.isValid("{[]}") << endl;
  return 0;
}