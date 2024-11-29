#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> // 시간 측정
#include "supplier_reader.h"
#include "nation_reader.h"
#include "file_writer.h"
#include "join_algorithm.h"
#include "table.h"
#include "time_utils.h" // 시간 측정 유틸리티

using namespace std;
using namespace chrono;

int main() {
    // 파일 경로 설정
    string supplierFile = "supplier.tbl"; // Supplier 데이터 파일 경로
    string nationFile = "nation.tbl";     // Nation 데이터 파일 경로
    string outputFile = "output.csv";     // 결과 데이터를 저장할 파일

    // 전체 시간 측정 시작
    auto overallStart = high_resolution_clock::now();

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

    // 시간 저장 변수
    double loadTime = 0.0;
    double joinTime = 0.0;
    double outputTime = 0.0;
    double overallTime = 0.0;

    // 데이터를 읽는 시간 측정
    auto loadStart = high_resolution_clock::now();

    // Nation 데이터를 테이블에 로드
    Table nationTable("Nation");
    vector<Nation> nations = loadAllNations(nationStream);
    for (const auto &nation : nations) {
        nationTable.addRecord(nation.nationKey, {nation.name});
    }

    // 조인에 사용할 테이블 벡터
    vector<Table> tables = {nationTable};

    auto loadEnd = high_resolution_clock::now();
    loadTime = duration_cast<duration<double>>(loadEnd - loadStart).count();

    // 조인 연산 시간 측정
    auto joinStart = high_resolution_clock::now();

    // 블록 중첩 조인 수행 및 결과 파일에 저장
    FileWriter fileWriter(outputFile, 1000); // 버퍼 크기 1000
    blockNestedLoopJoin(supplierStream, tables, 100); // 블록 크기 100

    auto joinEnd = high_resolution_clock::now();
    joinTime = duration_cast<duration<double>>(joinEnd - joinStart).count();

    // 전체 과정 시간 측정
    auto overallEnd = high_resolution_clock::now();
    overallTime = duration_cast<duration<double>>(overallEnd - overallStart).count();

    // 스트림 닫기
    supplierStream.close();
    nationStream.close();

    // 최종 시간 출력
    cout << "\n=== Time Summary ===" << endl;
    cout << "Loading data took: " << loadTime << " seconds" << endl;
    cout << "Join operation took: " << joinTime << " seconds" << endl;
    cout << "Output writing took: " << outputTime << " seconds" << endl;
    cout << "Overall processing took: " << overallTime << " seconds" << endl;
    cout << "=====================" << endl;
    cout << "Data processing completed. Results saved to " << outputFile << endl;

    return 0;
}
