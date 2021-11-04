//
//  elevator.c
//  Project_Math
//
//  Created by Haodan Tan on 9/8/21.


#include "elevator.h"

// Generate the total number of the passengers
int numOfpass(int upper, int lower){
    int numOfpass = (rand() % (upper - lower + 1)) + lower;
    return numOfpass;
}


// Generate the random floor of each passenger
int* floorPerpass(int totalpass){
    int* floor = (int*)malloc(sizeof(int) * totalpass); // return an array as a result in a function
    int flr = 0;
    
    for (int i=0; i < totalpass; i++){
        flr = (rand() % (20 - 2 + 1)) + 2; // the lower floor is the 1st floor
        floor[i] = flr;
    }
    return floor;
}


// Generate the random floor of each passenger between 1 to maxFloor1
int* floorPerpass1(int totalpass, int maxFloor1){
    int* floor = (int*)malloc(sizeof(int) * totalpass); // return an array as a result in a function
    int flr = 0;
    
    for (int i=0; i < totalpass; i++){
        flr = (rand() % (maxFloor1 - 2 + 1)) + 2; // the lower floor is the 1st floor
        floor[i] = flr;
    }
    return floor;
}


// Generate the random floor of each passenger between maxFloor1 to floor
int* floorPerpass2(int totalpass, int maxFloor1){
    int* floor = (int*)malloc(sizeof(int) * totalpass); // return an array as a result in a function
    int flr = 0;
    
    for (int i=0; i < totalpass; i++){
        flr = (rand() % (20 - (maxFloor1 + 1) + 1)) + (maxFloor1 + 1); // the lower floor is the 1st floor
        floor[i] = flr;
    }
    return floor;
}


// Compute the number of distinct floor（还没跑出来）
int countDistinct(int* floor, int totalPass)
{
    int num = 0; // store the total number of distinct number in array
    for (int i=0; i<totalPass;i++){
        int j = 0;
        for (j=0; j<i;j++){
            if (floor[i] == floor[j])
                break;
        }
        if (i == j)
            num++;
    }
    
    return num;
}


// Compute the number of largest floor
int countHighestFloor(int* floor, int totalPass)
{
    int i;
    int max = floor[0];
    
    for (i = 1; i < totalPass; i++)
        if (floor[i] > max)
            max = floor[i];
    
    
    return max;
}


// Compute the total time and average time
int computeTotalTime(int highestFloor, int distinctFloor){
    int totalTime = (highestFloor - 1) * 3 + distinctFloor * 15;
    
    if (distinctFloor == 0) {
        return 0;
    }
    return totalTime;
    
}


//Swap two elements of one array
void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


//sort the floor in ascend
void sortFloor(int* floor, int passenger){
    int i, j, min;
    
    for (i = 0; i < passenger - 1; i++) {
        min = i;
        for (j = i + 1; j<passenger; j++) {
            if (floor[j] < floor[min])
                min = j;
        }
        
        swap(&floor[min], &floor[i]);
    }
}


// Coumpute total waiting time of passenger
double waitTotal(int* floor, int passenger){
    int uniq;
    double sum = 0;
    for(int loop = 1; loop <= passenger; loop++){
        uniq = countDistinct(floor, loop);
        sum += (floor[loop - 1] - 1) * 3 + uniq * 15;
    }
    if (sum < 0) {
        return 0;
    }
    return sum;
}


// Coumpute average waiting time of passenger
double computeAvgTime(double totalTime, int passenger){
    double avgTime = totalTime / (double)passenger;
    return avgTime;
}


// Test in scenario 1 (without 1000 times)
double* eachTest(){
    double eachTime[2];
    
    // Generate the total number of passengers
    int passenger = numOfpass(18, 1);
    int* floor = floorPerpass(passenger);

    // Compute the number of distinct floor
    int distinctFloor = countDistinct(floor, passenger);
    // printf("\n There are %d distinct floor in the elevator\n", distinctFloor);
    
    
    // Compute the highest floor
    int highestFloor = countHighestFloor(floor, passenger);
    // printf("The highest floor is %d \n.", highestFloor);
    
    
    // Complete the elevator total running time and the average time per passenger
    int totalTime = computeTotalTime(highestFloor, distinctFloor);
    sortFloor(floor, passenger);
    double waitTotalPass = waitTotal(floor, passenger);
    double averageTime = computeAvgTime(waitTotalPass, passenger);

    
    
    eachTime[0] = totalTime;
    eachTime[1] = averageTime;
    return eachTime;
    
}


