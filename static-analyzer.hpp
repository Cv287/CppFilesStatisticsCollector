//
//  -analyzer.hpp
//  CodeAndCommentLinesParser
//
//  Created by Олег Куколев on 14.01.2021.
//

#ifndef _analyzer_hpp
#define _analyzer_hpp

#include <iostream>
#include <vector>
#include <string>

void Ltrim(std::string &s);
void Rtrim(std::string &s);
void Trim(const std::string& str);

struct AnalysisResult {
  unsigned long long total_lines;
  unsigned long long blank_lines;
  unsigned long long comment_lines;
  unsigned long long code_lines;
  
  AnalysisResult& operator+=(const AnalysisResult& other);
};



std::ostream& operator<<(std::ostream& os, const AnalysisResult& ar);

using _VectorString = std::vector<std::string>;
class StaticAnalyzer {
public:
   static auto Analyze(_VectorString file_content) -> AnalysisResult;
};

#endif /* _analyzer_hpp */
