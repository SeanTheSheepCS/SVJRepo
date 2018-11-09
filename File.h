//File.h
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef FILE_H
#define FILE_H
class File
{
public:
  //public variables
  fstream destination;
  //Manager Function
  File();
  File(string fileName_st);
  ~File();
  //Getter and Setter Functions
  void setDest(string fileName_st);
  //Implementer Functions
private:
  //Helper Functions
  string findType(string fileName_st);
  //data members
  string language;
  string mode;
  bool isOpen;
  string fileName_st;
};
#endif
