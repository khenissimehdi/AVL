#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

node *create_node(int elt)
{
    node *n = (node *)malloc(sizeof(node));
    assert(n != NULL);
    n->elt = elt;
    n->height = 0;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void free_tree(node *t)
{
    if (t != NULL)
    {
        free_tree(t->left);
        free_tree(t->right);
        free(t);
    }
}
void update_height(node *t)
{
    if (t->right->height > t->left->height)
    {
        t->height = t->right->height + 1;
    }
    else
    {
        t->height = t->left->height + 1;
    }
}
node *rotate_right(node *t)
{
    node *x = t->left;
    t->left = x->right;
    x->right = t;
    update_height(t);
    update_height(x);
    return x;
}
node *rotate_left(node *t)
{
    node *y = t->right;
    t->right = y->left;
    y->left = t;
    update_height(t);
    update_height(y);
    return y;
}
node *rotate_left_right(node *t)
{
    t->left = rotate_left(t->left);
    return rotate_right(t);
}
node *rotate_right_left(node *t)
{
    t->right = rotate_right(t->right);
    return rotate_left(t);
}
/* SEARCH */
int compute_balance(node *t)
{
    if (t->left != NULL && t->right != NULL)
    {
        return t->left->height - t->right->height;
    }
    if (t->left == NULL && t->right != NULL)
    {
        return 0 - t->right->height;
    }
    if (t->left != NULL && t->right == NULL)
    {
        return t->left->height;
    }
    return 0;
}
node *rebalance(node *t)
{
    if (t == NULL)
    {
        return t;
    }
    if (compute_balance(t) == 2)
    {

        if (compute_balance(t->left) == -1)
        {
            return rotate_left_right(t);
        }
        return rotate_right(t);
    }
    if (compute_balance(t) == -2)
    {
        if (compute_balance(t->right) == 1)
        {
            return rotate_right_left(t);
        }
        else
        {
            return rotate_left(t);
        }
    }
}
node *find_avl(node *t, int elt)
{
    node *ptr = t;
    while (ptr != NULL && ptr->elt != elt)
    {
        if (ptr->elt > elt)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return ptr;
}
