/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        copy(pHead);
        Link(pHead);
        RandomListNode* out = pHead->next;
        Break(out);
        return out;
    }
    void copy(RandomListNode* pHead){
        RandomListNode* temp = pHead->next;
        pHead->next = new RandomListNode(pHead->label);
        pHead->next->next = temp;
        if(temp != NULL) copy(temp);
    }
    void Link(RandomListNode* pHead){
        if(pHead != NULL){
            if(pHead->random != NULL) pHead->next->random = pHead->random->next;
            Link(pHead->next->next);
        }
    }
    void Break(RandomListNode* pHead){
        if(pHead->next != NULL){
            pHead->next = pHead->next->next;
            Break(pHead->next);
        }
    }
