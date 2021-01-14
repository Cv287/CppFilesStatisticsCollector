//
//  file-reader.cpp
//  CodeAndCommentLinesParser
//
//  Created by Олег Куколев on 14.01.2021.
//

#include "file-reader.hpp"

using namespace std;

auto FileReader::ReadFile(const string& filepath) -> vector<string> {
  vector<string> lines;
  ifstream file;

  file.open(filepath, ios::in);
  if (!file) {
    cerr << filepath << " not created!" << endl;
  }

  while (true) {
    string line;
    getline(file, line, '\n');
    lines.push_back(line);
    if (file.eof()) {
      break;
    }
  }

  file.close();
  return lines;
}
