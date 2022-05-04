#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main() {
    struct t_btree *root;
    root = bstree_create_node(8);
    int data_1[8] = {1, 3, 10, 6, 7, 4, 14, 13};
    // int data_2[8] = {1, 3, 10, 6, 18, 13, 14, 15};
    int flag = 0;
    for (int i = 0; i < 8 && !flag; i++) {
        if (bstree_insert(root, data_1[i], cmpf)) {
            printf("Already in a tree\n");
            flag = 1;
        }
    }
    if (!flag) {
        printf("INFIX\n");
        bstree_apply_infix(root, applyf);
        printf("\nPREFIX\n");
        bstree_apply_prefix(root, applyf);
        printf("\nPOSTFIX\n");
        bstree_apply_postfix(root, applyf);
    }
    bstree_destroy(root);
    return 0;
}
