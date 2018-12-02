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
  File* myFile = new File(filename_s);
  Writer* myWriter = new Writer(*myFile);
  myWriter -> readFile();

  myWriter -> insertAt('\n');
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

  myWriter -> moveCursor(-1,0);
  myWriter -> moveCursor(0,-2);
  myWriter -> insertAt('l');
  myWriter -> insertAt('u');
  myWriter -> insertAt('f');
  myWriter -> insertAt('i');
  myWriter -> insertAt('t');
  myWriter -> insertAt('u');
  myWriter -> insertAt('a');
  myWriter -> insertAt('e');
  myWriter -> insertAt('B');

  myWriter -> saveFile();
  return true;
}
