

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head; // get the pointer at the head
        ListNode* prev = nullptr; // take a pointer so i can make new list

        while(cur!=nullptr){ // till the last 
            ListNode* Newcur = cur->next; // cur's next store in new pointer
            cur->next=prev; //cur's next point to prev 
            prev = cur; // move prev to cur 
            cur = Newcur; // move cur to new cur 
        }
        return prev; // reurn final list 
    }
};