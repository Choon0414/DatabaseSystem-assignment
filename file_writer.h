#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include <vector>
#include <string>

// 결과 데이터를 파일에 저장하는 함수
void saveJoinResults(const std::string &outputFile, const std::vector<std::string> &results);

#endif // FILE_WRITER_H