//File.h
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class File
{
public:
  //Manager Function
  File();
  File(string fileName_st);
  ~File();
  //Getter and Setter Functions
  fstream getDest() const;
  void setDest(string fileName_st);
  //Implementer Functions
private:
  //Helper Functions
  string findType(string fileName_st);
  //data members
  fstream destination;
  string language;
  string mode;
  bool isOpen;
string fileName_st;
};
