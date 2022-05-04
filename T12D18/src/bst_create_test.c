#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main() {
    struct t_btree *node;
    int n;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &n);
        node = bstree_create_node(n);
        printf("%d %p %p\n", (*node).item, node->left, node->right);
    }
    bstree_destroy(node);
    return 0;
}
