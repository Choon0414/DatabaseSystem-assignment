#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class FileWriter {
private:
    ofstream outputStream;          // 출력 파일 스트림
    vector<string> buffer;          // 메모리 버퍼
    size_t bufferSize;              // 버퍼 크기

public:
    // 생성자: 파일 이름과 버퍼 크기를 설정.
    FileWriter(const string &fileName, size_t bufferSize, bool appendMode = true);

    // 소멸자: 버퍼 플러시 및 파일 닫기
    ~FileWriter();

    // 결과를 버퍼에 추가
    void addResult(const string &result);

    // 버퍼 내용을 파일에 기록ㅇ
    void flushBuffer();
};

#endif // FILE_WRITER_H
