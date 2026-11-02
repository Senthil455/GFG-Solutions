/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
void dfs(struct Node* root, int* max, int h){
    
    if(root == NULL){
        return;
    }
    for(int i = 0; i<root->numChildren;i++){
        struct Node* curr = root->children[i];
        if(curr == NULL){
            break;
        }
        if(h>(*max)){
            *max = h;
        }
        dfs(curr, max, h+1);
    }
}
int maxDepth(struct Node* root) {
    if(root == NULL){
        return 0;
    }
    int max = 1;
    dfs(root,&max, max+1);
    return max;
}