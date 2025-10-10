#
# @lc app=leetcode.cn id=2379 lang=python3
#
# [2379] 得到 K 个黑块的最少涂色次数
#


# @lc code=start
class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        result = 0  # 存储最终结果，即最少涂色次数
        count_b = 0  # 记录当前窗口中黑色块（'B'）的数量
        count_w = 0  # 记录当前窗口中白色块（'W'）的数量
        # 计算初始窗口（前k个字符）中的黑色块数量
        for i in range(0, k):
            if blocks[i] == "B":
                count_b += 1
        # 如果初始窗口中'B'的数量已经等于k，说明这个窗口已经是全黑的，无需涂色，直接返回0
        if count_b == k:
            return 0
        count_w = k - count_b  # 初始化count_w为初始窗口中需要涂色的白色块数量
        result = count_w  # result初始化为count_w，作为当前的最少涂色次数

        # 滑动窗口遍历剩余字符
        for i in range(k, len(blocks)):
            if blocks[i] == "B":
                count_b += 1  # 新进入窗口的字符是'B'，count_b加1
            if blocks[i - k] == "B":
                count_b -= 1  # 离开窗口的字符是'B'，count_b减1

            # 如果发现某个窗口中count_b等于k，说明该窗口已经是全黑的，直接返回0
            if count_b == k:
                return 0
            count_w = k - count_b  # 更新count_w为当前窗口中需要涂色的白色块数量
            result = min(result, count_w)  # 更新result为所有窗口中需要涂色的最少次数

        return result  # 返回记录的最少涂色次数result


# @lc code=end
