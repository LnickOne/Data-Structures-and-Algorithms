import heapq


class Test:
    def test(self):
        # Create minheap
        minheap = []
        heapq.heapify(minheap)  # 将列表堆化
        # Add element
        heapq.heappush(minheap, 10)
        heapq.heappush(minheap, 8)
        heapq.heappush(minheap, 9)
        heapq.heappush(minheap, 2)
        heapq.heappush(minheap, 1)
        heapq.heappush(minheap, 11)
        # [1，2，9，10，8，11]
        print(minheap)

        # peek
        # 1
        print(minheap[0])

        # Delete
        heapq.heappop(minheap)
        # Size
        len(minheap)

        # Iteration
        while len(minheap) != 0:
            print(heapq.heappop(minheap))


if __name__ == "__main__":
    test = Test()
    test.test()
