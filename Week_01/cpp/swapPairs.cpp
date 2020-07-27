class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = new ListNode(0);
        p->next = head;
        ListNode* curr = p;

        while( head && head->next ){
            ListNode* firstNode = head;
            ListNode* secondNode = head -> next;

            curr->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;
            curr = firstNode;
            head = firstNode->next;
        }
        return p->next;
    }
}; 
