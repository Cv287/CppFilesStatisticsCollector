//
//  main.cpp
//  CodeAndCommentLinesParser
//
//  Created by Олег Куколев on 13.01.2021.
//

#include <iostream>
#include <string>

#include "cpp-statistics-collector.hpp"

//#define RUN_TESTS

using namespace std;
 
int main(int argc, char* argv[]) {
  const string path{ "/Users/powerful_mac/Library/Mobile Documents/com~apple~CloudDocs/Desktop/Old/Work/XCodeProj/languageC++/IT_Academy/CodeAndCommentLinesParser/"
  };
  
  C_CppFilesStatisticsCollector collector{ path };
  collector.Collect();
  collector.PrintStats(cout);
}
