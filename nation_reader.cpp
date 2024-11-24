#include <iostream>
#include <fstream>
#include <sstream>
#include "nation_reader.h"

using namespace std;

// 한 줄 데이터를 Nation 구조체로 파싱
Nation parseNationRecord(const std::string &line) {
    Nation record;
    istringstream stream(line);
    string field;

    // 필드 분리 및 할당
    getline(stream, field, '|');
    record.nationKey = stoi(field);

    getline(stream, record.name, '|');

    getline(stream, field, '|');
    record.regionKey = stoi(field);

    getline(stream, record.comment, '|');

    return record;
}

// 파일에서 블록 단위로 읽기
vector<Nation> readNationBlock(ifstream &file, int blockSize) {
    vector<Nation> block;
    string line;
    int count = 0;

    while (count < blockSize && getline(file, line)) {
        block.push_back(parseNationRecord(line));
        count++;
    }

    return block;
}
