//
// Created by HP User on 11/26/2018.
//

#ifndef MIDTERM2_STANDARD_DEVIATION_HPP
#define MIDTERM2_STANDARD_DEVIATION_HPP
#include <cmath>

using namespace std;

template <typename InputIterator>
auto standardDeviation(InputIterator first, InputIterator last){
    double sum = 0;
    double mean = 0;
    double variance = 0;
    double stdDeviation = 0;
    int count = 0;
    for(auto it = first; it != last; ++it){
        sum += *it;
        ++count;
    }
    mean = sum/count;
    for(auto it = first; it != last; ++it) {
        variance += pow(*it - mean, 2);
    }
    variance=variance/count;
    stdDeviation = sqrt(variance);
    return stdDeviation;
}
#endif //MIDTERM2_STANDARD_DEVIATION_HPP
