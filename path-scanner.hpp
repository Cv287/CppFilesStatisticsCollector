//
//  path-scanner.hpp
//  CodeAndCommentLinesParser
//
//  Created by Олег Куколев on 14.01.2021.
//

#ifndef path_scanner_hpp
#define path_scanner_hpp

#include <vector>
#include <filesystem>
#include <algorithm>
#include <string>
#include <mutex>

using _VectorString = std::vector<std::string>;

class RecursivePathScanner {
  // Path of file which has to be investigated
  const std::string kPath;
  // Vector of file extensions to be processed
  const _VectorString kExtensions;
  
private:
  bool IsValidExtension(const std::string& extension) const;
  
public:
  RecursivePathScanner(const std::string& path, const _VectorString file_extensions);
  _VectorString GetPaths() const;
};

#endif /* path_scanner_hpp */
