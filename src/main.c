#include <stdio.h>
#include "map.h"
#include "N-ary-tree.h"
#include "node.h"
#include "time.h"
#include "moves.h"
#include "loc.h"

int main() {
    srand(time(NULL));
    
    t_map map = createMapFromFile("maps/example1.map");
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    // for (int i = 0; i < map.y_max; i++)
    // {
    //     for (int j = 0; j < map.x_max; j++)
    //     {
    //         printf("%d ", map.soils[i][j]);
    //     }
    //     printf("\n");
    // }
    /*
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
   p_node thenode = createNode(NULL,0);
   int countnode=1;
   int count_=0;
   int random_orientation;
   t_position popo;
   t_localisation loco;

    thenode->l=loco;
   popo=getRandomStartingPoint(map.y_max,map.x_max);
   printf("original y: %d   original x: %d\n",popo.y,popo.x);

    random_orientation=rand()%4;
    t_orientation orientation = (t_orientation)random_orientation;

    thenode->l=loc_init(popo.x,popo.y,orientation);
    printf("orientation %d\n",thenode->l.ori);
   
   t_move *random_moves=getRandomMoves(9);
    for(int i=0;i<9;i++){
        thenode->mouv_for_sons[i]=random_moves[i];
        printf("%s   ",_moves[random_moves[i]]);
    }
    printf("\n\n");


    thenode=createNaryTree(thenode,9,&countnode,NULL);
    traversePreOrder(thenode,&count_);

    thenode->sons[0]->l = move(thenode->l,thenode->mouv_for_sons[0]);
    //printf("new y: %d    new x: %d   new ori %d\n",thenode->sons[0]->l.pos.y, thenode->sons[0]->l.pos.x,thenode->sons[0]->l.ori);
    //printf("%d  %d\n",thenode->sons[0]->l.pos.y,thenode->sons[0]->l.pos.x);

    //printf("%d \n",countnode);
    //printf("    \n%d\n",count_);
    //printf("%p\n",thenode->sons[0]->father);

    for(int i=0;i<9;i++){
        printf("move used : %s   ",_moves[thenode->sons[i]->move_to_get_here]);
        printf("y:%d  x:%d   ori:%d\n",thenode->sons[i]->l.pos.y,thenode->sons[i]->l.pos.x,thenode->sons[i]->l.ori);
        for(int j=0;j<8;j++){
            continue;
        }   
    }
    

    return 0;
}
