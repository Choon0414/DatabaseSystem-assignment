#ifndef SUPPLIER_READER_H
#define SUPPLIER_READER_H

#include <vector>
#include <fstream>
#include <string>

// SUPPLIER 테이블의 레코드 구조 정의
struct Supplier {
    int suppKey;
    std::string name;
    std::string address;
    int nationKey;
    std::string phone;
    double acctBal;
    std::string comment;
};

// SUPPLIER 데이터를 블록 단위로 읽는 함수
Supplier parseSupplierRecord(const std::string &line);
std::vector<Supplier> readSupplierBlock(std::ifstream &file, int blockSize);

#endif // SUPPLIER_READER_H