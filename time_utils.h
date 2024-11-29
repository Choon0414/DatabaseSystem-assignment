#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <chrono>
#include <string>

// 시간 측정 유틸리티 함수 선언
void printElapsedTime(const std::string &taskName,
                      const std::chrono::high_resolution_clock::time_point &start,
                      const std::chrono::high_resolution_clock::time_point &end);

#endif // TIME_UTILS_H
