//test.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "Writer.h"

bool testWriter();

int main()
{
  testWriter();

}

bool testWriter()
{
  string filename_s = "ABC.txt";
  char input = 'Z';
  File* myFile = new File(filename_s);
  Writer* myWriter = new Writer(*myFile);
  myWriter -> readFile();
  myWriter -> insertAt('B');
  myWriter -> saveFile();
  return true;
}
