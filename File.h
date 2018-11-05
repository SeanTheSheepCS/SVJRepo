//File.h
#include <iostream>
#include <fstream>
#include <string>

class File
{
public:
  //Manager Function
  File(string fileName_st);
  ~File();
  //Getter and Setter Functions
  getDest();
  setDest(string fileName_st);
  //Implementer Functions
private:
  //Helper Functions
  //data members
  fstream destination;
  string language;
  string mode;
  bool isOpen;
}