// Test in scenario 1 (with 1000 times)
void test1(){
    time_t t;
    double minTotal = 1000000; // min of total
    double maxTotal = 0;       // max of total
    double totalTotal = 0;    // 1000 times of total
    double avgTotal;          // avg of 1000 times of total
    double totalAvg = 0;      // total of avg
    double perPass = 0;       // per pass
    
    srand((unsigned) time(&t));
    // Repeat 1000 times
    for (int i=0; i<1000;i++){
        double* p = eachTest();
        if (p[0] < minTotal)
            minTotal = p[0];
        
        if (p[0] > maxTotal)
            maxTotal = p[0];
        
        totalTotal += p[0];
        totalAvg += p[1];
    }
    
    avgTotal = totalTotal / 1000;
    perPass = totalAvg / 1000;
    
    printf("The result of Scenario 1:\n");
    printf("\n The average of total time is %f \n the minimum of total time is %f \n the maximum of the total time is %f \n The average time per passenger is: %f", avgTotal, minTotal, maxTotal,perPass);
    
}


// Test in scenario 2 (without 1000 times)
double* eachTest2(){
    double eachTime[2];
    int passenger = numOfpass(18, 1);
    int passenger1 = numOfpass(passenger, 1);
    int passenger2 = passenger - passenger1;
    
    
    
    // Generate the random floor of each passenger
    // printf("\n Every passenger have the different floor to go:");
    int* floor1 = floorPerpass(passenger1);
    int* floor2 = floorPerpass(passenger2);

    
    // Compute the number of distinct floor
    int distinctFloor1 = countDistinct(floor1, passenger1);
    int distinctFloor2 = countDistinct(floor2, passenger2);

    
    // Compute the highest floor
    int highestFloor1 = countHighestFloor(floor1, passenger1);
    int highestFloor2 = countHighestFloor(floor2, passenger2);

    //
    // Complete the elevator total running time and the average time per passenger
    double totalTime1 = computeTotalTime(highestFloor1, distinctFloor1);
    double totalTime2 = computeTotalTime(highestFloor2, distinctFloor2);
    
    
    
    sortFloor(floor1, passenger1);
    sortFloor(floor2, passenger2);
    double waitTotalPass1 = waitTotal(floor1, passenger1);
    double waitTotalPass2 = waitTotal(floor2, passenger2);
    
    double averageTime = (waitTotalPass1 + waitTotalPass2) / passenger;

    
    double totalTime;
    
    if (totalTime1 > totalTime2) {
        totalTime = totalTime1;
    }
    else{
        totalTime = totalTime2;
    }

    eachTime[0] = totalTime;
    eachTime[1] = averageTime;
    return eachTime;
}


// Test in scenario 1 (with 1000 times)
void test2(){
    time_t t;
    double minTotal = 1000000; // min of total
    double maxTotal = 0;       // max of total
    double totalTotal = 0;    // 1000 times of total
    double avgTotal;          // avg of 1000 times of total
    double totalAvg = 0;      // total of avg
    double perPass = 0;       // per pass
    double p[2];
    
    
    srand((unsigned) time(&t));
    // Repeat 1000 times
    for (int i=0; i<1000;i++){
        double* p = eachTest2();
        
        
        if (p[0] < minTotal)
            minTotal = p[0];
        
        if (p[0] > maxTotal)
            maxTotal = p[0];
        
        totalTotal += p[0];
        totalAvg += p[1];
    }
    
    avgTotal = totalTotal / 1000;
    perPass = totalAvg / 1000;
    
    
    
    printf("\n \n \nThe result of Scenario 2:\n");
    printf("\n The average of the total time is %f \n the minimum of the total time is %f \n the maximum of the total time is %f \n The average time per passenger is: %f", avgTotal, minTotal, maxTotal,perPass);
}


// Test in scenario 3 (without 1000 times)
double* eachTest3(int maxFloor){
    
    double eachTime[2];
    int passenger = numOfpass(18, 1);  // generate the number of total number
    int* floor = floorPerpass(passenger);
    sortFloor(floor, passenger);
    int maxFloor1 = maxFloor;

    // Seperate passengers into two elevalors by using the maxFloor1
    int passenger1=0;
    for (int i=0; i<passenger;i++){
        // no passenger in elevator 1
        if (maxFloor1 < floor[0])
            passenger1 = 0;
        if (floor[i] <= maxFloor1)
            passenger1 ++;
        
    }

    
    int passenger2 = passenger - passenger1;
    
    int* floor1 = floor;
    int* floor2 = floor + passenger1;
    

    // Compute the number of distinct floor
    int distinctFloor1 = countDistinct(floor1, passenger1);
    int distinctFloor2 = countDistinct(floor2, passenger2);

    
    // Compute the highest floor
    int highestFloor1 = countHighestFloor(floor1, passenger1);
    int highestFloor2 = countHighestFloor(floor2, passenger2);

    
    // Complete the elevator total running time and the average time per passenger
    double totalTime1 = computeTotalTime(highestFloor1, distinctFloor1);
    double totalTime2 = computeTotalTime(highestFloor2, distinctFloor2);
    
    
    double waitTotalPass1 = waitTotal(floor1, passenger1);
    double waitTotalPass2 = waitTotal(floor2, passenger2);
    
    if (waitTotalPass1 < 0) {
        waitTotalPass1 = 0;
    }
    if (waitTotalPass2 < 0) {
        waitTotalPass2 = 0;
    }
    double averageTime = (waitTotalPass1 + waitTotalPass2) / passenger;
    
    
    double totalTime;
    
    if (totalTime1 > totalTime2) {
        totalTime = totalTime1;
    }
    else{
        totalTime = totalTime2;
    }
    

    eachTime[0] = totalTime;
    eachTime[1] = averageTime;

    return eachTime;
    
    
}


