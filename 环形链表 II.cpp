//判断链表是否有环，若有则返回环的起点，若没有，则返回NULL。
//设环之前的长度为a，环的长度为b.若相遇，慢指针走的长度为a+x,快指针的长度为a+bm+x
//由于快指针的速度是慢指针的两杯，2(a+x) = a+bm+x，化简得到a = bm-x
//这里有个trick是，相遇后的位置，再加上a，刚好是环起点的位置，(a+bm+x)+a= (a+bm+x)+bm-x = a+2bm
//因此可以在相遇后，再生成一个指向起点的指针，按相同速度移动快指针和新指针，相遇后正好是环的起点。
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        while(ptr2 != NULL){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if(ptr2 == NULL) return NULL;
            ptr2 = ptr2->next;
            if(ptr1 == ptr2) {
                ListNode *dect = head;
                while(dect != ptr2){
                    dect = dect->next;
                    ptr2 = ptr2->next;
                }
                return dect;
            }
        }
        return NULL;        
    }
};
