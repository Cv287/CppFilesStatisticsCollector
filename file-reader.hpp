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

//
//  This class is intended for reading a file line by line
//

class FileReader {
  const std::string kFilePath;
  std::ifstream file;
  
public:
  /* Constructor, takes path to file for further reading as an argument. */
  FileReader(const std::string& path);
  /* Opens a file located in kFilePath. */
  void OpenFile();
  /* Closes a file. */
  void CloseFile();
  /* Checks if there's end of file. */
  bool Eof() const;
  /* Reads one line from file and returns it.
   If called when EOF then exception is raising. */
  std::string ReadNextLine();
};

#endif /* file_reader_hpp */
