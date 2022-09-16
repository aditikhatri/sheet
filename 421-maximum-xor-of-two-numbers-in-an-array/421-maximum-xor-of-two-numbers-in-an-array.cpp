class Solution {
    class Trie{
        class Node{
			 Node* links[2];
        public:
            bool check(int id) {
                if (links[id] != NULL)
                    return true;
                return false;
            }
            
            void put_link(int id,Node* curr){
                links[id] = curr;
            }
            
            Node* get_link(int id) {
                return links[id];
            }

        };
        /////////////// root node ////////////
        Node* root;
        
    public:
        Trie(){
            root = new Node();
        }
        
        void insert(int num){
            Node* temp = root;
            for(int i=31;i>=0;i--){
                int bit = (num>>i)&1;
                if(temp->check(bit)){
                    temp = temp->get_link(bit);
                }
                else{
                    temp->put_link(bit,new Node());
                    temp = temp->get_link(bit);
                }
            }
        }
        
        int get_max(int num){
            Node* temp = root;
            int ans = 0;
            for(int i=31;i>=0;i--){
                int bit = (num>>i)&1;
                if(temp->check(1-bit)){
                    temp = temp->get_link(1-bit);
                    ans |= (1<<i);
                }
                else{
                    temp = temp->get_link(bit);
                }
            }
            return ans;
        }
    };

public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* tre = new Trie();
        
        for(auto it:nums){
            tre->insert(it);
        }
        
        int ans = 0;
        
        for(auto it:nums){
            ans = max(ans,tre->get_max(it));
        }
        
        return ans;
    } 
};