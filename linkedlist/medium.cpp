// detect a loop in the linkedlist
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) return true;
            
        }
        return false;
    }
};

//---------- Lenth of loop in linkedlist -------------------

//-----------brute
class Solution {
public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        map<Node*, int> mapp;
        int timer = 1;
        Node* temp = head;
        
        while(temp != nullptr) {
            if(mapp.find(temp) != mapp.end()) {
                int value = mapp[temp];
                return timer - value;
            }
            mapp[temp] = timer;
            timer++;
            temp = temp->next;
        }
        return 0;
    }
};

//------optimal
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int lengthofll(Node* slow,Node* fast){
        int count=1;
        fast=fast->next;
        while(slow!=fast){
            count++;
            fast=fast->next;
        }
        return count;
    }
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        
            if(slow==fast){
                return lengthofll(slow,fast);
            }
        }
        return 0;
    }
    // -----------reverse a linkedlist -----------
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* newhead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newhead;
    }   
};
//-------------palindrome in linkedlist------------
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return true;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newhead=reverseLL(slow->next);
        ListNode*first=head;
        ListNode*second=newhead;
        while(second!=nullptr){
            if(first->val!=second->val){
                reverseLL(newhead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseLL(newhead);
        return true;

        
    }
    ListNode* reverseLL(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode*newhead=reverseLL(head->next);
        ListNode*front=head->next;
        front->next=head;
        head->next=nullptr;
        return newhead;
    }
};