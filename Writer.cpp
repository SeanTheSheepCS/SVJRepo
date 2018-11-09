//Writer.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "Writer.h"


Writer::Writer(File& selectedFile_Fl)
{
  destination_Fl = &selectedFile_Fl;
}
Writer::~Writer()
{

}
int Writer::write_char(char source_c)
{
  //destination_Fl -> destination << "a" << endl;
  destination_Fl -> destination << source_c << endl;
  return 0;
}
