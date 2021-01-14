//
//  static-analyzer.cpp
//  CodeAndCommentLinesParser
//
//  Created by Олег Куколев on 14.01.2021.
//

#include "static-analyzer.hpp"

//  BLANK LINE examples: "", " ", "\t", " \t"
//  COMMENT
//
//

using namespace std;

// trim from start (in place)
void Ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
void Rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
void Trim(std::string &s) {
    Ltrim(s);
    Rtrim(s);
}

AnalysisResult& AnalysisResult::operator+=(const AnalysisResult& other) {
  total_lines += other.total_lines;
  blank_lines += other.blank_lines;
  comment_lines += other.comment_lines;
  code_lines += other.code_lines;
  return *this;
}

ostream& operator<<(ostream& os, const AnalysisResult& ar) {
  return os << "Total lines: " << ar.total_lines << endl
            << "Blank lines: " << ar.blank_lines << endl
            << "Comment lines: " << ar.comment_lines << endl
            << "Source code lines: " << ar.code_lines;
}

auto StaticAnalyzer::Analyze(_VectorString file_content) -> AnalysisResult {
  AnalysisResult result{
    .total_lines = file_content.size()
  };
  
  for (const auto& line : file_content) {
    string trimmed{ line };
    Trim(trimmed);
    
    if (trimmed.empty()) {
      result.blank_lines++;
    }
    else if (trimmed.size() > 1 && trimmed[0] == '/' && trimmed[1] == '/') {
      result.comment_lines++;
    }
    else if (trimmed[0] == '/' && trimmed[1] == '*') {
      do {
        result.comment_lines++;
      } while (trimmed.find("*/") != string::npos);
    }
    else {
      result.code_lines++;
    }
  }
  
  return result;
}
