#include <stdio.h>
#include <malloc.h>
#define APPEND -1
struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode ListNode;

// 
void printListNode(struct ListNode* ln){
    ListNode* tmpLn = ln;
    while(1){
        printf("Value: %d, Next: %p\n", tmpLn->val, tmpLn->next);

        if(tmpLn->next != NULL){
            tmpLn = tmpLn->next;
        }else{
            break;
        }
    }
};

// `ln` = listnode , `val` = value, `index` = can be NULL or INT, index in the linked list
//  - Note: ONLY ADDS values
ListNode* addNodeValueToList(ListNode* ln, int val, __u_int index){
    // go to the specific node
    ListNode* tmpLn = ln;
    if(index == 0) tmpLn->val;

    for(__u_int i = 0; ((i < index - 1) && (tmpLn->next != NULL)) || (index < 0); i++){
        tmpLn = tmpLn->next;
    }

    ListNode* newLn = (ListNode*) malloc(sizeof(ListNode));
    newLn->val = val;
    if(index > 0){
        newLn->next = tmpLn->next;
    }
    tmpLn->next = newLn;
    return newLn;
}

int main(){
    struct ListNode j = {3, NULL};
    
    // printListNode(&j);

    for(int i = 0;  i < 500; i++){
        addNodeValueToList(&j, i, APPEND);
    }

    // addNodeToList(&j, 5);
    // printListNode(&j);

    printf("===============\n");
    addNodeValueToList(&j, 23, 3);

    printListNode(&j);
}