// Test in scenario 3 (with 1000 times)
void test3(int maxFloor){
    time_t t;
    double minTotal = 1000000; // min of total
    double maxTotal = 0;       // max of total
    double totalTotal = 0;    // 1000 times of total
    double avgTotal;          // avg of 1000 times of total
    double totalAvg = 0;      // total of avg
    double perPass = 0;       // per pass
    double p[2];
    
    
    srand((unsigned) time(&t));
    // Repeat 1000 times
    for (int i=0; i<1000;i++){
        double* p = eachTest3(maxFloor);
        
        
        if (p[0] < minTotal)
            minTotal = p[0];
        
        if (p[0] > maxTotal)
            maxTotal = p[0];
        
        totalTotal += p[0];
        totalAvg += p[1];
    }
    
    avgTotal = totalTotal / 1000;
    // printf("The totaltime is %f", avgTotal);
    perPass = totalAvg / 1000;
    //    printf("\njiu ta ma hen lipu %f", totalTotal);
    
    
    printf("\n The average of the total time is %f \n the minimum of the total time is %f \n the maximum of the total time is %f \n The average time per passenger is: %f", avgTotal, minTotal, maxTotal,perPass);
}


// Test in scenario 4 (without 1000 times)
double* eachTest4(int maxFloor1, int maxFloor2){
    double eachTime[2];
    int passenger = numOfpass(18, 1);  // generate the number of total number
    int* floor = floorPerpass(passenger);
    sortFloor(floor, passenger);


    // Seperate passengers into two elevalors by using the maxFloor1
    int passenger1=0;
    int passenger2 =0;
    for (int i=0; i<passenger;i++){
        if (floor[i] <= maxFloor1) {
            passenger1++;
        }
        if (floor[i] > maxFloor1 && floor[i] <= maxFloor2 ) {
            passenger2++;
        }
    }


    int passenger3 = passenger - passenger1 - passenger2;


    int* floor1 = floor;
    int* floor2 = floor + passenger1;
    int* floor3 = floor + passenger1 + passenger2;
    


    // Compute the number of distinct floor
    int distinctFloor1 = countDistinct(floor1, passenger1);
    int distinctFloor2 = countDistinct(floor2, passenger2);
    int distinctFloor3 = countDistinct(floor3, passenger3);

    
    // Compute the highest floor
    int highestFloor1 = countHighestFloor(floor1, passenger1);
    int highestFloor2 = countHighestFloor(floor2, passenger2);
    int highestFloor3 = countHighestFloor(floor3, passenger3);

    

    // Complete the elevator total running time and the average time per passenger
    double totalTime1 = computeTotalTime(highestFloor1, distinctFloor1);
    double totalTime2 = computeTotalTime(highestFloor2, distinctFloor2);
    double totalTime3 = computeTotalTime(highestFloor3, distinctFloor3);


    double waitTotalPass1 = waitTotal(floor1, passenger1);
    double waitTotalPass2 = waitTotal(floor2, passenger2);
    double waitTotalPass3 = waitTotal(floor3, passenger3);


    double averageTime = (waitTotalPass1 + waitTotalPass2 + waitTotalPass3) / passenger;


    double comparingtime = totalTime1;
    
    if (comparingtime < totalTime2) {
        comparingtime = totalTime2;
    }
    if (comparingtime < totalTime3) {
        comparingtime = totalTime3;
    }

    eachTime[0] = comparingtime;
    eachTime[1] = averageTime;
    
    
    return eachTime;
}


// Test in scenario 4 (with 1000 times)
double* test4(int maxFloor1,int maxFloor2){
    time_t t;
    double minTotal = 1000000; // min of total
    double maxTotal = 0;       // max of total
    double totalTotal = 0;    // 1000 times of total
    double avgTotal;          // avg of 1000 times of total
    double totalAvg = 0;      // total of avg
    double perPass = 0;       // per pass
    double p[2];
    double testresult[2];
    
    
    srand((unsigned) time(&t));
    
    
    // Repeat 1000 times
    for (int i=0; i<1000;i++){
        double* p = eachTest4(maxFloor1,maxFloor2);
        
        
        if (p[0] < minTotal)
            minTotal = p[0];
        
        if (p[0] > maxTotal)
            maxTotal = p[0];
        
        totalTotal += p[0];
        totalAvg += p[1];
    }
    
    avgTotal = totalTotal / 1000;
    perPass = totalAvg / 1000;

    
    testresult[0] = avgTotal;
    testresult[1] = perPass;
    return testresult;

}
