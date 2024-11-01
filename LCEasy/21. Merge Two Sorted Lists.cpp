/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /* Recursive approach */

        //bases cases: if either list is empty, return the other list
        if (list1 == nullptr){
            return list2;
        }
        if (list2 == nullptr){
            return list1;
        }

        //compare the values and recursively merge the lists
        if ((list1->val) < (list2->val)){
            //attach smaller node to the merged list and recursive call to continue merging
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;  //return l1 as the head
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;  //return l2 as the head
        }
    }   
};
