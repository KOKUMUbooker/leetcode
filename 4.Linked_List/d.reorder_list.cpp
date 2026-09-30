#include <cstdlib>
#include <vector>
#include <iostream>

/*
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
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
    void reorderList(ListNode* head) {
        std::vector<ListNode*> nodeVec {};

        ListNode* cur {head};
        while (cur != nullptr)
        {
            nodeVec.push_back(cur);
            cur = cur->next;
        }

        int len {static_cast<int>(nodeVec.size())};
        if (len <= 2)
            return;

        std::vector<ListNode*> resVec {};
        for (int i {0}; i < len/2; ++i)
        {
            ListNode* cur {nodeVec[i]};
            ListNode* target {nodeVec[(len-1)-i]};
            resVec.push_back(cur);
            resVec.push_back(target);
        }

        if (len % 2 != 0)
            resVec.push_back(nodeVec[len/2]);

        for (int i {0}; i < len; ++i)
        {
            if (i != len-1)
                resVec[i]->next = resVec[i+1];
            else 
                resVec[i]->next = nullptr;
        }
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
    // Input:  [1,2,3,4]
    // Output: [1,4,2,3]

    ListNode* list1 {new ListNode {1}};

    AddNode(list1, 2);
    AddNode(list1, 3);
    AddNode(list1, 4);

    std::cout << "Example 1\n";

    std::cout << "Input:  ";
    PrintLinkedList(list1);

    solution.reorderList(list1);

    std::cout << "Output: ";
    PrintLinkedList(list1);

    std::cout << "\n";


    // Example 2
    // Input:  [1,2,3,4,5]
    // Output: [1,5,2,4,3]

    ListNode* list2 {new ListNode {1}};

    AddNode(list2, 2);
    AddNode(list2, 3);
    AddNode(list2, 4);
    AddNode(list2, 5);

    std::cout << "Example 2\n";

    std::cout << "Input:  ";
    PrintLinkedList(list2);

    solution.reorderList(list2);

    std::cout << "Output: ";
    PrintLinkedList(list2);


    return EXIT_SUCCESS;
}