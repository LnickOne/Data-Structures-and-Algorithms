/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/FortPu/)
题目描述
设计一个支持在平均 O(1) 时间复杂度下执行以下操作的数据结构:
- insert(val): 当元素 val 不存在时返回 true, 并向集合中插入该项, 否则返回 false。
- remove(val): 当元素 val 存在时返回 true, 并从集合中移除该项, 否则返回 false。
- getRandom: 随机返回现有集合中的一项, 每个元素有相同概率被返回。
题目样例
示例1
- 输入: ["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]
          [[],[1],[2],[2],[],[1],[2],[]]
- 输出: [null,true,false,true,2,true,false,2]
题目思考
1. 需要用到哪些数据结构?
解决方案
思路
- 用 vector<int> 存储元素 (支持 O(1) 随机访问), 用 unordered_map<int,int> 存储值到下标的映射
- insert: 查 map 判断是否存在, 不存在则尾部追加并记录下标
- remove: 查 map 得到下标, 将末尾元素移到该位置并更新 map, 然后删除末尾
- getRandom: 用 rand() % size 取随机下标
复杂度
- 时间复杂度 O(1): 每种操作都只需要常数时间
- 空间复杂度 O(N): 数组和哈希表各需要 O(N) 空间
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedSet
{
    vector<int> arr;
    unordered_map<int, int> v2i;
public:
    bool insert(int val)
    {
        if (v2i.count(val)) return false;
        v2i[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    bool remove(int val)
    {
        if (!v2i.count(val)) return false;
        int i = v2i[val];
        int last = arr.back();
        arr[i] = last;
        v2i[last] = i;
        arr.pop_back();
        v2i.erase(val);
        return true;
    }
    int getRandom()
    {
        return arr[rand() % arr.size()];
    }
};

int main()
{
    RandomizedSet rs;
    cout << boolalpha;
    cout << rs.insert(1) << endl;   // true
    cout << rs.remove(2) << endl;   // false
    cout << rs.insert(2) << endl;   // true
    cout << rs.getRandom() << endl; // 1 或 2
    cout << rs.remove(1) << endl;   // true
    cout << rs.insert(2) << endl;   // false
    cout << rs.getRandom() << endl; // 2
    return 0;
}
