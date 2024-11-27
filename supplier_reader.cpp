#include "supplier_reader.h"
#include <sstream>

// 한 줄 데이터를 Supplier 구조체로 파싱
Supplier parseSupplierRecord(const std::string &line) {
    Supplier record;
    std::istringstream stream(line);
    std::string field;

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
std::vector<Supplier> readSupplierBlock(std::ifstream &file, int blockSize) {
    std::vector<Supplier> block;
    std::string line;
    int count = 0;

    while (count < blockSize && getline(file, line)) {
        block.push_back(parseSupplierRecord(line));
        count++;
    }

    return block;
}
