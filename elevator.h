//
//  elevator.h
//  Project_Math
//
// @author Chen Wang(cwang784)   Haodan Tan(htan74)

#ifndef elevator_h
#define elevator_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *@brief    Produced random number of passengers between lower and upper bounds.
 *@param upper      This is the upper bound of passengers.
 *@Param lower       This is the lower bound of passengers.
 *@return        Random number of passengers
 */
int numOfpass(int upper, int lower);


/**
 *@brief    Generated an array to store each desired floor for each passenger
 *@param totalpass          total number of passengers
 *@return   floor array
 */
int* floorPerpass(int totalpass);


/**
 *@brief    Counted the distinct number of the floor array
 *@param floor      floor array
 *@param totalPass      the total number of passenger
 *@return   the distincet number of the floor array
 */
int countDistinct(int* floor, int totalPass);


/**
 *@brief    Calculated the total time of elevator will take from the lowest floor to highest floor
 *@param floor      floor array
 *@param totalPass      the total number of passenger
 *@return   Calculated the total time of elevator will take from the lowest floor to highest floor
 */
int countHighestFloor(int* floor, int totalPass);


/**
 *@brief    Calculated the total  time of the elevator to get to the highest floor
 *@param highestFloor       The highest floor that passengers want to get
 *@param distinctFloor      The floor array with distinct floors (removed the duplicate floor)
 *@return   total of the elevator to get to the highest floor
 */
int computeTotalTime(int highestFloor, int distinctFloor);


/**
 *@brief    Calculated the average time of per passenger of the elevator to get to the highest floor
 *@param totalTime      the total  time of the elevator to get to the highest floor
 *@param passenger      the total number of the passengers
 *@return   the average time of the elevator to get to the highest floor
 */
double computeAvgTime(double totalTime, int passenger);


/**
 *@brief    Swap two integers
 *@param xp     The pointer to integer x
 *@param yp     The pointer to integer y
 */
void swap(int* xp, int* yp);


/**
 *@brief    Sort the floor array from the lowest floor to highest floor
 *@param floor      floor array
 *@param passenger     the total number of passenger
 */
void sortFloor(int* floor, int passenger);


/**
 *@brief    Compute the total waiting time for every passenger in the elevator ( Passengers who want to get to higher floor must wait for who wants to get to the lower floor )
 *@param floor      floor array
 *@param passenger     the total number of passenger
 *@return   The total waiting time for every passenger in the elevator
 */
double waitTotal(int* floor, int passenger);


/**
 *@brief    Execute the sutuation in scenario 1 for each time (not including 1000 times)
 *@return   the total  time of the elevator to get to the highest floor, and the average time of per passenger to wait for the elevator to get to the highest floor
 */
double* eachTest();


/**
 *@brief    Execute the sutuation in scenario 1  (including 1000 times)
 */
void test1();


/**
 *@brief    Execute the sutuation in scenario 2 for each time (not including 1000 times)
 *@return   the total  time of the elevator to get to the highest floor, and the average time of per passenger to wait for the elevator to get to the highest floor
 */
double* eachTest2();


/**
 *@brief    Execute the sutuation in scenario 2  (including 1000 times)
 */
void test2();


/**
 *@brief    Generate the random floor of each passenger between 1 to maxFloor1
 *@return   The random floor
 */
int* floorPerpass1(int totalpass, int maxFloor1);


/**
 *@brief    Generate the random floor of each passenger between maxFloor1 to the highest floor
 *@return   The random floor
 */
int* floorPerpass2(int totalpass, int maxFloor1);


/**
 *@brief    Execute the sutuation in scenario 3 for each time (not including 1000 times)
 *@return   the total  time of the elevator to get to the highest floor, and the average time of per passenger to wait for the elevator to get to the highest floor
 */
double* eachTest3(int maxFloor);


/**
 *@brief    Execute the sutuation in scenario 3  (including 1000 times)
 */
void test3(int maxFloor);


/**
 *@brief    Execute the sutuation in scenario 4 for each time (not including 1000 times)
 *@return   the total  time of the elevator to get to the highest floor, and the average time of per passenger to wait for the elevator to get to the highest floor
 */
double* eachTest4(int maxFloor1, int maxFloor2);


/**
 *@brief    Execute the sutuation in scenario 4 (including 1000 times)
 */
double* test4(int maxFloor1,int maxFloor2);
#endif /* elevator_h */

