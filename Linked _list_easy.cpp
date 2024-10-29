class Node {
public:
//     int data;
//     Node* next;

//     // Default constructor
//     Node()
//     {
//         data = 0;
//         next = NULL;
//     }

//     // Parameterised Constructor
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// // User function Template for C++

class Node {
 public:
     int data;
     Node* next;

     // Default constructor
     Node()
     {
         data = 0;
         next = NULL;
     }

     // Parameterised Constructor
     Node(int data)
     {
         this->data = data;
        this->next = NULL;
     }
 };

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for(int i = 1; i < arr.size(); i++){
            Node* newNode = new Node(arr[i]);
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }
};
//-----------insert at end-----------------

class Solution {
public:
    Node *insertAtEnd(Node *head, int x) {
     
        Node* newNode = new Node(x);
          
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        
        return head;
    }
};
//----------Delete Node in a Linked List------------

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * temp=node->next;
        node->val=temp->val;
        node->next=node->next->next;
        delete temp;
    }
};