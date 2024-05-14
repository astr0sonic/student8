#include "max_value.h"
#include<fstream>
#include<iostream>
#include<queue>
using namespace std;

double calculateMaxValue(double* nums, int n){
    std::queue<double> q;
    
    q.push(nums[0]);
    
    for (int i = 1; i < n; i++) {
        int size = q.size();
        for (int j = 0; j < size; j++) {
            double front = q.front();
            q.pop();
            
            q.push(front + nums[i]);
            q.push(front - nums[i]);
            q.push(front * nums[i]);
            if (nums[i] != 0) {
                q.push(front / nums[i]);
            }
        }
    }
    
    double max_val = q.front();
    q.pop();
    while (!q.empty()) {
        max_val = std::max(max_val, q.front());
        q.pop();
    }
    
    return max_val;
}
