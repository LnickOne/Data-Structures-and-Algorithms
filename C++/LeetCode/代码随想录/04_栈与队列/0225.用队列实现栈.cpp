#include <iostream>
#include <queue>
using namespace std;
class MyStack
{
private:
    //  队列先进先出
    //  栈先进后出
    //  队列<-(front) 1 2 3 4 (back)
    //  要取到4这个栈顶元素，需要把1 2 3 4 重新入队，
    //  然后再把1 2 3 4 重新出队，这样就实现了栈的先进后出
    queue<int> queue_in;
    queue<int> queue_out;
    MyStack() {}
    void push(int x)
    {
        queue_in.push(x);
    }
    int pop()
    {
        int size = queue_in.size();
        size--;
        while (size > 0)
        {
            int top = queue_in.front();
            queue_out.push(top);
            queue_in.pop();
            --size;
        }
        int result = queue_in.front();
        queue_in.pop();
        queue_in = queue_out;
        while (!queue_out.empty())
            queue_out.pop();
        return result;
    }
    int top()
    {
        return queue_in.back();
    }

    bool empty()
    {
        return queue_in.empty() && queue_out.empty();
    }
};

class MyStack
{
private:
    queue<int> queue;
    MyStack()
    {
    }

    void push(int x)
    {
        queue.push(x);
    }

    int pop()
    {
        int size = queue.size();
        size--; // 先减1，因为要把最后一个元素弹出
        while (size > 0)
        {
            queue.push(queue.front());
            queue.pop();
            size--;
        }
        int result = queue.front(); // 记录最后一个元素
        queue.pop();                // 弹出最后一个元素
        return result;
    }
    int top()
    {
        return queue.back();
    }

    bool empty()
    {
        return queue.empty();
    }
};

int main()
{
    return 0;
}
