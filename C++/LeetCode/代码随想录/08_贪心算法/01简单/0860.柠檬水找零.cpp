#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。
你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
注意，一开始你手头没有任何零钱。
给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。
如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
示例 1：
输入：bills = [5,5,5,10,20]
输出：true
解释：
前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
由于所有客户都得到了正确的找零，所以我们输出 true。
示例 2：
输入：bills = [5,5,10,10,20]
输出：false
解释
前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
由于不是每位顾客都得到了正确的找零，所以答案是 false。
*/
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for (int bill : bills)
        {
            if (bill == 5) // 情况一
                five++;
            if (bill == 10) // 情况二
            {
                if (five <= 0)
                    return false;
                ten++;
                five--;
            }
            if (bill == 20) // 情况三
            {
                if (five > 0 && ten > 0) // 贪心优先消耗10美元，因为5美元的找零用处更大，能多留着就多留着
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> v = {5, 5, 5, 10, 20};
    Solution s;
    cout << s.lemonadeChange(v);
    return 0;
}