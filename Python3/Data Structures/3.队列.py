from collections import deque
"""
数据结构队列性质
有单端队列和双端队列
一般使用单端队列 先进先出
进来[1,2,3]
出去[1,2,3]
"""

class Test:
    def test(self):
        # Create a queue
        queue = deque()
        # Add element
        # Time Complexity:0(1)
        queue.append(1)
        queue.append(2)
        queue.append(3)
        # [1,2,3]
        print(queue)

        # Get the head of the queue
        # Time Complexity:0(1)
        temp1 = queue[0]
        # 1
        print(temp1)
        # Remove the head of the queue
        # Time Complexity:0(1)
        temp2 = queue.popleft()  # 先进来的在左边，后进来的是right,考虑单端队列所以先进先出只删除poplef
        # 1
        temp3 = queue.pop() #直接使用.pop() 等于删除队列右边的元素
        print("temp:"+str(temp3))
        # [2,3]
        print(queue)

        # Queue is empty?# Time Complexity:0(1)
        len(queue) == 0
        # The length of queue
        # Time Complexity:0(1)
        len(queue)
        # Time Complexity:0(N)
        while len(queue) != 0:
            temp = queue.popleft()
            print(temp)


if __name__ == '__main__':
    test = Test()
    test.test()
