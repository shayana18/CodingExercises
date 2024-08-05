//You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.



// watched https://www.youtube.com/watch?v=R9PTBwOzceo to gain basic understanding of linkedLists
// intuition: compare heads of each list.. smaller becomes the head of the output list. then increment list with smaller elemnt and compare to other list.. always place smaller element into list and increment other until one list runs out then place entire other list into output as it is already sorted

// Definition for singly-linked list.
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; 
        ListNode *outputList = &dummy;

        while(list1 !=nullptr && list2 != nullptr){
            if(list1->val > list2->val){
                outputList->next = list2; 
                list2 = list2->next;
            }else{
                outputList->next = list1; 
                list1 = list1->next;
            }
            outputList = outputList->next; // this basically insures that future vales get stored in the next element portion of the output list and continue to do so for each node, without this the loop is either infinite or you would continue to overwrite the first node in outputList
        }
        if(list1== nullptr){
            outputList->next = list2;
        }else{
            outputList->next = list1;
        }

        return dummy.next; // since dummy was arbitrary header we used to initialize our linked list we want to return its next element as that is what contianes the merged list
    }
};