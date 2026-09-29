#include <cstdlib>
#include <unordered_map>
#include <iostream>

/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
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
    bool hasCycle(ListNode *head) {
        std::unordered_map<ListNode*,bool> hitMap {};

        ListNode* cur {head};
        bool cycleFound {false};
        while (cur != nullptr)
        {
            if (hitMap.count(cur) > 0)
            {
                cycleFound = true;
                break;
            }

            hitMap.try_emplace(cur,true);
            cur = cur->next;
        }

        return cycleFound;
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
    // [3,2,0,-4], pos = 1
    // tail (-4) points back to node containing 2

    ListNode* list1 {new ListNode {3}};

    AddNode(list1, 2);
    AddNode(list1, 0);
    AddNode(list1, -4);

    // Get the node containing 2
    ListNode* cycleNode {list1->next};

    // Get the tail
    ListNode* tail {list1};
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    // Create the cycle
    tail->next = cycleNode;

    std::cout << "Example 1\n";
    std::cout << "Input: [3,2,0,-4], pos = 1\n";
    std::cout << "Output: " << std::boolalpha
              << solution.hasCycle(list1) << "\n\n";


    // Example 2
    // [1,2], pos = 0
    // tail (2) points back to head (1)

    ListNode* list2 {new ListNode {1}};
    AddNode(list2, 2);

    tail = list2;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    tail->next = list2;

    std::cout << "Example 2\n";
    std::cout << "Input: [1,2], pos = 0\n";
    std::cout << "Output: " << solution.hasCycle(list2) << "\n\n";


    // Example 3
    // [1], pos = -1
    // No cycle

    ListNode* list3 {new ListNode {1}};

    std::cout << "Example 3\n";
    std::cout << "Input: [1], pos = -1\n";
    std::cout << "Output: " << solution.hasCycle(list3) << "\n";


    return EXIT_SUCCESS;
}