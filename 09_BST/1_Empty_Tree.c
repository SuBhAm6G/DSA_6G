#include <stdio.h>
typedef struct node{
    struct node *left,*right;
    int val;
}node;
node* CreateTree(){
    node* root=NULL;
    return root;
}
int main() {
    node *root=CreateTree();
    
    return 0;
}
