class LRUCache {
    struct DoublyLL{
        int key,val;
        DoublyLL* prev;
        DoublyLL* next;
        DoublyLL(){ this->key=0; this->val=0; this->prev=nullptr; this->next=nullptr;}
        DoublyLL(int key,int val){ this->key=key; this->val=val; this->prev=nullptr; this->next=nullptr;}
    };
public:
    unordered_map<int,DoublyLL*> mp;
    int maxSize;
    DoublyLL* head;
    DoublyLL* tail;
    int currSize;
    LRUCache(int capacity) {
        maxSize=capacity;
        currSize=0;
        head = new DoublyLL(0,0);
        tail = new DoublyLL(0,0);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
             DoublyLL* nodeToDelete = mp[key];
            DoublyLL* previous = nodeToDelete->prev;
            DoublyLL* nextE = nodeToDelete->next;
            previous->next = nextE;
            nextE->prev = previous;

            nodeToDelete->next=head->next;
            nodeToDelete->prev=head;
            head->next=nodeToDelete;
            nodeToDelete->next->prev=nodeToDelete;
            mp[key] = nodeToDelete;
            return nodeToDelete->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            DoublyLL* nodeToDelete = mp[key];
            DoublyLL* prev = nodeToDelete->prev;
            prev->next = nodeToDelete->next;
            nodeToDelete->next->prev = prev;

            nodeToDelete->next=head->next;
            nodeToDelete->prev=head;
            head->next=nodeToDelete;
            nodeToDelete->next->prev=nodeToDelete;
            nodeToDelete->val=value;
            mp[key] = nodeToDelete;

        }else{
            DoublyLL* temp = new DoublyLL(key,value);
            temp->next=head->next;
            temp->prev=head;
            head->next=temp;
            temp->next->prev=temp;
            mp[key] = temp;
             currSize++;
            if(currSize>maxSize){
               DoublyLL* tailtemp = tail->prev;
               tail->prev=tailtemp->prev;
               tailtemp->prev->next=tail;
               mp.erase(tailtemp->key);
               delete tailtemp;   
               currSize--;         
            }
        }
    }
};