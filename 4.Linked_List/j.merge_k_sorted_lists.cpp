#include <vector>
#include <iostream>

/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
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
private:
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

public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        
        while (lists.size() > 1)
        {
            std::vector<ListNode*> mergedList {};
            int len {static_cast<int>(lists.size())};
            for (int i {0}; i < len; i+=2)
            {
                ListNode* l1 {lists[i]};
                ListNode* l2 {i == len-1 ? nullptr : lists[i+1]};
                mergedList.push_back(mergeTwoLists(l1, l2));
            }

            lists = mergedList;
        }

        return lists.size() > 0 ? lists[0] : nullptr;
    }
};

void PrintLinkedList(ListNode* head)
{
    ListNode* node {head};

    while (node != nullptr)
    {
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
    Solution solution {};

    // Example 1
    std::cout << "Example 1:\n";

    ListNode* list1 {new ListNode {1}};
    AddNode(list1, 4);
    AddNode(list1, 5);

    ListNode* list2 {new ListNode {1}};
    AddNode(list2, 3);
    AddNode(list2, 4);

    ListNode* list3 {new ListNode {2}};
    AddNode(list3, 6);

    std::vector<ListNode*> lists1 {list1, list2, list3};

    std::cout << "Input:\n";
    PrintLinkedList(list1);
    PrintLinkedList(list2);
    PrintLinkedList(list3);

    ListNode* result1 {solution.mergeKLists(lists1)};

    std::cout << "Output:\n";
    PrintLinkedList(result1);

    // Example 2
    std::cout << "\nExample 2:\n";

    std::vector<ListNode*> lists2 {};

    std::cout << "Input: []\n";

    ListNode* result2 {solution.mergeKLists(lists2)};

    std::cout << "Output: ";
    PrintLinkedList(result2);

    // Example 3
    std::cout << "\nExample 3:\n";

    std::vector<ListNode*> lists3 {nullptr};

    std::cout << "Input: [[]]\n";

    ListNode* result3 {solution.mergeKLists(lists3)};

    std::cout << "Output: ";
    PrintLinkedList(result3);

    return EXIT_SUCCESS;
}