#include "table.h"
#include <stdexcept> // 예외 처리

// 테이블 생성자
Table::Table(const std::string &name) : tableName(name) {}

// 레코드 추가 메서드
void Table::addRecord(int key, const std::vector<std::string> &fields) {
    TableRecord record{key, fields};
    records[key] = record;
}

// 특정 키로 레코드 조회
TableRecord Table::getRecord(int key) const {
    auto it = records.find(key);
    if (it != records.end()) {
        return it->second;
    }
    throw std::out_of_range("Record not found for key: " + std::to_string(key));
}

// 테이블 이름 반환
std::string Table::getTableName() const {
    return tableName;
}
