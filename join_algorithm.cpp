#include "join_algorithm.h"
#include "table.h" // Table 클래스 정의 포함
#include "supplier_reader.h"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

// 블록 중첩 조인 함수
void blockNestedLoopJoin(ifstream &supplierStream, const vector<Table> &tables, int blockSize) {
    // 조인 로직 구현
    while (!supplierStream.eof()) {
        vector<Supplier> suppliers = readSupplierBlock(supplierStream, blockSize);

        for (const auto &supplier : suppliers) {
            for (const auto &table : tables) {
                // 조건: Supplier의 nationKey와 Table의 레코드 key가 일치
                try {
                    TableRecord record = table.getRecord(supplier.nationKey);
                    cout << "Join Result: Supplier " << supplier.name
                         << " -> Nation " << record.fields[0] << endl;
                } catch (const out_of_range &e) {
                    // 테이블에 키가 없을 경우 처리
                    cerr << "Record not found for key: " << supplier.nationKey << endl;
                }
            }
        }
    }
}
