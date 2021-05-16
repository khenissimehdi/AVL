#ifndef TREE_H
#define TREE_H

/*
 * Allocate memory for a new node.
 */

void parcours_prefixe(node *t);
int count_nodes(node *t);
int count_leaves(node *t);
int count_only_children(node *t);
void parcours_infixe(node *t);
void parcours_suffixe(node *t);
int height(node *t);
node *scan_tree(void);

#endif /* TREE_H */
