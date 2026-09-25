#include <cstdlib>
#include <iostream>

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev {nullptr};
        ListNode* cur {head};
        
        while (cur != nullptr)
        {
            ListNode* next {cur->next};
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};

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

void PrintLinkedList(ListNode* head)
{
    ListNode* node {head};
    while (node != nullptr) {
        std::cout << node->val << " -> ";
        node = node->next;
    }
    std::cout << "null\n";
}

int main()
{
    Solution sln;

    ListNode* head1 {new ListNode {1}};
    AddNode(head1, 2);
    AddNode(head1, 3);
    AddNode(head1, 4);
    AddNode(head1, 5);
    std::cout << "Input : ";
    PrintLinkedList(head1);
    head1 = sln.reverseList(head1);
    std::cout << "Output : ";
    PrintLinkedList(head1);

    std::cout << "\n";
    ListNode* head2 {new ListNode {1}};
    AddNode(head2, 2);
    std::cout << "Input : ";
    PrintLinkedList(head2);
    head2 = sln.reverseList(head2);
    std::cout << "Output : ";
    PrintLinkedList(head2);

     std::cout << "\n";
    ListNode* head3 {new ListNode {}};
    std::cout << "Input : ";
    PrintLinkedList(head3);
    head3 = sln.reverseList(head3);
    std::cout << "Output : ";
    PrintLinkedList(head3);

    return EXIT_SUCCESS;
}