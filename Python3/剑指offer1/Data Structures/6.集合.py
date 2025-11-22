class Test:

    def test(self):
        # Create Set
        s = set()
        # Add element
        # Time Complexity:0(1)
        s.add(10)
        s.add(3)
        s.add(5)
        s.add(2)
        s.add(2)
        # {2,10,3,5}
        print(s)

        # Search Element
        # Time Complexity:o(1)
        2 in s

        # Delete Element
        # Time Complexity:0(1)
        s.remove(2)

        # {10,3,5}
        print(s)

        # Size
        # TimeComplexity:0(1)
        len(s)


if __name__ == '__main__':
    test = Test()
    test.test()
