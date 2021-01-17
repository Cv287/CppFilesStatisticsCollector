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
  // Path of directory for scanning
  const std::string kPath;
  // Vector of file extensions to be processed
  const _VectorString kExtensions;
  
private:
  /* Checks if extension is in kExtensions vector. */
  bool IsValidExtension(const std::string& extension) const;
  
public:
  /* Constructor, has 2 parameters:
      1. path to main directory where scanning is started;
      2. vector of file extensions
   Files with appropriate extensions will be processed by GetPaths(). */
  RecursivePathScanner(const std::string& path, const _VectorString file_extensions);
  /* Returns list of files in kPath with extensions in kExtensions */
  _VectorString GetPaths() const;
};

#endif /* path_scanner_hpp */
