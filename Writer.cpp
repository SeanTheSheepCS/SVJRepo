//Writer.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "Writer.h"

Writer::write_char(char source_c)
{
  destination_Fl.getDest() << source_c;
}
Writer::Writer(selectedFile_Fl)
{
  destination_Fl = selectedFile_Fl;
}
Writer::~Writer()
{
  
}