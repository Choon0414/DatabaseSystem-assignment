#include <iostream>
#include <fstream>
#include "supplier_reader.h"
#include "nation_reader.h"
#include "join_algorithm.h"

using namespace std;

int main() {
    string supplierFile = "supplier.tbl";
    string nationFile = "nation.tbl";
    string outputFile = "join_result.csv";
    int blockSize = 100; // 블록 크기 (레코드 수 기준)

    // SUPPLIER 데이터 파일 스트림
    ifstream supplierStream(supplierFile);
    if (!supplierStream.is_open()) {
        cerr << "Error opening supplier file!" << endl;
        return 1;
    }

    // NATION 데이터 읽기
    vector<Nation> nations = readNationData(nationFile);

    // 결과 파일 스트림
    ofstream outputStream(outputFile);
    if (!outputStream.is_open()) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    // 블록 중첩 조인 수행
    blockNestedLoopJoin(supplierStream, nations, outputStream, blockSize);

    cout << "Join completed! Results saved to " << outputFile << endl;

    supplierStream.close();
    outputStream.close();

    return 0;
}