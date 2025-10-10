class ArrayTest:
    def test(self):
        # 创建一个数组
        Array = []

        # 添加元素
        # Time Complexity: 0(1)
        Array.append(1)
        Array.append(2)
        Array.append(3)
        # [1,2,3]
        print(Array)

        # 插入元素
        # Time Complexity: 0(N)
        Array.insert(2, 99)
        # [1,2,99,3]
        print(Array)

        # Access element
        # Time Complexity:0(1)
        temp = Array[2]
        # 99
        print(temp)

        # Update element
        # Time complexity:O(1)
        Array[2] = 88
        # [1,2,88,3]
        print(Array)

        # Remove element
        # Time Complexity:O(N)
        Array.remove(88)
        # [1,2,3]
        print(Array)
        Array.pop(1)
        # [1,3]
        print(Array)
        # Time Complexity: 0(1)
        Array.pop()
        print(Array)

        Array = [1, 2, 3]
        # Get array size
        size = len(Array)
        # 3
        print(size)

        # Iterate array
        # Time complexity:0(N)
        for i in Array:
            print(i)
        for index, element in enumerate(Array):
            print("Index at ", index, "is :", element)
        for i in range(0, len(Array)):
            print("i:", i, " element:", Array[i])

        # Find an element
        # Time complexity:O(N)
        index = Array.index(2)
        # 1
        print(index)

        # Sort an array
        # Time Complexity: 0(NlogN)
        # From small to big
        Array = [3, 1, 2]
        Array.sort()
        # [1,2,3]
        print(Array)
        # From big to small
        Array.sort(reverse=True)
        # [3,2,1]
        print(Array)


if __name__ == '__main__':
    array = ArrayTest()
    array.test()
