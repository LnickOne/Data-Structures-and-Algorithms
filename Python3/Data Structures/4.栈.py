"""
栈是先进后出
进来[1,2,3]
出去[3,2,1]
"""


class Test:
    def test(self):
        # Create a stack,python直接写一个列表
        stack = []

        # Add element
        # Time complexity:0(1)
        stack.append(1)
        stack.append(2)
        stack.append(3)
        # [1,2,3]
        print(stack)
        # Get the top of stack 获取栈顶元素，从后往前读
        # Time complexity:0(1)
        stack[-1]

        # Remove the top of stack 删除栈顶元素,从后往前读
        # Time complexity:0(1)
        temp = stack.pop()
        # 3
        print(temp)
        print(stack)

        # Get stack length
        # Time complexity:0(1)
        len(stack)
        # Stack is empty? 看栈的长度是否为0即可
        # Time complexity:0(1)
        len(stack) == 0

        # Iterate Stack 栈的遍历，边删除边遍历
        # Time complexity:0(N)
        while len(stack) > 0:  # 判断栈里是否有元素
            temp = stack.pop()
            print(temp)


if __name__ == '__main__':
    test = Test()
    test.test()
