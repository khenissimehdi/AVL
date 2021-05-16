#include "tree.h"
#include <stdio.h>
#include "visualtree.h"
int main()
{

  node *t;
  t = NULL;
  t = create_node(3);

  t->left = create_node(5);
  t->left->left = create_node(12);
  t->left->right = create_node(1);
  t->left->right->left = create_node(4);
  t->right = create_node(2);
  t->right->right = create_node(7);

  int res = count_nodes(t);
  printf("%d \n", res);
  int res2 = count_leaves(t);
  printf("%d \n", res2);
  int res3 = count_only_children(t);
  printf("%d \n", res3);

  int res4 = height(t);
  printf("%d \n", res4);

  free_tree(t);
  /*node *t;

  t = scan_tree();
  parcours_prefixe(t);

  putchar('\n');
  write_tree(t);*/

  return 0;
}
