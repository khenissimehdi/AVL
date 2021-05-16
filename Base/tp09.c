#include "avl.h"
#include "tree.h"
#include "visualtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * 1 - Pour une insertion de 1000000 d’éléments aléatoire nous avons environ 0.057039 secondes pour une hauteur de 11.
 * 2 - pour une insertion d’entier 1,2...N en ordre, et pour une insertion de 1 000 000 d'éléments nous avons environ 0.389721 secondes pour une hauteur de 1000000.
 */

node *testRandomNumbers(node *t, int number)
{

    srand(time(NULL));

    int i = 0;

    for (i = 0; i < number; i++)
    {
        int elt = ((rand() % (10 - 0 + 1)) + 0);

        t = insert_avl(t, elt);
    }
    int nodes = count_nodes(t);
    printf("we done %d \n", nodes);

    return t;
}
node *testOrderNumbers(node *t, int number)
{

    srand(time(NULL));
    int i = 0;

    for (i = 0; i < number; i++)
    {

        t = insert_avl(t, i);
    }
    int nodes = count_nodes(t);
    printf("we done %d \n", nodes);

    return t;
}

int main()
{

    /* node *t;
    t = create_node(10);
    t = insert_avl(t, 5);
    t = insert_avl(t, 13);
    t = insert_avl(t, 11);
    t = insert_avl(t, 15);
    t = insert_avl(t, 12);

    write_tree(t);
    node *t2 = NULL;
    int i;
    for (i = 0; i < 100; i++)
    {
        t2 = insert_avl(t2, i);
        if (!is_avl(t2))
        {
            printf("The tree is not balanced\n");
            exit(-1);
        }
    }
    printf("Ok!\n");*/

    node *testTRee = NULL;
    clock_t time;
    time = clock();
    testTRee = testRandomNumbers(testTRee, 1000000);
    time = clock() - time;
    double time_taken = ((double)time) / CLOCKS_PER_SEC;
    printf("fun() took %f seconds to execute \n", time_taken);

    /* printf("%d \n", is_avl(t));*/
    return 0;
}
