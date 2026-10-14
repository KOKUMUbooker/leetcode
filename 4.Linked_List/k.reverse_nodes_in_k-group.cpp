#include <cstdlib>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void PrintLinkedList(ListNode* head);
    
class Solution {
private:
    ListNode* revGroup(ListNode* head, int k)
    {
        //std::cout << "revGroup head : " << head->val << "\n";
        ListNode* cur {head};
        ListNode* tail {nullptr};
        int count {0};
        while (cur != nullptr)
        {
            ++count;
            ListNode* next {cur->next};
            cur->next = tail;
            tail = cur;
            cur = next;

            if (count == k)
                break;
        }

        return tail; // Will be the starting point of that group
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* resHead {nullptr};

        ListNode* cur {head};
        ListNode* start {head};
        ListNode* prevBreakPoint {nullptr};
        int count {0};

        while (cur != nullptr)
        {
            ++count;
            
            if (count == k)
            {
                ListNode* nextStart {cur->next};
                ListNode* groupStart {revGroup(start,k)};
                ListNode* curBreakpoint {start}; // After reversing, "start" will be to the right edge and its next value will be nullptr
                curBreakpoint->next = nextStart;
                // std::cout << curBreakpoint->val << "\n"; 

                // Set resHead once
                if (resHead == nullptr)
                {
                    //std::cout << "Setting res head to : " << start->val << "\n";
                    resHead = groupStart;
                }
                
                if (prevBreakPoint != nullptr)
                    prevBreakPoint->next = cur;
                
                cur = nextStart;
                start = nextStart;
                count = 0;
                prevBreakPoint = curBreakpoint;
            }
            else
                cur = cur->next;
        }

        return resHead;
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


int main()
{
    Solution sln;

    ListNode* head1 {new ListNode(1)};
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    std::cout << "Example 1 : \n";
    PrintLinkedList(head1);
    ListNode* revHead1 = sln.reverseKGroup(head1, 2);
    PrintLinkedList(revHead1);

    ListNode* head2 {new ListNode(1)};
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    std::cout << "\nExample 2 : \n";
    PrintLinkedList(head2);
    ListNode* revHead2 = sln.reverseKGroup(head2, 3);
    PrintLinkedList(revHead2);

    return EXIT_SUCCESS;
}