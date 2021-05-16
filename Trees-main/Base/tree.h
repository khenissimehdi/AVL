#ifndef TREE_H
#define TREE_H

typedef struct _node
{
    int data;            /* data stored : an integer    */
    struct _node *left;  /* pointer to the left child   */
    struct _node *right; /* pointer to the right child  */
} node;

/*
 * Allocate memory for a new node.
 */
node *create_node(int data);

void parcours_prefixe(node *t);
int count_nodes(node *t);
int count_leaves(node *t);
int count_only_children(node *t);
void parcours_infixe(node *t);
void parcours_suffixe(node *t);
int height(node *t);
node *scan_tree(void);
void free_tree(node *t);

#endif /* TREE_H */
