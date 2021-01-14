//
//  file-reader.hpp
//  CodeAndCommentLinesParser
//
//  Created by Олег Куколев on 14.01.2021.
//

#ifndef file_reader_hpp
#define file_reader_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class FileReader {
public:
  static auto ReadFile(const std::string& filepath) -> std::vector<std::string>;
};

#endif /* file_reader_hpp */
