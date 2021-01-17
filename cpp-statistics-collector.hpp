//
//  cpp-statistics-collector.hpp
//  CodeAndCommentLinesParser
//
//  Created by Олег Куколев on 14.01.2021.
//

#ifndef cpp_statistics_collector_hpp
#define cpp_statistics_collector_hpp

#include <iostream>
#include <optional>
#include <vector>
#include <string>
#include <mutex>
#include <thread>
#include <boost/asio.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/lockfree/queue.hpp>

#include "path-scanner.hpp"
#include "file-reader.hpp"
#include "static-analyzer.hpp"

/* Number of threads to be created in C_CppFilesStatisticsCollecor::Collect(). */
constexpr int THREAD_WORKERS{ 4 };

//
//  This class is intended for static analysis of c/cpp files
//  in specific directory and its subdirectories.
//  The method Collect is multi-threaded.
//  The list of supported file extensions:
//    * .h, .hpp
//    * .c, .cc, .cpp, .cxx
//

class CppFilesStatisticsCollector {
  const std::string kRootDirectory;
  int processed_files;
  std::optional<AnalysisResult> statistics;
  
public:
  /* Constructor, takes path to directory as an argument. */
  CppFilesStatisticsCollector(const std::string& path_to_directory);
  
  /* Multi-thread method */
  AnalysisResult Collect();
  
  /* Prints stats of type AnalysisResult to os. */
  std::ostream& PrintStats(std::ostream& os);
};

#endif /* cpp_statistics_collector_hpp */
