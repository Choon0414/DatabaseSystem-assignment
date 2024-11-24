#ifndef JOIN_ALGORITHM_H
#define JOIN_ALGORITHM_H

#include <vector>
#include <fstream>
#include "supplier_reader.h"
#include "nation_reader.h"

using namespace std;

// 테이블 입력
void inputTable();

// 메인 테이블 결정
void decideMainTable();

// 블록 중첩 조인 수행 함수
void blockNestedLoopJoin(std::ifstream &supplierStream, const std::vector<Nation> &nations, 
                         std::ofstream &outputStream, int blockSize);

#endif // JOIN_ALGORITHM_H