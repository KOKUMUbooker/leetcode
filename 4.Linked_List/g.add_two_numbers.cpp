#include <cstdlib>
#include <iostream>

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Example 4:
Input: l1 = [2,4,9], l2 = [5,6,4,9]
Output: [7,0,4,0,1]
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 {l1};
        ListNode* n2 {l2};

        int carry {0};
        ListNode* resHead {nullptr};
        ListNode* resTail {nullptr};
        while (n2 != nullptr || n1 != nullptr)
        {
            int sum {carry};

            if (n1 != nullptr)
            {
                sum += n1->val;
                n1 = n1->next;
            }

            if (n2 != nullptr)
            {
                sum += n2->val;
                n2 = n2->next;
            }

            carry = sum > 9 ? 1 : 0;
            ListNode* newNode {new ListNode(sum > 9 ? sum - 10 : sum )};
            if (resHead == nullptr)
                resHead = newNode;
            if (resTail != nullptr)
                resTail->next = newNode;

            resTail = newNode;
        }

        if (carry > 0) 
        {
            ListNode* newNode {new ListNode(carry)};
            resTail->next = newNode;
        }

        return resHead;
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
    // Input:  [2,4,3] + [5,6,4]
    // Output: [7,0,8]

    ListNode* l1 {new ListNode {2}};
    AddNode(l1, 4);
    AddNode(l1, 3);

    ListNode* l2 {new ListNode {5}};
    AddNode(l2, 6);
    AddNode(l2, 4);

    std::cout << "Example 1\n";

    std::cout << "Input l1: ";
    PrintLinkedList(l1);

    std::cout << "Input l2: ";
    PrintLinkedList(l2);

    ListNode* result1 {solution.addTwoNumbers(l1, l2)};

    std::cout << "Output:   ";
    PrintLinkedList(result1);

    std::cout << "\n";


    // Example 2
    // Input:  [0] + [0]
    // Output: [0]

    l1 = new ListNode {0};
    l2 = new ListNode {0};

    std::cout << "Example 2\n";

    std::cout << "Input l1: ";
    PrintLinkedList(l1);

    std::cout << "Input l2: ";
    PrintLinkedList(l2);

    ListNode* result2 {solution.addTwoNumbers(l1, l2)};

    std::cout << "Output:   ";
    PrintLinkedList(result2);

    std::cout << "\n";


    // Example 3
    // Input:  [9,9,9,9,9,9,9] + [9,9,9,9]
    // Output: [8,9,9,9,0,0,0,1]

    l1 = new ListNode {9};
    AddNode(l1, 9);
    AddNode(l1, 9);
    AddNode(l1, 9);
    AddNode(l1, 9);
    AddNode(l1, 9);
    AddNode(l1, 9);

    l2 = new ListNode {9};
    AddNode(l2, 9);
    AddNode(l2, 9);
    AddNode(l2, 9);

    std::cout << "Example 3\n";

    std::cout << "Input l1: ";
    PrintLinkedList(l1);

    std::cout << "Input l2: ";
    PrintLinkedList(l2);

    ListNode* result3 {solution.addTwoNumbers(l1, l2)};

    std::cout << "Output:   ";
    PrintLinkedList(result3);

    std::cout << "\n";


    // Example 4
    // Input:  [2,4,9] + [5,6,4,9]
    // Output: [7,0,4,0,1]

    l1 = new ListNode {2};
    AddNode(l1, 4);
    AddNode(l1, 9);

    l2 = new ListNode {5};
    AddNode(l2, 6);
    AddNode(l2, 4);
    AddNode(l2, 9);

    std::cout << "Example 4\n";

    std::cout << "Input l1: ";
    PrintLinkedList(l1);

    std::cout << "Input l2: ";
    PrintLinkedList(l2);

    ListNode* result4 {solution.addTwoNumbers(l1, l2)};

    std::cout << "Output:   ";
    PrintLinkedList(result4);


    return EXIT_SUCCESS;
}