class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap (priority queue) to always extract smallest node
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        // Push head of each list into the min-heap
        for (auto node : lists) {
            if (node) pq.push({node->val, node});
        }

        // Dummy node to simplify construction of result list
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Extract the smallest node and push its next node until heap is empty
        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();

            tail->next = node; 
            tail = tail->next;

            if (node->next) {
                pq.push({node->next->val, node->next});
            }
        }

        return dummy.next;
    }
};