#include "nation_reader.h"
#include <sstream>

// 한 줄 데이터를 Nation 구조체로 파싱
Nation parseNationRecord(const std::string &line) {
    Nation record;
    std::istringstream stream(line);
    std::string field;

    // 각 필드를 분리하여 Nation 구조체에 저장
    getline(stream, field, '|');
    record.nationKey = stoi(field);

    getline(stream, record.name, '|');

    getline(stream, field, '|');
    record.regionKey = stoi(field);

    getline(stream, record.comment, '|');

    return record;
}

// 파일에서 Nation 데이터를 한 번에 로드
std::vector<Nation> loadAllNations(std::ifstream &file) {
    std::vector<Nation> nations; // Nation 데이터를 저장할 벡터
    std::string line;

    // 파일의 모든 라인을 읽어 파싱
    while (getline(file, line)) {
        nations.push_back(parseNationRecord(line));
    }

    return nations;
}
