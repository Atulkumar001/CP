Imagine managing a database of dashboard of some firm with the following operations:

Insert: Add a new user to the server named x, with some value.

Sum: Sum of all the value of user.

Erase Entries: Remove particular user.

Get Max: Retrieve the max value of the user.

Get Distinct: No. of users with distinct value.

Algorithmic Explanation:

Insert Operation:

When inserting a new user with value x:
Increment the current sum by x.
Update the map mp to keep track of the frequency of each value.
Remove Entries Operation:

When removing a user with value x:
Decrement the current sum by x.
Decrement the frequency of x in the map mp.
If the frequency becomes 0, remove the entry for x from the map.
Sum Operation:

Simply return the current sum stored in the variable cur_sum. This operation runs in constant time O(1).
Get Max Operation:

Find the maximum value in the map mp by accessing the last entry (since it's sorted in ascending order by default).
Get Distinct Operation:

Return the size of the map mp, which represents the number of distinct users.
Code:
..................................................................................................................................................................
#include <iostream>
#include <map>

using namespace std;

struct bag {
    int cur_sum = 0;
    map<int, int> mp;

    void insert(int x)    // 0(logn)
    {
        cur_sum += x;
        mp[x]++;
    }

    void remove(int x)     // 0(logn)
    {
        cur_sum -= x;
        mp[x]--;
        if (mp[x] == 0) {
            mp.erase(x);
        }
    }

    int sum()    // 0(1)
    {
        return cur_sum;
    }

    int getmax()   // 0(1)
    {
        auto it = mp.end();
        it--;
        return it->first;
    }

    int getdistinct()   // 0(1)
    {
        return mp.size();
    }
};

int main() {
    bag b;
    b.insert(5);
    b.insert(7);
    b.insert(5);
    cout << "Sum: " << b.sum() << endl; // Output: Sum: 17
    cout << "Max: " << b.getmax() << endl; // Output: Max: 7
    cout << "Distinct: " << b.getdistinct() << endl; // Output: Distinct: 2
    b.remove(5);
    cout << "Sum after removing 5: " << b.sum() << endl; // Output: Sum after removing 5: 7
    return 0;
}
