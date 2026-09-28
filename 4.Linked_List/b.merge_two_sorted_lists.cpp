#include <cstdlib>
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
        ListNode dummy;
        ListNode* tail {&dummy};

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        // One list may still have nodes remaining.
        if (list1 != nullptr)
            tail->next = list1;
        else
            tail->next = list2;

        return dummy.next;
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