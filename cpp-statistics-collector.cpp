//
//  cpp-statistics-collector.cpp
//  CodeAndCommentLinesParser
//
//  Created by Олег Куколев on 14.01.2021.
//

#include "cpp-statistics-collector.hpp"

CppFilesStatisticsCollector::CppFilesStatisticsCollector(const std::string& path_to_directory)
: kRootDirectory{ path_to_directory },
  processed_files{ 0 }
{
  
}

AnalysisResult CppFilesStatisticsCollector::Collect() {
  AnalysisResult result{
    .blank_lines = 0,
    .code_lines = 0,
    .comment_lines = 0
  };
  
  const std::vector<std::string> file_extensions{
    ".h", ".c", ".hpp", ".cpp", ".cc", ".cxx"
  };
  
  RecursivePathScanner path_scanner{ kRootDirectory, file_extensions };
  auto paths = path_scanner.GetPaths();
  
  boost::lockfree::queue<std::string*> queue(paths.size());
  for (auto& path : paths) {
    queue.push(new std::string{ path });
  }
  
  boost::asio::thread_pool pool{ THREAD_WORKERS };
  
  boost::mutex mutex;
  
  for (size_t i{ 0 }; i < THREAD_WORKERS; i++) {
    boost::asio::dispatch([&]() {
      std::string* path;
      
      while (queue.pop(path)) {
        StaticAnalyzer analyzer{ *path };
        
        const auto stats = analyzer.Analyze();
        
        delete path;
        path = nullptr;
        
        mutex.lock();
        processed_files++;
        result += stats;
        mutex.unlock();
      }
    });
  }
  
  pool.join();
  
  statistics = result;
  return result;
}

std::ostream& CppFilesStatisticsCollector::PrintStats(std::ostream& os) {
  os << "Total files processed: " << processed_files << std::endl;
  os << statistics.value() << std::endl;
  return os;
}
