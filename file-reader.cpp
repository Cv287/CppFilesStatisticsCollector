//
//  file-reader.cpp
//  CodeAndCommentLinesParser
//
//  Created by Олег Куколев on 14.01.2021.
//

#include "file-reader.hpp"

using namespace std;

FileReader::FileReader(const std::string& path)
: kFilePath{ path }
{
  
}

void FileReader::OpenFile() {
  file.open(kFilePath, ios::in);
  if (!file) {
    cerr << kFilePath << " not created!" << endl;
  }
}

void FileReader::CloseFile() {
  file.close();
}

bool FileReader::Eof() const {
  return file.eof();
}

std::string FileReader::ReadNextLine() {
  if (!file.eof()) {
    string line;
    getline(file, line, '\n');
    return line;
  }
  throw runtime_error{ "Attempt to read from file on EOF" };
}
