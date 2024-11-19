#include <stdio.h>
#include "map.h"
#include "N-ary-tree.h"
#include "node.h"
#include "moves.h"

int main() {
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
   p_node thenode = createNode(NULL,0);
   int countnode=1;
   thenode=createNaryTree(thenode,9,&countnode,NULL);
   printf(" %d \n",countnode);

    printf("%p\n",thenode->sons[0]->father);
    for(int i=0;i<9;i++){
        //printf("    %p  pos: %d\n",thenode->sons[i],thenode->sons[i]->pos_in_children);
        //printf("%s\n",_moves[i]);
   }

    int N=12;
    int nbmoves[]={22,15,7,7,21,21,7};
    int total_moves=100;
    t_move *moves = (t_move *)malloc(N * sizeof(t_move));
    for (int i = 0; i < N; i++)
    {
        int r = rand() % total_moves;
        int type=0;
        while (r >= nbmoves[type])
        {
            r -= nbmoves[type];
            type++;
        }
        nbmoves[type]--;
        total_moves--;
        moves[i] = (t_move )type;
    }
    printf("%d",moves);
  return 0;
}
