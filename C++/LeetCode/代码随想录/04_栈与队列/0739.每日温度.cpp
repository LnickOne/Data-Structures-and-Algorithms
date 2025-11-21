/*
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，
下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
示例 1:

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
示例 2:

输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]
示例 3:

输入: temperatures = [30,60,90]
输出: [1,1,0]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
class Solution
{
public:
    /*
    单调栈适用问题：通常是一维数组并且要寻找任一个元素的右边或者左边第一个比自己大或者小的元素的位置
    本题其实就是找找到一个元素右边第一个比自己大的元素，此时就应该想到用单调栈了
    单调栈的本质是空间换时间，因为在遍历的过程中需要用一个栈来记录右边第一个比当前元素高的元素，优点是整个数组只需要遍历一次。
    在使用单调栈的时候首先要明确如下几点：
    单调栈里存放的元素是什么？
    单调栈里只需要存放元素的下标i就可以了，如果需要使用对应的元素，直接T[i]就可以获取。
    单调栈里元素是递增呢？ 还是递减呢？
    注意以下讲解中，顺序的描述为 从栈头到栈底的顺序，因为单纯的说从左到右或者从前到后，不说栈头朝哪个方向的话，大家一定比较懵。
    这里我们要使用递增循序（再强调一下是指从栈头到栈底的顺序）
    因为只有递增的时候，栈里要加入一个元素i的时候，才知道栈顶元素在数组中右面第一个比栈顶元素大的元素是i。
    即：如果求一个元素右边第一个更大元素，单调栈就是递增的，如果求一个元素右边第一个更小元素，单调栈就是递减的。

    使用单调栈主要有三个判断条件。
    当前遍历的元素T[i]小于栈顶元素T[st.top()]的情况
    当前遍历的元素T[i]等于栈顶元素T[st.top()]的情况
    当前遍历的元素T[i]大于栈顶元素T[st.top()]的情况
     */
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> stack;
        vector<int> result(temperatures.size(), 0);
        stack.push(0);
        for (int i = 1; i < temperatures.size(); i++)
        {
            if (temperatures[i] < temperatures[stack.top()])
            {
                stack.push(i);
            }
            if (temperatures[i] == temperatures[stack.top()])
            {
                stack.push(i);
            }
            if (temperatures[i] > temperatures[stack.top()])
            {
                while (!stack.empty() && temperatures[i] > temperatures[stack.top()])
                {
                    result[stack.top()] = i - stack.top();
                    stack.pop();
                }
                stack.push(i);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> temperatures_1{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> temperatures_2{30, 40, 50, 60};
    vector<int> temperatures_3{30, 60, 90};
    vector<int> temperatures_4{89, 62, 70, 58, 47, 47, 46, 76, 100};
    Solution s;
    vector<int> result = s.dailyTemperatures(temperatures_1);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}