#ifndef SRC_BST_H_
#define SRC_BST_H_

typedef struct t_btree {
    int item;
    struct t_btree *left;
    struct t_btree *right;
} t_btree;

t_btree* bstree_create_node(int item);
int bstree_insert(t_btree *root, int item, int (*cmpf)(int, int));
int cmpf(int n1, int n2);
void bstree_apply_infix(t_btree *root, void (*applyf)(int));
void bstree_apply_prefix(t_btree *root, void (*applyf)(int));
void bstree_apply_postfix(t_btree *root, void (*applyf)(int));
void applyf(int item);
void bstree_destroy(t_btree *root);

#endif  //  SRC_BST_H_
