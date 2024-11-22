#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "nation_reader.h"

using namespace std;

// NATION 테이블의 레코드 구조 정의
struct Nation {
    int nationKey;
    string name;
    int regionKey;
    string comment;
};

// 한 줄 데이터를 Nation 구조체로 파싱
Nation parseRecord(const string &line) {
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
vector<Nation> readBlock(ifstream &file, int blockSize) {
    vector<Nation> block;
    string line;
    int count = 0;

    while (count < blockSize && getline(file, line)) {
        block.push_back(parseRecord(line));
        count++;
    }

    return block;
}
