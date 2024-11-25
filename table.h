#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include <unordered_map>

// 테이블 레코드를 나타내는 구조체
struct TableRecord {
    int key;
    std::vector<std::string> fields; // 필드 데이터
};

// 테이블 클래스 정의
class Table {
private:
    std::string tableName;                         // 테이블 이름
    std::unordered_map<int, TableRecord> records; // 키 기반 레코드 저장

public:
    Table(const std::string &name); // 생성자

    // 레코드 추가
    void addRecord(int key, const std::vector<std::string> &fields);

    // 특정 키로 레코드 조회
    TableRecord getRecord(int key) const;

    // 테이블 이름 반환
    std::string getTableName() const;
};

#endif // TABLE_H
