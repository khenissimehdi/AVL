#ifndef VISUALTREE_H
#define VISUALTREE_H

#include "avl.h"

/*
 * Open a file current-tree.dot, write the DOT code for
 * the tree t, and convert the .dot-file to a pdf.
 */
void write_tree(node *t);

#endif /* VISUALTREE_H */
