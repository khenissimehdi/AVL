#include "avl.h"
#include "tree.h"
#include "visualtree.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    node *t = scan_tree();
    write_tree(t);
    free_tree(t);

    return 0;
}
