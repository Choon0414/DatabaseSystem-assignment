#ifndef JOIN_ALGORITHM_H
#define JOIN_ALGORITHM_H

#include <fstream>
#include <vector>
#include "table.h"        // Table 클래스 정의
#include "supplier_reader.h" // Supplier 구조체 정의

void blockNestedLoopJoin(std::ifstream &supplierStream, const std::vector<Table> &tables, int blockSize);

#endif // JOIN_ALGORITHM_H
