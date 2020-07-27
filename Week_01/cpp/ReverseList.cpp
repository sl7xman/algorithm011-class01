class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if( head == nullptr || head->next == nullptr ){
            return head;
        }

        ListNode* p = reverseList( head->next );
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while( cur ) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};
