#include "join_algorithm.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// 테이블 구조 정의
// struct Table {
//     string name;
//     int tupleCount;

//     Table(string tableName, int count) : name(tableName), tupleCount(count) {}
// };

// 테이블 입력
// Table inputTable(ifstream &fileStream) {
//     string tableName;
//     int tupleCount;

//     // 테이블 이름과 튜플 수 읽기
//     if (fileStream >> tableName >> tupleCount) {
//         cout << "Table " << tableName << " with " << tupleCount << " tuples loaded." << endl;
//         return Table(tableName, tupleCount);
//     }

//     throw runtime_error("Failed to read table information from file.");
// }

// // 메인 테이블 결정
// Table decideMainTable(const Table &table1, const Table &table2) {
//     if (table1.tupleCount <= table2.tupleCount) {
//         cout << "Main table: " << table1.name << endl;
//         return table1;
//     } else {
//         cout << "Main table: " << table2.name << endl;
//         return table2;
//     }
// }

// 블록 중첩 루프 조인
void blockNestedLoopJoin(ifstream &supplierStream, const vector<Table> &tables, 
                         ofstream &outputStream, int blockSize) {
    // 고정길이 레코드 블록 중첩 조인 로직 구현 (예시)
    cout << "Performing block nested loop join with block size: " << blockSize << endl;
}