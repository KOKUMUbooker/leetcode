#include <vector>
#include <algorithm>
#include <iostream>

/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur {list1};
        std::vector<ListNode*> nodes {};

        while (cur != nullptr)
        {
            nodes.push_back(cur);
            cur = cur->next;
        }

        cur = list2;
        while (cur != nullptr)
        {
            nodes.push_back(cur);
            cur = cur->next;
        }

        int len {static_cast<int>(nodes.size())};
        if (len == 0)
            return nullptr;

        std::sort(nodes.begin(), nodes.end(), [](auto a, auto b) {
            return a->val < b->val;
        });

        // Update the pointers
        (nodes[len-1])->next = nullptr;
        for (int i {0}; i < len-1; ++i)
            (nodes[i])->next = nodes[i+1];

        return nodes[0];
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
    ListNode* list1 {new ListNode {1, new ListNode {2, new ListNode {4}}}};
    ListNode* list2 {new ListNode {1, new ListNode {3, new ListNode {4}}}};

    std::cout << "Example 1\n";
    std::cout << "Input:  list1 = ";
    PrintLinkedList(list1);
    std::cout << "        list2 = ";
    PrintLinkedList(list2);

    ListNode* result {solution.mergeTwoLists(list1, list2)};

    std::cout << "Output: ";
    PrintLinkedList(result);

    std::cout << "\n";


    // Example 2
    list1 = nullptr;
    list2 = nullptr;

    std::cout << "Example 2\n";
    std::cout << "Input:  list1 = ";
    PrintLinkedList(list1);
    std::cout << "        list2 = ";
    PrintLinkedList(list2);

    result = solution.mergeTwoLists(list1, list2);

    std::cout << "Output: ";
    PrintLinkedList(result);

    std::cout << "\n";


    // Example 3
    list1 = nullptr;
    list2 = new ListNode {0};

    std::cout << "Example 3\n";
    std::cout << "Input:  list1 = ";
    PrintLinkedList(list1);
    std::cout << "        list2 = ";
    PrintLinkedList(list2);

    result = solution.mergeTwoLists(list1, list2);

    std::cout << "Output: ";
    PrintLinkedList(result);


    return EXIT_SUCCESS;
}