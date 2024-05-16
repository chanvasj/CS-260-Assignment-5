#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class SortedArrayList {
private:
    std::vector<int> array;

public:
    void insert(int value) {
        auto it = std::lower_bound(array.begin(), array.end(), value);
        array.insert(it, value);
    }

    bool search(int value) {
        return std::binary_search(array.begin(), array.end(), value);
    }
};

void testArrayList() {
    SortedArrayList list;
    
    // Test insert function in random order 
    list.insert(3);
    list.insert(2);
    list.insert(4);
    list.insert(1);
    std::cout << "Test 1: " << (list.search(4) ? "Passed" : "Failed") << std::endl;
    
    // Test search function
    assert(list.search(1));
    assert(list.search(2));
    assert(list.search(3));
    assert(list.search(4));

    std::cout << "Search function tests passed successfully. " << std::endl;

}

int main() {
    testArrayList();

    return 0;
}