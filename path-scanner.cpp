//
//  path-scanner.cpp
//  CodeAndCommentLinesParser
//
//  Created by Олег Куколев on 14.01.2021.
//

#include "path-scanner.hpp"
using namespace std;

RecursivePathScanner::RecursivePathScanner(const string& path, const _VectorString file_extensions)
: kPath{ path },
  kExtensions{ file_extensions }
{
  
}

_VectorString RecursivePathScanner::RecursivePathScanner::GetPaths() const {
  
  function<_VectorString(const string&)> GetPathsRecursive {
    [&](const string& path) -> _VectorString {
    _VectorString file_paths;
    
    filesystem::directory_iterator current_dir_it{ path };
    
    for (const auto& file : current_dir_it) {
      if (file.is_directory()) {
        const auto paths = GetPathsRecursive(file.path());
        file_paths.insert(file_paths.end(), paths.begin(), paths.end());
      }
      else if (IsValidExtension(file.path().extension())) {
        file_paths.push_back(file.path());
      }
    }
    
    return file_paths;
    }
  };
  
  return GetPathsRecursive(kPath);
}

bool RecursivePathScanner::IsValidExtension(const string& extension) const {
  return find(kExtensions.begin(), kExtensions.end(), extension) != kExtensions.end();
}
