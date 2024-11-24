#ifndef NATION_READER_H
#define NATION_READER_H

#include <vector>
#include <string>

using namespace std;

// NATION 테이블의 레코드 구조 정의
struct Nation {
    int nationKey;
    string name;
    int regionKey;
    string comment;
};

// NATION 데이터를 읽어 메모리에 로드하는 함수
Nation parseNationRecord(const string &line);
std::vector<Nation> readNationBlock(ifstream &file, int blockSize);

#endif // NATION_READER_H