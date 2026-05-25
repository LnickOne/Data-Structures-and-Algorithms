"""

"""


class Test:

    def test(self):
        # Create HashTable by Array
        hashTable = [''] * 4
        # Create HashTable by Dictionary
        mapping = {}

        # Add element
        # Time Complexity:0(1)
        hashTable[1] = 'hanmeimei'
        hashTable[2] = 'lihua'
        hashTable[3] = 'siyangyuan'
        mapping[1] = 'hanmeimei'
        mapping[2] = 'lihua'
        mapping[3] = 'siyangyuan'

        # Update element
        # Time Complexity:0(1)
        hashTable[1] = 'bishi'
        mapping[1] = 'bishi'

        # Remove element
        # Time Complexity:0(1)
        hashTable[1] = mapping.pop(1)
        # del mapping[1]

        # Get Value
        # Time Complexity:0(1)hashTable[3]mapping[3]
        # Check Key# Time Complexity:0(1)# hashTable No
        3 in mapping

        # Length
        # Time Complexity: 0(1)
        # hashTable No
        len(mapping)

        # is Empty
        # Time Complexity:0(1)
        # hashTable No
        len(mapping) == 0


if __name__ == '__main__':
    test = Test()
    test.test()
