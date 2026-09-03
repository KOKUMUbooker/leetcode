#include <iostream>
#include <string>
#include <vector>

class Solution {
private:
    // Use a non-printable character
    char delimiter {127}; // The Delete control character
    char nullChar {'\0'}; // Null character to communicate that vector is empty

    std::vector<std::string> splitString(const std::string& input, char delimiter)
    {
        if (input.size() == 0)
            return std::vector<std::string>{""};

        if (input.size() == 1 && input == std::string(1, nullChar))
            return std::vector<std::string>{};

        std::vector<std::string> tokens {};
        std::string tkn {""};
        int len {static_cast<int>(input.size())};
        for (int i {0}; i < len; ++i)
        {
            if (input[i] == delimiter)
            {
                tokens.push_back(tkn);
                tkn = "";
                // Also account for if this is the last index - means an empty "" to the right
                if (i == len-1)
                    tokens.push_back("");

                continue;
            }
            tkn += input[i];
        }

        if (tkn.size() != 0)
            tokens.push_back(tkn);

        return tokens;
    }
public:

    std::string encode(std::vector<std::string>& strs) {
        int len {static_cast<int>(strs.size())};
        if (len == 0)
            return std::string(1, nullChar);

        std::string res {""};
        for (int i {0}; i < len; ++i)
        {
            res += strs[i];
            if (i != len-1)
                res += delimiter;
        }
        return res;
    }

    std::vector<std::string> decode(std::string s) {
        return splitString(s,delimiter);
    }
};


void printVector(const std::vector<std::string>& vec)
{
    int len {static_cast<int>(vec.size())};
    std::cout << "[";
    for (int i {0}; i < len; ++i)
    {
        std::cout << '\"' << vec[i] << '\"';
        if (i != (len-1))
            std::cout << ", ";
    }
    std::cout << "]\n";
}

int main()
{
    Solution sln;
    std::vector<std::string> tst1 {"",""};
    std::string tst1Encoded {sln.encode(tst1)};
    tst1 = sln.decode(tst1Encoded);
    printVector(tst1);

    std::vector<std::string> tst2 {"","", ""};
    std::string tst2Encoded {sln.encode(tst2)};
    tst2 = sln.decode(tst2Encoded);
    printVector(tst2);

    std::vector<std::string> tst3 {};
    std::string tst3Encoded {sln.encode(tst3)};
    tst3 = sln.decode(tst3Encoded);
    printVector(tst3);

    return EXIT_SUCCESS;
}