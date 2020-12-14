/*given an arrays of regions and its length, determine whether we can empty 
an amount of trash given by goal*/

#include <stdio.h>
int canEmpty(const unsigned int* regions, unsigned int num_regions, int goal){
    if (*regions == goal){
        return 1;
    }
    if (goal == 0){
        return 1;
    }
    if (num_regions == 0){
        return 0;
    }
    if (goal < 0){
        return 0;
    }
    //choose to fill or not fill
    unsigned int currsize = *regions;
    
    if (canEmpty(regions+1, num_regions-1, goal-currsize)) return 1;
    if (canEmpty(regions+1, num_regions-1, goal)) return 1;
    return 0;
}

//testing purposes
int main(){
    int reg[5] = {1, 3, 5, 4, 4};
    printf("%d", canEmpty(reg, 5, 2));
}