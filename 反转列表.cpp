//算法：指针指向第一个节点，不断将下一个移到开头，知道“原”第一个节点成为最后一个阶段
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = head;
        if(ptr == NULL) return ptr;
        while(ptr->next != NULL){
            ListNode* temp = ptr->next;
            ptr->next = temp->next;
            temp->next = head;
            head = temp;
        }
        return head;
    }
};
