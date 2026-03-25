class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; 
    }

    ListNode *findKth(ListNode* head, int k) {
        while (head && --k > 0) {
            head = head->next;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;
        
        ListNode* currHead = head;

        while (true) {
            ListNode* kthNode = findKth(currHead, k);
            if (!kthNode) break;

            ListNode* groupStart = groupPrev->next;
            ListNode* nextGroupHead = kthNode->next;

            kthNode->next = nullptr;
            groupPrev->next = reverse(groupStart);

            groupStart->next = nextGroupHead;

            groupPrev = groupStart;
            currHead = nextGroupHead;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};