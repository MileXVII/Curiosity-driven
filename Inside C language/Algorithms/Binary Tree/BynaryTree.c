/*Basic implamantition of a binary tree: */

#include <stdio.h>
#include <stdlib.h>

void error(char* err){
    fprintf(stderr, "[ERROR]: %s!\n", err);
    exit(1);
}

struct node {
    int val;
    struct node *left, *right;
};

/*Add a new node, if root is NULL returns the new root
(the first inserted node) otherwise is just returns
the root passed by the user in input. 

WARNING: this function don't check duplicates, it's a basic example*/
struct node *add(struct node *root, int val) {
    struct node *saved_root = root;
    struct node *new = malloc(sizeof(*new)); //sizeof(struct node*);
    if(new == NULL) error("Malloc failed");
    
    new->left = new->right = NULL;
    new->val = val;

    if (root == NULL) return new;

    while(1) {
        if(val > root->val) {
            if(root->right == NULL) {
                root->right = new;
                return saved_root;
            }
            root = root->right;
        } else {
            if (root->left == NULL) {
                root->left = new;
                return saved_root;
            }
            root = root->left;
        }
    }
}

void free_tree (struct node *root) {
    if(root == NULL) return;

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print_sorted(struct node *root) {
    if (root == NULL) return;
    print_sorted(root->left);;
    printf("%d\n", root->val);
    print_sorted(root->right);
}

int main(void) {
    struct node *root = NULL;

    root = add(root, 20);
    root = add(root, 10);
    root = add(root, 5);
    root = add(root, 20);
    root = add(root, 100);
    root = add(root, 40);
    root = add(root, 33);
    root = add(root, 20);

    print_sorted(root);
    free_tree(root);
    
    return 0;
}
