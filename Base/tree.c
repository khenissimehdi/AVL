#include "avl.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void parcours_prefixe(node *t)
{
  if (t == NULL)
    return;
  printf("%d ", t->elt);
  parcours_prefixe(t->left);
  parcours_prefixe(t->right);
}

void parcours_infixe(node *t)
{
  if (t == NULL)
    return;

  parcours_infixe(t->left);
  printf("%d ", t->elt);
  parcours_infixe(t->right);
}
void parcours_suffixe(node *t)
{
  if (t == NULL)
    return;
  parcours_suffixe(t->left);
  parcours_suffixe(t->right);
  printf("%d ", t->elt);
}

node *scan_tree(void)
{
  int input;
  node *tree = NULL;
  scanf("%d", &input);

  if (input == 0)
  {
    return NULL;
  }

  tree = create_node(input);

  tree->left = scan_tree();
  tree->right = scan_tree();
  compute_balance(tree);

  return tree;
}
int count_nodes(node *t)
{
  if (t == NULL)
    return 0;
  return count_nodes(t->left) + count_nodes(t->right) + 1;
}

int count_leaves(node *t)
{
  if (t == NULL)
    return 0;

  if (t->left == NULL && t->right == NULL)
  {
    return 1;
  }
  return count_leaves(t->left) + count_leaves(t->right);
}
int count_only_children(node *t)
{

  if (t == NULL)
    return 0;

  if (t->left == NULL || t->right == NULL)
  {
    if (t->left == NULL && t->right == NULL)
    {
      return 0;
    }
    if (t->left != NULL)
    {
      return count_only_children(t->left) + 1;
    }
    if (t->right != NULL)
    {
      return count_only_children(t->right) + 1;
    }
  }
  return count_only_children(t->left) + count_only_children(t->right);
}
int height(node *t)
{

  if (t == NULL)
    return -1;
  else
  {

    int left = height(t->left);
    int right = height(t->right);

    if (left > right)
    {
      return (left + 1);
    }

    else
    {
      return (right + 1);
    }
  }
}
