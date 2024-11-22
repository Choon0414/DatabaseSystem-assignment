#ifndef NATION_READER_H
#define NATION_READER_H

#include <vector>
#include <string>
#include "utils.h"

// NATION 데이터를 읽어 메모리에 로드하는 함수
Nation parseRecord(const string &line);
vector<Nation> readBlock(ifstream &file, int blockSize);

#endif // NATION_READER_H