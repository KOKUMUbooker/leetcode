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
        
        // In order to get the largest number which will serve as the max number koko
        // can eat per hour if they should could eat all piles
        std::sort(piles.begin(), piles.end()); 
        int len {static_cast<int>(piles.size())};
        
        // 1 to piles[len-1] are the possibles speeds that koko will have to 
        // eat at before the h hours elapse
        for (int speed {piles[len-1]}; speed >= 1 ; --speed) 
        {
            long long totalHrs {0};
            for (int i {0}; i < len; ++i)
                totalHrs += RoundUpDivision(piles[i],speed);

            if (totalHrs > h)
                break;
            else
                minSpeed = speed;
        }

        return minSpeed;
    }
};