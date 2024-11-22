#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "supplier_reader.h"

using namespace std;

// SUPPLIER 테이블의 레코드 구조 정의
struct Supplier {
    int suppKey;
    string name;
    string address;
    int nationKey;
    string phone;
    double acctBal;
    string comment;
};

// 한 줄 데이터를 Supplier 구조체로 파싱
Supplier parseRecord(const string &line) {
    Supplier record;
    istringstream stream(line);
    string field;

    // 필드 분리 및 할당
    getline(stream, field, '|');
    record.suppKey = stoi(field);

    getline(stream, record.name, '|');
    getline(stream, record.address, '|');

    getline(stream, field, '|');
    record.nationKey = stoi(field);

    getline(stream, record.phone, '|');

    getline(stream, field, '|');
    record.acctBal = stod(field);

    getline(stream, record.comment, '|');

    return record;
}

// 파일에서 블록 단위로 읽기
vector<Supplier> readBlock(ifstream &file, int blockSize) {
    vector<Supplier> block;
    string line;
    int count = 0;

    while (count < blockSize && getline(file, line)) {
        block.push_back(parseRecord(line));
        count++;
    }

    return block;
}
