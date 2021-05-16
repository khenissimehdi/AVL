#include "avl.h"
#include "tree.h"
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
    if (t == NULL)
    {
        return;
    }
    int h = 0;
    if (t->left != NULL)
    {
        h = t->left->height + 1;
    }
    if (t->right != NULL)
    {
        if (t->right->height >= h)
        {

            h = t->right->height + 1;
        }
    }
    t->height = h;
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
    if (t->right == NULL && t->left != NULL)
    {

        return t->left->height;
    }
    return -1;
}

node *rebalance(node *t)
{

    if (t == NULL)
    {

        return t;
    }
    int feq = compute_balance(t);

    if (feq == 2)
    {

        if (t->left != NULL && compute_balance(t->left) == -1)
        {

            return rotate_left_right(t);
        }

        return rotate_right(t);
    }
    if (feq == -2)
    {
        if (t->right != NULL && compute_balance(t->right) == 1)
        {
            return rotate_right_left(t);
        }
        else
        {
            return rotate_left(t);
        }
    }
    return t;
}

int is_avl(node *t)
{
    if (t == NULL)
        return 0;
    if (t->left != NULL && t->right != NULL)
    {
        if (t->height != height(t))
        {

            return 0;
        }
        if (compute_balance(t) < -1 && compute_balance(t) > 1)
        {
            return 0;
        }
    }
    is_avl(t->left);
    is_avl(t->right);
    return 1;
}

node *insert_avl(node *t, int elt)
{
    if (t == NULL)
    {
        t = create_node(elt);
        return t;
    }
    else if (t->elt > elt)
    {
        t->left = insert_avl(t->left, elt);
    }
    else if (t->elt < elt)
    {
        t->right = insert_avl(t->right, elt);
    }
    update_height(t);
    t = rebalance(t);
    return t;
}
