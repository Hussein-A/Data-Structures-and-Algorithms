4-42. Implement an algorithm that takes an input array and returns only the unique elements in it.  
.  
***Solution***  
Unfortunately the problem is not too precise as to our exact limitations when dealing with the data, for example are we permitted to modify
the data? Minimize extra space? etc. We assume that we are indeed allowed to modify the data. The simplest method would be first sort the
array. This will help us identify duplicate elements as follows: as we go through the array check if the element infront is the same as
the current one, if so keep going (ie. ignore this element) until we come to the next distinct element and check again. If the front element
differs from the previous then this is a unique element, add it to an array that will only contain the unique elements we find. This takes
O(n+nlogn) time.  

Alternatively we may reduce our time complexity in the average case by resorting to hashing. Hash the elements of the array. Afterwards
go through the buckets and check if the size of the bucket is of size 1, if so then this is a unique element and hence will be outputted
else move on to the next bucket. This yields an expected O(n) time and O(n) space. Code from leetcode that deals specifically with
this problem is given below (note the leetcode problem assumes the list is already sorted.).  
.  
*Code*  
```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode* dummy = new ListNode{0};
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr->next != NULL){
            if (curr->val == curr->next->val){
                int duplicate = curr->val;
                while (curr && curr->val == duplicate){
                    auto temp = curr;
                    curr= curr->next;
                    delete temp;
                }
                
                prev->next = curr;
                if (curr == NULL) break;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};
```
