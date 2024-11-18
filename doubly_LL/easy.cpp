class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        Node*head=new Node(arr[0]);
        Node*prev=head;
        int n=arr.size();
        for(int i=1;i<n;i++){
        Node*temp=new Node(arr[i]);
        temp->prev=prev;
        prev->next=temp;
        prev=temp;
        
    }return head;
        
    }
};


// --------------- delete a doublyLL node ----------------
//---------------1)at head---2)at tail----3) at kth position-------
class Solution {
  public:
       Node* deleteNode(Node* head, int x) {
        // Your code here
        Node* temp = head;
        
        int count = 0;
        while(temp != nullptr)
        {
            count += 1;
            if(count == x) break;
            temp = temp->next;
        }
        Node* prev = temp->prev;
        Node* front = temp->next;
        
        if(front == nullptr && prev == nullptr)  
        {
            return nullptr;  
        }
        else if(prev == nullptr) 
        {
            return deleteHead(head);
        }
        else if(front == nullptr)  
        {
            return deleteTail(head);
        }
        else
        {
            prev->next = front;
            front->prev = prev;
            temp->next = nullptr;
            temp->prev = nullptr;
            free(temp);
            return head;   
        }
    }
    
    Node* deleteHead(Node* head){
        Node* temp = head;
        head = head->next;
        if(head != nullptr)     
            head->prev = nullptr;
        temp->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    
    Node* deleteTail(Node* head)
    {
        Node* temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        Node* prev = temp->prev;
        prev->next = nullptr;
        temp->prev = nullptr;
        temp->next = nullptr;   
        delete temp;
        return head;
    }
};