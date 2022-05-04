#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

t_btree* bstree_create_node(int item) {
    struct t_btree* node = malloc(sizeof(t_btree));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    int flag = 0;
    if (root->left != NULL && root->left->item == item)
        flag = 1;
    else if (root->right != NULL && root->right->item == item)
        flag = 1;
    else if (root->item == item)
        flag = 1;
    if (!flag) {
        if ((*root).left == NULL && (*root).right == NULL) {
            if ((*cmpf) ((*root).item, item)) {
                root->left = bstree_create_node(item);
            } else {
                root->right = bstree_create_node(item);
            }
        } else {
            if ((*cmpf) ((*root).item, item)) {
                if ((*root).left != NULL)
                    bstree_insert(root->left, item, (*cmpf));
                else
                    root->left = bstree_create_node(item);
            } else {
                if ((*root).right != NULL)
                    bstree_insert(root->right, item, (*cmpf));
                else
                    root->right = bstree_create_node(item);
            }
        }
    }
    return flag;
}

int cmpf(int n1, int n2) {
    int flag = 1;
    if (n2 > n1)
        flag = 0;
    return flag;
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root->left)
        bstree_apply_infix(root->left, applyf);
    applyf(root->item);
    if (root->right)
        bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    applyf(root->item);
    if (root->left)
        bstree_apply_prefix(root->left, applyf);
    if (root->right)
        bstree_apply_prefix(root->right, applyf);
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root->right)
        bstree_apply_postfix(root->right, applyf);
    applyf(root->item);
    if (root->left)
        bstree_apply_postfix(root->left, applyf);
}

void applyf(int item) {
    printf("%d ", item);
}

void bstree_destroy(t_btree *root) {
    if (root->left)
        bstree_destroy(root->left);
    if (root->right)
        bstree_destroy(root->right);
    if (root)
        free(root);
}
