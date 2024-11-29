#include "time_utils.h"
#include <iostream>

using namespace std;
using namespace chrono;

// 시간 측정 결과를 출력하는 함수 구현
void printElapsedTime(const string &taskName,
                      const high_resolution_clock::time_point &start,
                      const high_resolution_clock::time_point &end) {
    chrono::duration<double> duration = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << taskName << " took " << duration.count() << " seconds" << endl;
}
