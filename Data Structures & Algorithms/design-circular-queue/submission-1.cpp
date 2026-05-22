class MyCircularQueue {
     struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
public:
    int size=0;
    int maxSize;
    ListNode* tail=nullptr;
    ListNode* head=nullptr;
    MyCircularQueue(int k) {
        maxSize=k;
        // ListNode* dummy = new ListNode(0);
        // dummy->next=head;
        // dummy->next=tail;

    }
    
    bool enQueue(int value) {
        if(size==maxSize){
            return false;
        }
        ListNode* temp = new ListNode(value);
        if(head==nullptr){
            head=temp;
            tail=temp;
        }else{
        tail->next=temp;
        tail=temp;
        }
         size++;
        return true;
    }
    
    bool deQueue() {
       if(size==0){
            return false;
        }
        head = head->next;
        if(head==nullptr){
            tail=nullptr;
        }
         size--;
         return true;
    }
    
    int Front() {
        if(size==0) return -1;
        return head->val;
    }
    
    int Rear() {
        if(size==0) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        if(size==0) return true;
        return false;
    }
    
    bool isFull() {
        if(size==maxSize) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */