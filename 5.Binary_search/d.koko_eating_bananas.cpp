
#include <vector>
#include <algorithm>

class Solution {
private:
    int RoundUpDivision(int a, int b)
    {
        return (a+b-1) / b;
    }

public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int minSpeed {1};

        int maxPile {
            *std::max_element(piles.begin(), piles.end())
        };

        int low {1};
        int high {maxPile};

        while (low <= high)
        {
            int mid {low + (high - low) / 2};
            long long totalHrs {0};

            for (int i {0}; i < static_cast<int>(piles.size()); ++i)
            {
                totalHrs += RoundUpDivision(piles[i], mid);

                if (totalHrs > h)
                    break;
            }

            if (totalHrs <= h)
            {
                minSpeed = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return minSpeed;
    }
};
