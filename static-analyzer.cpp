//
//  static-analyzer.cpp
//  CodeAndCommentLinesParser
//
//  Created by Олег Куколев on 14.01.2021.
//

#include "static-analyzer.hpp"

using namespace std;

//
//  Utility functions
//

void Ltrim(std::string &s);
void Rtrim(std::string &s);
void Trim(const std::string& str);

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

//
//  Class implementation
//

StaticAnalyzer::StaticAnalyzer(const std::string& path) : FileReader{ path } {
  
}

auto StaticAnalyzer::Analyze() -> AnalysisResult {
  AnalysisResult result{
    .code_lines = 0,
    .comment_lines = 0,
    .blank_lines = 0
  };
  
  OpenFile();
  
  for (auto line = ReadNextLine(); !Eof(); line = ReadNextLine()) {
    string trimmed{ line };
    Trim(trimmed);
    
    if (trimmed.empty()) {
      result.blank_lines++;
    }
    else if (trimmed.size() > 1 && trimmed[0] == '/' && trimmed[1] == '/') {
      result.comment_lines++;
    }
    else if (trimmed[0] == '/' && trimmed[1] == '*') {
      bool first = true;
      
      do {
        result.comment_lines++;
        if (!first) {
          trimmed = ReadNextLine();
          Trim(trimmed);
        }
        first = false;
      } while (trimmed.rfind("*/") == string::npos);
    }
    else {
      result.code_lines++;
    }
  }
  
  CloseFile();
  
  return result;
}

AnalysisResult& AnalysisResult::operator+=(const AnalysisResult& other) {
  blank_lines += other.blank_lines;
  comment_lines += other.comment_lines;
  code_lines += other.code_lines;
  return *this;
}

ostream& operator<<(ostream& os, const AnalysisResult& ar) {
  const auto total_lines = ar.blank_lines + ar.code_lines + ar.comment_lines;
  return os << "Total lines: " << total_lines << endl
            << "Blank lines: " << ar.blank_lines << endl
            << "Comment lines: " << ar.comment_lines << endl
            << "Source code lines: " << ar.code_lines;
}
