#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>

#define FILE_NAME "random_array.txt"
#define SIZE 10
#define MAX 50
#define NEG_INFI -999999

void generateIntArrayToFile(int size){
    // TODO
}

std::vector<int> getIntArrayFromFile(){
    // TODO
}

int algorithm01(std::vector<int> a){
    // TODO
}

int algorithm02(std::vector<int> a){
    // TODO
}

int maxLeft(std::vector<int> a, int i, int j){
    // TODO
}

int maxRight(std::vector<int> a, int i, int j){
    // TODO
}

int maxSub(std::vector<int> a, int i, int j){
    // TODO
}

int algorithm03(std::vector<int> a){
    // TODO
}

int main(){
    // Initial random array and write to file
    // generateIntArrayToFile( SIZE );

    // Read the array from file
    std::vector<int> a = getIntArrayFromFile();
    
    std::cout << "\nStart Program ..." << std::endl;
    std::chrono::steady_clock sc;   // create an object of 'steady_clock' class
    auto start = sc.now();          // start timer

    // Algorithm
    int maxSum = algorithm01(a);
    // int maxSum = algorithm02(a);
    // int maxSum = algorithm03(a);

    std::cout << "The maximum weight of sub array is: " << maxSum << std::endl;

    // Calculate span time of the operation
    auto end = sc.now();     // end timer
    auto time_span = static_cast<std::chrono::duration<double>>(end - start);   // measure time span between start & end
    std::cout << "\nOperation took: " << time_span.count() << " second !!! " << std::endl;
    std::cout << "\nEnd Program" << std::endl;
    return 0;
}