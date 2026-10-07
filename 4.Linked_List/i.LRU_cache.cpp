#include <cstdlib>
#include <unordered_map>
#include <iostream>

/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:
1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/

class Node {
public:
    int val {0};
    Node* next {nullptr};
    Node* prev {nullptr};
    Node() {};
    Node(int v) : val {v} {};
    Node(int v, Node* pr) : val {v}, prev {pr} {};
    Node(int v, Node* pr, Node* nx) : val {v}, prev {pr}, next {nx} {};
};

class LRUCache {
private:
    int cap {0};
    int size {0};
    Node* start {nullptr};
    Node* end {nullptr};
    std::unordered_map<int,Node*> nMap {};

    inline void MoveTargetCloseToStart(Node* target)
    {
        // Move it closer to start
        // i) Update tar prev and next
        Node* tarPrev {target->prev};
        Node* tarNext {target->next};

        tarPrev->next = tarNext;
        tarNext->prev = tarPrev;

        // ii) Update pointers of start and target
        Node* stNxt {start->next};
        
        start->next = target;
        stNxt->prev = target;
        target->next = stNxt;
        target->prev = start;
    }
    inline void MoveNewNodeCloseToStart(Node* target)
    {
        // Get what start's next val
        Node* stNxt {start->next};
        
        start->next = target;
        stNxt->prev = target;

        target->next = stNxt;
        target->prev = start;
    }
public:
    LRUCache(int capacity) {
       cap = capacity;

       // set up start and end pointers
       start = new Node(-1);
       end = new Node(0, start, start);

       start->prev = end;
       start->next = end;
    }
    
    int get(int key) {
        if (nMap.count(key) == 0)
            return -1;

        Node* target {nMap[key]};
        MoveTargetCloseToStart(target);
        
        return target->val;
    }
    
    void put(int key, int value) {
        if (nMap.count(key) != 0)
        {
            nMap[key]->val = value;
            MoveTargetCloseToStart(nMap[key]);
            return;
        }

        Node* newNode {new Node(value)};
        nMap.try_emplace(key, newNode);
        if (size != cap) // Space is available
        {
            MoveNewNodeCloseToStart(newNode);
            ++size;
        }
        else
        {
            // Remove least recently used node
            Node* least {end->prev};
            Node* leastPrev {least->prev};

            leastPrev->next = end;
            end->prev = leastPrev;

            int key {-1};
            // move entry from map as well
            for (std::pair<int,Node*> entry : nMap)
            {
                if (entry.second == least)
                {
                    key = entry.first;
                    break;
                }
            }
            nMap.erase(key);

            delete least;
            least = nullptr;


            // Move new node close to the start
            MoveNewNodeCloseToStart(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#include <iostream>

int main()
{
    LRUCache lRUCache {2};


    std::cout << "LRU Cache Example\n\n";


    std::cout << "put(1, 1)\n";
    lRUCache.put(1, 1);

    std::cout << "put(2, 2)\n";
    lRUCache.put(2, 2);

    std::cout << "get(1) -> "
              << lRUCache.get(1)
              << "\n";

    std::cout << "put(3, 3)\n";
    lRUCache.put(3, 3);

    std::cout << "get(2) -> "
              << lRUCache.get(2)
              << "\n";

    std::cout << "put(4, 4)\n";
    lRUCache.put(4, 4);

    std::cout << "get(1) -> "
              << lRUCache.get(1)
              << "\n";

    std::cout << "get(3) -> "
              << lRUCache.get(3)
              << "\n";

    std::cout << "get(4) -> "
              << lRUCache.get(4)
              << "\n";


    return EXIT_SUCCESS;
}