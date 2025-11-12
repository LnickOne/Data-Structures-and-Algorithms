#include <iostream>
#include <stack>
using namespace std;
class MyQueue
{
private:
    // 栈是先进后出
    // 队列是先进先出
    // 1 2 3 4
    // 要取到队列的1元素，需要将栈里的元素全部导入到另一个栈中，再取栈顶元素
    stack<int> stack_in;
    stack<int> stack_out;
    MyQueue() {}
    void push(int x)
    {
        stack_in.push(x);
    }
    int pop()
    {
        int result;
        if (stack_out.empty()) // 如果stack_out为空，就从stack_in里导入全部数据
        {
            while (!stack_in.empty())
            {
                int top = stack_in.top();
                stack_out.push(top);
                stack_in.pop();
            }
        }
        result = stack_out.top(); // 从栈出stack_out出栈取出栈顶元素
        stack_out.pop();
        return result;
    }

    int peek()
    {
        int result;
        if (stack_out.empty())
        {
            while (!stack_in.empty())
            {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        result = stack_out.top();
        return result;
    }

    bool empty()
    {
        return stack_in.empty() && stack_out.empty();
    }
};
int main()
{
    return 0;
}
