#include <stdio.h>
#include "map.h"
#include "N-ary-tree.h"
#include "node.h"
#include "time.h"
#include "moves.h"

int main() {
    srand(time(NULL));
    /*
    t_map map = createMapFromFile("maps/example1.map");
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    displayMap(map);
    return 0;
    */
   t_move *random_moves=getRandomMoves(9);
   p_node thenode = createNode(NULL,0);
   int countnode=1;
    for(int i=0;i<9;i++){
        thenode->mouv_for_sons[i]=random_moves[i];
        printf("%d  ",random_moves[i]);
    }
    
    thenode=createNaryTree(thenode,9,&countnode,NULL);
    //printf(" %d \n",countnode);
    int count_=0;
    traversePreOrder(thenode,&count_);
    //printf("    \n%d\n",count_);

    printf("%p\n",thenode->sons[0]->father);
    for(int i=0;i<9;i++){
        for(int j=0;j<8;j++){
            printf("%d   ",thenode->sons[i]->mouv_for_sons[j]);
        }
        printf("        %d",thenode->sons[i]->move_to_get_here);
        printf("\n");

        
    }

    return 0;
}
