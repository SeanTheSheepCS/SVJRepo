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

  myWriter -> insertAt('T');
  myWriter -> insertAt('I');
  myWriter -> insertAt(' ');
  myWriter -> insertAt('D');
  myWriter -> insertAt('I');
  myWriter -> insertAt('D');
  myWriter -> insertAt(' ');
  myWriter -> insertAt('E');
  myWriter -> insertAt('W');
  myWriter -> insertAt('\n');
  myWriter -> insertAt('!');
  myWriter -> insertAt('d');
  myWriter -> insertAt('l');
  myWriter -> insertAt('r');
  myWriter -> insertAt('o');
  myWriter -> insertAt('W');
  myWriter -> insertAt(' ');
  myWriter -> insertAt(',');
  myWriter -> insertAt('o');
  myWriter -> insertAt('l');
  myWriter -> insertAt('l');
  myWriter -> insertAt('e');
  myWriter -> insertAt('H');
  myWriter -> saveFile();
  return true;
}
