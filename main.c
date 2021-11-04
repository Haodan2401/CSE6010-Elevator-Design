#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elevator.h"

//Assume:
//1. We did not count the waiting time at the first floor.
//2. We count the stopping time for each floor is alway 15s.

int main(void){
    
    // Scenario 1:
    test1();


    // Scenario 2:
    test2();


    // Scenario 3:
    for (int i = 7; i < 16; i++){
        printf("\n \n \nThe result of Scenario 3 (MaxFloor1 = %d):\n", i);
        test3(i);

    }

    
    // Scenario 4:

    int mintotal1;
    int mintotal2;
    double totalrecord1 = 10000000;
    double totalrecord2 = 0;
    
    int minper1;
    int minper2;
    double perecord1 = 1000000;
    double perecord2 = 0;
    
    double* finalresult;
    for (int index1 = 5; index1 < 16; index1++) {
        for (int index2 = index1+1; index2 < 17; index2++) {
            finalresult = test4(index1, index2);
            
            if (finalresult[0] < totalrecord1) {
                totalrecord1 = finalresult[0];
                totalrecord2 = finalresult[1];
                mintotal1 = index1;
                mintotal2 = index2;
            }
            
            if (finalresult[1] < perecord1) {
                perecord1 = finalresult[1];
                perecord2 = finalresult[0];
                minper1 = index1;
                minper2 = index2;
            }
        }
    }
    
    printf("\n\nThe optimum result for the minimum total time is maxFloor1 = %d, maxFloor2 = %d, and the result time is %f with average time for each passenger is %f, \nThe optimum result for the minimum average time of each person is maxFloor1 = %d, maxFloor2 = %d, and the result time is %f with average total time is %f ",mintotal1, mintotal2,totalrecord1,totalrecord2, minper1, minper2,perecord1, perecord2);

}
