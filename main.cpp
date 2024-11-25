#include <iostream>
#include <fstream>
#include "supplier_reader.h"
#include "nation_reader.h"
#include "file_writer.h"

using namespace std;

int main() {
    // 파일 경로 설정
    string supplierFile = "supplier.tbl";     // Supplier 데이터 파일 경로
    string nationFile = "nation.tbl";         // Nation 데이터 파일 경로
    string outputFile = "output.csv";         // 결과 데이터를 저장할 파일

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

    // Nation 데이터를 한 번에 로드
    vector<Nation> nations = loadAllNations(nationStream);

    // Supplier 데이터를 블록 단위로 로드 및 처리
    FileWriter fileWriter(outputFile, 1000);

    while (!supplierStream.eof()) {
        vector<Supplier> suppliers = readSupplierBlock(supplierStream, 100); // 블록 크기 100

        if (suppliers.empty()) break; // EOF 처리

        for (const auto &supplier : suppliers) {
            // 관련된 Nation 찾기
            string nationName = "Unknown";
            for (const auto &nation : nations) {
                if (nation.nationKey == supplier.nationKey) {
                    nationName = nation.name;
                    break;
                }
            }

            // 결과 데이터를 출력 파일에 추가
            fileWriter.addResult("Supplier Key: " + to_string(supplier.suppKey) +
                                 ", Name: " + supplier.name +
                                 ", Nation: " + nationName +
                                 ", Balance: " + to_string(supplier.acctBal));
        }
    }

    // 스트림 닫기
    supplierStream.close();
    nationStream.close();

    cout << "Data processing completed. Results saved to " << outputFile << endl;

    return 0;
}
