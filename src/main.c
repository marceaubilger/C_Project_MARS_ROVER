#include <stdio.h>
#include "map.h"
#include "N-ary-tree.h"
#include "node.h"

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
        printf("    %p  pos: %d\n",thenode->sons[i],thenode->sons[i]->pos_in_children);

   }
  return 0;
}
