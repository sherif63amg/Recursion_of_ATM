#include <iostream>

using namespace std;

bool hasCombination(const int nums[], int target, int index, int size) {
    // Base cases:
    if (target == 0) {
        return true; // Found a combination
    }
    if (index >= size || target < 0) {
        return false; // No more numbers or target is negative
    }

    // Recursive cases:
    // Include the current number in the combination
    bool include = hasCombination(nums, target - nums[index], index + 1, size);
    // Exclude the current number from the combination
    bool exclude = hasCombination(nums, target, index + 1, size);

    return include || exclude;
}

int main() {
    int numbers[] = { 2, 3, 100, 2 };
    int targetSum = 10;
    int size = sizeof(numbers) / sizeof(numbers[0]);

    bool result = hasCombination(numbers, targetSum, 0, size);

    if (result) {
        cout << "A combination exists." << endl;
    }
    else {
        cout << "No combination exists." << endl;
    }

    return 0;
}