#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class RandomizedSet
{
private:
    // Data Members
    unordered_map<int, int> mpp;
    vector<int> arr;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        // if value is already present, return false.
        if (mpp.find(val) != mpp.end())
        {
            return false;
        }

        // if value is not present, insert it and return true.
        arr.push_back(val);
        mpp[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        auto it = mpp.find(val);
        // if value is not present, return false.
        if (it == mpp.end())
        {
            return false;
        }

        // if value is present,then remove it and return true.

        int idx = it->second;  // index of value, which we have to remove.
        arr[idx] = arr.back(); // at index of value which we have to delete, replace the value with last value present at array.
        arr.pop_back();        // pop the last value.

        mpp[arr[idx]] = idx; // update the index of last value in map.
        mpp.erase(val);      // erase value which we have to delete from map.
        return true;
    }

    int getRandom()
    {
        int n = arr.size();
        int randomElement = arr[rand() % n];
        return randomElement;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */


int main()
{
    RandomizedSet *obj = new RandomizedSet();

    int val = 5;
    bool param_1 = obj->insert(val);
    bool param_2 = obj->remove(val);
    int param_3 = obj->getRandom();

}