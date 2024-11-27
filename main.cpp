#include <iostream>
#include <fstream>
#include <vector>
#include "supplier_reader.h"
#include "nation_reader.h"
#include "file_writer.h"
#include "join_algorithm.h"
#include "table.h"

using namespace std;

int main() {
    // 파일 경로 설정
    string supplierFile = "supplier.tbl"; // Supplier 데이터 파일 경로
    string nationFile = "nation.tbl";     // Nation 데이터 파일 경로
    string outputFile = "output.csv";     // 결과 데이터를 저장할 파일

    // Supplier 파일 열기
    ifstream supplierStream(supplierFile);
    if (!supplierStream.is_open()) {
        cerr << "Error opening supplier file!" << endl;
        return 1;
    }

    // Nation 파일 열기
    ifstream nationStream(nationFile);
    if (!nationStream.is_open()) {
        cerr << "Error opening nation file!" << endl;
        return 1;
    }

    // Nation 데이터를 테이블에 로드
    Table nationTable("Nation");
    vector<Nation> nations = loadAllNations(nationStream);
    for (const auto &nation : nations) {
        nationTable.addRecord(nation.nationKey, {nation.name});
    }

    // 조인에 사용할 테이블 벡터
    vector<Table> tables = {nationTable};

    // 블록 중첩 조인 수행 및 결과 파일에 저장
    FileWriter fileWriter(outputFile, 1000); // 버퍼 크기 1000
    blockNestedLoopJoin(supplierStream, tables, 100); // 블록 크기 100

    // 스트림 닫기
    supplierStream.close();
    nationStream.close();

    cout << "Data processing completed. Results saved to " << outputFile << endl;

    return 0;
}
