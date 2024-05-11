/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <queue>
#include <vector>


struct compare {
    bool operator()(const ListNode* l1, const ListNode* l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Initialize the priority queue with the head of each list
        for (ListNode* list : lists) {
            if (list) pq.push(list);
        }

        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;

        while (!pq.empty()) {
            // The smallest node
            ListNode* top = pq.top();
            pq.pop();

            // Add the smallest node to the merged list
            current->next = top;
            current = current->next;

            // If there is more nodes in the list, push the next node to the queue
            if (top->next) {
                pq.push(top->next);
            }
        }

        ListNode* mergedList = dummyHead->next;
        delete dummyHead; // clean up dummy node
        return mergedList;
    }
};
