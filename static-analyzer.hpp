//
//  -analyzer.hpp
//  CodeAndCommentLinesParser
//
//  Created by Олег Куколев on 14.01.2021.
//

#ifndef _analyzer_hpp
#define _analyzer_hpp

#include <iostream>
#include <string>

#include "file-reader.hpp"

/* Forward declaration. */
struct AnalysisResult;

//
//  This class is designed for reading a c/cpp file line by line
//  and analyze its content by dividing it into 3 groups:
//    1. source code lines
//    2. comment lines
//    3. blank lines
//

class StaticAnalyzer : public FileReader {
public:
  StaticAnalyzer(const std::string& path);
  auto Analyze() -> AnalysisResult;
};

/* Represents static analysis statistics results. */
struct AnalysisResult {
  unsigned long long blank_lines;
  unsigned long long comment_lines;
  unsigned long long code_lines;
  
  AnalysisResult& operator+=(const AnalysisResult& other);
};

std::ostream& operator<<(std::ostream& os, const AnalysisResult& ar);

#endif /* _analyzer_hpp */
