#ifndef AVL_H
#define AVL_H

typedef struct _node
{
    int elt;             /* donnee stockee : un entier  */
    int height;          /* la hauteur de l'arbre       */
    struct _node *left;  /* pointeur sur le fils gauche */
    struct _node *right; /* pointeur sur le fils droit  */
} node;

node *create_node(int elt);

void free_tree(node *t);
int compute_balance(node *t);
node *rebalance(node *t);
int is_avl(node *t);
void update_height(node *t);
node *rotate_right(node *t);
node *rotate_left(node *t);
node *rotate_left_right(node *t);
node *rotate_right_left(node *t);

node *insert_avl(node *t, int elt);

int is_avl(node *t);

#endif /* AVL_H */
