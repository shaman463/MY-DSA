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
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
       
//        ListNode* dummy = new ListNode(0);
//         dummy->next = head;
        
//         ListNode* temp = dummy;
        
//         while (temp->next != nullptr) {
//             if (temp->next->val == val) {
//                 ListNode* todelete = temp->next;
//                 temp->next = temp->next->next; 
//                 delete todelete;
//             } else {
//                 temp = temp->next;
//             }
//         }
//         head = dummy->next;
//         delete dummy;
//         return head;
//     }
// };