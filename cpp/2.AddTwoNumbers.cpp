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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* l3 = nullptr;
        ListNode** node = &l3;
        bool flag = false;
        while(true){

            if(l1 != nullptr){
                sum += l1 -> val;
                l1 = l1 -> next;
                flag = true;
            }

            if(l2 != nullptr){
                sum += l2 -> val;
                l2 = l2 -> next;
                if(!flag){
                    flag = true;
                }
            }

            if(flag || sum > 0){
                *node = new ListNode(sum % 10);
                sum /= 10;
            }else{
                break;
            }

            flag = false;
            node = &((*node) -> next);
        }
        return l3;
    }
};