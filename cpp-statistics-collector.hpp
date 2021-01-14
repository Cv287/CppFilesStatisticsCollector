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
#include <boost/asio.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/lockfree/queue.hpp>

#include "path-scanner.hpp"
#include "file-reader.hpp"
#include "static-analyzer.hpp"

#define THREAD_WORKERS 4

class C_CppFilesStatisticsCollector {
  const std::string kRootDirectory;
  int processed_files;
  std::optional<AnalysisResult> stats;
  
public:
  C_CppFilesStatisticsCollector(const std::string& path_to_directory);
  AnalysisResult Collect();
  std::ostream& PrintStats(std::ostream& os);
};

#endif /* cpp_statistics_collector_hpp */
