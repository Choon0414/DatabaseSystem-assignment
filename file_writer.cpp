#include "file_writer.h"
#include <stdexcept>
#include <iostream>

// 생성자: 파일 열기 및 버퍼 초기화
FileWriter::FileWriter(const std::string &fileName, size_t bufferSize, bool appendMode)
    : bufferSize(bufferSize) {
    if (appendMode) {
        outputStream.open(fileName, std::ios::app);
    } else {
        outputStream.open(fileName);
    }

    if (!outputStream.is_open()) {
        throw std::runtime_error("Error: Could not open output file: " + fileName);
    }

    buffer.reserve(bufferSize);
}

// 소멸자: 버퍼 플러시 및 파일 닫기
FileWriter::~FileWriter() {
    flushBuffer();
    outputStream.close();
}

// 결과를 버퍼에 추가
void FileWriter::addResult(const std::string &result) {
    buffer.push_back(result);
    if (buffer.size() >= bufferSize) {
        flushBuffer();
    }
}

// 버퍼 내용을 파일에 기록
void FileWriter::flushBuffer() {
    for (const auto &line : buffer) {
        outputStream << line << "\n";
    }
    buffer.clear();
}
