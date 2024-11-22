#ifndef SUPPLIER_READER_H
#define SUPPLIER_READER_H

#include <vector>
#include <fstream>
#include "utils.h"

// SUPPLIER 데이터를 블록 단위로 읽는 함수
Supplier parseRecord(const string &line);
vector<Supplier> readBlock(ifstream &file, int blockSize);

#endif // SUPPLIER_READER_H