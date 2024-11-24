#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "supplier_reader.h"
#include "nation_reader.h"
// #include "join_algorithm.h"

#include "supplier_reader.cpp"
#include "nation_reader.cpp"
// 왠지 모르겠으나 .h 파일과 .cpp 파일의 링킹이 안됨
// 계속 빌드하면 해당 헤더 파일의 구현부(.cpp)를 찾지 못한다고 에러 뜸.
// 임시로 .cpp를 직접 include 해서 사용중

using namespace std;

int main() {
    string staticRoot = "C://Users//user//Desktop//DatabaseSystem//database_system//";
    string supplierRoot = "TPC-H V3.0.1//dbgen//supplier.tbl";
    string nationRoot = "TPC-H V3.0.1//dbgen//nation.tbl";
    string output = "TPC-H V3.0.1//join_result.csv";
    int blockSize = 100; // 블록 크기 (레코드 수 기준)

    // supplier, nation 파일 열기
    ifstream supplierStream(staticRoot + supplierRoot);
    ifstream nationStream(staticRoot + nationRoot);

    if (!supplierStream.is_open()) {
        cerr << "Error opening supplier file!" << endl;
        return 1;
    }
    if (!nationStream.is_open()) {
        cerr << "Error opening nation file!" << endl;
        return 1;
    }

    cout << "Success Open All File!" << endl;

    // Supplier 블럭화 하여 결과 출력
    int supplierBlockNum = 1;
    int nationBlockNum = 1; 

    while (!supplierStream.eof()) {
        vector<Supplier> suppliers = readSupplierBlock(supplierStream, blockSize);

        if (suppliers.empty()) {
            break;
        }

        cout << "Supplier Block Number: " << supplierBlockNum << endl;

        for (const auto &supplier : suppliers) {
            cout << "Supplier Key: " << supplier.suppKey 
                << ", Name: " << supplier.name << std::endl;
        }

        supplierBlockNum++;
    }

    // Nation 블럭화 후 결과 출력
    while (!nationStream.eof()) {
        vector<Nation> nations = readNationBlock(nationStream, blockSize);

        if (nations.empty()) {
            break;
        }

        cout << "Nation Block Number: " << nationBlockNum << endl;

        for (const auto &nation : nations) {
            cout << "Nation Key: " << nation.nationKey 
                      << ", Name: " << nation.name << std::endl;
        }

        nationBlockNum++;
    }

    // 파일 닫기
    supplierStream.close();
    nationStream.close();

    return 0;
}