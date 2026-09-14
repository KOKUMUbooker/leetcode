#include <stack>
#include <vector>
#include <iostream>

// Given an array of integers temperatures represents the daily temperatures, 
// return an array answer such that answer[i] is the number of days you have 
// to wait after the ith day to get a warmer temperature. 
// If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// Example 2:
// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]

// Example 3:
// Input: temperatures = [30,60,90]
// Output: [1,1,0]

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int len {static_cast<int>(temperatures.size())};
        std::vector<int> res (len,0);
        std::stack<int> idxStack;

        for (int i {len-1}; i >= 0; --i)
        {
            while (!idxStack.empty() && temperatures[idxStack.top()] <= temperatures[i]) {
                idxStack.pop();
            }

            if (!idxStack.empty())
                res[i] = idxStack.top() - i;

            idxStack.push(i);
        }

        return res;
    }
};


void printVector(const std::vector<int>& vec)
{
    int len {static_cast<int>(vec.size())};
    std::cout << "[";
    for (int i {0}; i < len; ++i)
    {
        std::cout << vec[i];
        if (i != (len-1))
            std::cout << ", ";
    }
    std::cout << "]\n";
}

int main()
{
    Solution sln;
    std::vector<int> tst1 {73,74,75,71,69,72,76,73};
    printVector(sln.dailyTemperatures(tst1));

    std::vector<int> tst2 {30,40,50,60};
    printVector(sln.dailyTemperatures(tst2));

    std::vector<int> tst3 {30,60,90};
    printVector(sln.dailyTemperatures(tst3));

    return EXIT_SUCCESS;
}