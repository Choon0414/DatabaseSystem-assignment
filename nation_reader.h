#ifndef NATION_READER_H
#define NATION_READER_H

#include <vector>
#include <string>
#include <fstream>

// Nation 구조체 정의
struct Nation {
    int nationKey;            // 국가 키
    std::string name;         // 국가 이름
    int regionKey;            // 지역 키
    std::string comment;      // 주석
};

// Nation 데이터를 파싱하는 함수 선언
Nation parseNationRecord(const std::string &line);

// Nation 데이터를 파일에서 한 번에 로드하는 함수 선언
std::vector<Nation> loadAllNations(std::ifstream &file);

#endif // NATION_READER_H
