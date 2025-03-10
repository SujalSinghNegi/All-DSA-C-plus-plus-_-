#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    // Sample array; modify as needed.
    vector<int> arr = {2,4,3,5,1};

    // --- Finding numbers greater than each element ---
    // Left side: We iterate from left to right, maintaining a multiset of already seen elements.
    cout << "Left side numbers greater than each element:\n";
    multiset<int> leftSet;
    for (size_t i = 0; i < arr.size(); i++) {
        // In the leftSet, all elements are stored in sorted order.
        // Using upper_bound(arr[i]) gives the first element strictly greater than arr[i].
        auto it = leftSet.upper_bound(arr[i]);
        cout << "For " << arr[i] << ": ";
        for (; it != leftSet.end(); ++it) {
            cout << *it << " ";
        }
        cout << "\n";
        leftSet.insert(arr[i]);
    }

    // Right side: We pre-load all elements into a multiset and remove the current element as we iterate.
    cout << "\nRight side numbers greater than each element:\n";
    multiset<int> rightSet(arr.begin(), arr.end());
    for (size_t i = 0; i < arr.size(); i++) {
        // Remove the current element from rightSet so only elements to its right remain
        auto itRemove = rightSet.find(arr[i]);
        if (itRemove != rightSet.end()) {
            rightSet.erase(itRemove);
        }
        auto it = rightSet.upper_bound(arr[i]);
        cout << "For " << arr[i] << ": ";
        for (; it != rightSet.end(); ++it) {
            cout << *it << " ";
        }
        cout << "\n";
    }

    // --- Finding numbers smaller than each element ---
    // Left side: We again build the leftSet as we iterate.
    cout << "\nLeft side numbers smaller than each element:\n";
    leftSet.clear();
    for (size_t i = 0; i < arr.size(); i++) {
        // lower_bound(arr[i]) returns the first element that is not less than arr[i];
        // iterating from begin() to that iterator gives all elements smaller than arr[i]
        auto it = leftSet.lower_bound(arr[i]);
        cout << "For " << arr[i] << ": ";
        for (auto iter = leftSet.begin(); iter != it; ++iter) {
            cout << *iter << " ";
        }
        cout << "\n";
        leftSet.insert(arr[i]);
    }

    // Right side: Similarly, we pre-load all elements and remove the current one as we move.
    cout << "\nRight side numbers smaller than each element:\n";
    rightSet.clear();
    rightSet.insert(arr.begin(), arr.end());
    for (size_t i = 0; i < arr.size(); i++) {
        auto itRemove = rightSet.find(arr[i]);
        if (itRemove != rightSet.end()) {
            rightSet.erase(itRemove);
        }
        auto it = rightSet.lower_bound(arr[i]);
        cout << "For " << arr[i] << ": ";
        for (auto iter = rightSet.begin(); iter != it; ++iter) {
            cout << *iter << " ";
        }
        cout << "\n";
    }

    return 0;
}
