//题目：给两个列表，判断是否相交，若相交，则返回交点，若否，则返回NULL
//理论上是假设链表一长度为a1+b，链表二为a2+b，其中b为公共链的长度。那么让链表一的指针走完走二，链表二的指针走完走一，则必定在交点出相交。
//(a1+b)+a2 = (a2+b)+a1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        if(ptr1 == NULL || ptr2 == NULL) return NULL;
        while(ptr1 != ptr2){
            if(ptr1 == NULL){
                ptr1 = headB;
            }
            else{
                ptr1 = ptr1->next;
            }
            if(ptr2 == NULL){
                ptr2 = headA;
            }
            else{
                ptr2 = ptr2->next;
            }
        }
        return ptr1;
    }
};
