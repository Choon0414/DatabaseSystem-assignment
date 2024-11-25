#ifndef SUPPLIER_READER_H
#define SUPPLIER_READER_H

#include <vector>
#include <string>
#include <fstream>

// Supplier 구조체 정의
struct Supplier {
    int suppKey;              // 공급자 키
    std::string name;         // 공급자 이름
    std::string address;      // 공급자 주소
    int nationKey;            // 국가 키
    std::string phone;        // 전화번호
    double acctBal;           // 계정 잔고
    std::string comment;      // 주석
};

// Supplier 파일 읽기 함수 선언
Supplier parseSupplierRecord(const std::string &line);
std::vector<Supplier> readSupplierBlock(std::ifstream &file, int blockSize);

#endif // SUPPLIER_READER_H
