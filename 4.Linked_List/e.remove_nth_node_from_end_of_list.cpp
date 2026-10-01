#include <cstdlib>
#include <iostream>
#include <vector>

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode*> nodeVec {};
        ListNode* cur {head};
        while (cur != nullptr)
        {
            nodeVec.push_back(cur);
            cur = cur->next;
        }

        int len {static_cast<int>(nodeVec.size())};
        std::vector<ListNode*> resVec {};
        int idxToSkip {len - n};
        for (int i {0}; i < len; ++i)
        {
            if (i == idxToSkip)
            {
                delete nodeVec[i];
                continue;
            }
            resVec.push_back(nodeVec[i]);
        }
        
        // Update pointers
        len = {static_cast<int>(resVec.size())};
        for (int i {0}; i < len-1; ++i)
        {
            resVec[i]->next = resVec[i+1];
        }
        if (len > 0)
            resVec[len-1]->next = nullptr;

        return len > 0 ? resVec[0] : nullptr;
    }
};

void PrintLinkedList(ListNode* head)
{
    ListNode* node {head};
    while (node != nullptr) {
        std::cout << node->val << " -> ";
        node = node->next;
    }
    std::cout << "null\n";
}

void AddNode(ListNode* head, int val)
{
    ListNode* node {head};
    ListNode* prev {nullptr};

    while (node != nullptr)
    {
        prev = node;
        node = node->next;
    }

    prev->next = new ListNode {val};
}


int main()
{
    Solution solution;
    // Example 1
    // Input:  [1,2,3,4,5], n = 2
    // Output: [1,2,3,5]

    ListNode* list1 {new ListNode {1}};

    AddNode(list1, 2);
    AddNode(list1, 3);
    AddNode(list1, 4);
    AddNode(list1, 5);

    std::cout << "Example 1\n";

    std::cout << "Input:  ";
    PrintLinkedList(list1);

    std::cout << "n: 2\n";

    list1 = solution.removeNthFromEnd(list1, 2);

    std::cout << "Output: ";
    PrintLinkedList(list1);

    std::cout << "\n";


    // Example 2
    // Input:  [1], n = 1
    // Output: []

    ListNode* list2 {new ListNode {1}};

    std::cout << "Example 2\n";

    std::cout << "Input:  ";
    PrintLinkedList(list2);

    std::cout << "n: 1\n";

    list2 = solution.removeNthFromEnd(list2, 1);

    std::cout << "Output: ";
    PrintLinkedList(list2);

    std::cout << "\n";


    // Example 3
    // Input:  [1,2], n = 1
    // Output: [1]

    ListNode* list3 {new ListNode {1}};

    AddNode(list3, 2);

    std::cout << "Example 3\n";

    std::cout << "Input:  ";
    PrintLinkedList(list3);

    std::cout << "n: 1\n";

    list3 = solution.removeNthFromEnd(list3, 1);

    std::cout << "Output: ";
    PrintLinkedList(list3);


    return EXIT_SUCCESS;
}