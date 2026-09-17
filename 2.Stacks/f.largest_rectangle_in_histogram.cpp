#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int maxArea {0};
        // <index,height>
        std::stack<std::pair<int,int>> stk;
        int len {static_cast<int>(heights.size())};
        for (int i {0}; i < len; ++i)
        {
            int curHeight {heights[i]};
            int start {i};
            // As long as height at [i] can extend backwards, do this
            while (!stk.empty() && heights[i] < stk.top().second)
            {
                int h {stk.top().second}, j {stk.top().first};
                int w {i - j};
                maxArea = std::max(maxArea, h*w);

                // pop top element
                stk.pop();
                start = j; // move start backwards
            }

            stk.push({start, curHeight});
        }

        // Stack might still not be empty
        while(!stk.empty())
        {
            int h {stk.top().second}, j {stk.top().first};
            int w {len - j};
            maxArea = std::max(maxArea, h*w);

            // pop top element
            stk.pop();
        }

        return maxArea;
    }
};

int main()
{
    Solution sln;
    std::vector<int> tst1 {2, 1, 5, 6, 2, 3};
    std::cout << sln.largestRectangleArea(tst1) << "\n";

    std::vector<int> tst2 {2, 4};
    std::cout << sln.largestRectangleArea(tst2) << "\n";

    return EXIT_SUCCESS;
}