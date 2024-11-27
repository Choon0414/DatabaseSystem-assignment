#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include <vector>
#include <string>
#include <fstream>

class FileWriter {
private:
    std::ofstream outputStream;          // 출력 파일 스트림
    std::vector<std::string> buffer;     // 메모리 버퍼
    size_t bufferSize;                   // 버퍼 크기

public:
    // 생성자
    FileWriter(const std::string &fileName, size_t bufferSize, bool appendMode = true);

    // 소멸자
    ~FileWriter();

    // 결과 추가
    void addResult(const std::string &result);

    // 버퍼 플러시
    void flushBuffer();
};

#endif // FILE_WRITER_H
