// struct Node{
//     int key;
//     int val;
//     Node *prev;
//     Node *next;
//     Node(int k, int v, Node* p, Node* n) : key(k),val(v),next(n),prev(p) {}
// };


// class LRUCache {
// private:
//     void deleteNode(Node* node){
//         Node* prevNode=node->prev;
//         Node* afterNode=node->next;
//         prevNode->next=afterNode;
//         afterNode->prev= prevNode;
//     }

//     void insertAhead(Node* node, Node* head){
//         Node* curr=head->next;
//         head->next=node;
//         node->prev=head;
//         node->next=curr;
//         curr->prev=node;

//     }
// public:
//     unordered_map<int,Node*> mpp;
//     int capacity;
//     Node* head=new Node(-1,-1,nullptr,nullptr);
//     Node* tail=new Node(-1,-1,nullptr,nullptr);
    

//     LRUCache(int capacity) {
//         this->capacity=capacity;
//         mpp.clear();
//         head->next=tail;
//         tail->prev=head;
        
//     }
    
//     int get(int key) {

//         if(mpp.find(key) == mpp.end()) return -1;
        
//         Node* node=mpp[key];
//         deleteNode(node);
//         insertAhead(node,head);
//         return node->val;
//     }
    
//     void put(int key, int value) {

//         if(mpp.find(key)!=mpp.end()){
//             Node* node=mpp[key];
//             deleteNode(node);
//             insertAhead(node,head);
//             node->val=value;
//         }else{

//             if(capacity==mpp.size()){
//                 Node* node=tail->prev;
//                 mpp.erase(node->key);
//                 deleteNode(node);
//             }
//             Node* newNode= new Node(key,value,nullptr,nullptr);
//             mpp[key]= newNode;
//             insertAhead(newNode,head);
//         }
        
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> lruList; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // Not found
        if (cache.find(key) == cache.end()) return -1;

        // Found → move to front
        auto it = cache[key];
        int value = it->second;

        lruList.erase(it);
        lruList.push_front({key, value});
        cache[key] = lruList.begin();

        return value;
    }

    void put(int key, int value) {
        // If key exists → remove old
        if (cache.find(key) != cache.end()) {
            lruList.erase(cache[key]);
        }

        // Insert new key-value at front
        lruList.push_front({key, value});
        cache[key] = lruList.begin();

        // If over capacity → remove least recently used (back of list)
        if (cache.size() > capacity) {
            auto last = lruList.back();
            cache.erase(last.first);
            lruList.pop_back();
        }
    }
};
