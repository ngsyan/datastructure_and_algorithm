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
    std::ofstream myfile;
    myfile.open(FILE_NAME);
    
    srand( (unsigned)time( NULL ));
    
    for(int i=0; i<size; i++){
        int rand_num = std::rand()%MAX - int(MAX/2);
        myfile << rand_num << '\n';
    }
}

std::vector<int> getIntArrayFromFile(){
    std::string line;
    std::vector<int> a;
    std::ifstream myfile (FILE_NAME);
    if(myfile.is_open()){
        while( std::getline(myfile, line) ){
            a.push_back( std::stoi(line) );
        }
    }
    std::cout << std::endl;

    return a;
}

int algorithm01(std::vector<int> a){
    int maxSum = NEG_INFI;
    for (int i=0; i<a.size(); i++){
        for(int j=i; j<a.size(); j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum += a[k];
            }
            if(sum > maxSum){
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

int algorithm02(std::vector<int> a){
    int maxSum = NEG_INFI;
    for (int i=0; i<a.size(); i++){
        int sum = 0;
        for(int j=i; j<a.size(); j++){
            sum += a[j];
            if(sum > maxSum){
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

int maxLeft(std::vector<int> a, int i, int j){
    int maxSum = NEG_INFI;
    int sum = 0;
    for(int k=j; k>=i; k--){
        sum += a[k];
        if(sum > maxSum){
            maxSum = sum;
        }
    }
    return maxSum;
}

int maxRight(std::vector<int> a, int i, int j){
    int maxSum = NEG_INFI;
    int sum = 0;
    for(int k=i; k<=j; k++){
        sum += a[k];
        if(sum > maxSum){
            maxSum = sum;
        }
    }
    return maxSum;
}

int maxSub(std::vector<int> a, int i, int j){
    if(i == j){
        return a[i];
    }

    int maxSum = NEG_INFI;
    int m = int( (i+j)/2 );
    int wL = maxSub(a, i, m);
    int wR = maxSub(a, m+1, j);
    int wM = maxLeft(a, i, m) + maxRight(a, m+1, j);

    if(maxSum < wL){
        maxSum = wL;
    }

    if(maxSum < wR){
        maxSum = wR;
    }
    
    if(maxSum < wM){
        maxSum = wM;
    }

    return maxSum;
}

int algorithm03(std::vector<int> a){
    int maxSum = maxSub(a, 0, a.size()-1);
    return maxSum;
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