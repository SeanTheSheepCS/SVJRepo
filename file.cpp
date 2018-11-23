//file.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "File.h"

using namespace std;

/*
-----------------------
SHOULD NOT INCLUDE THIS
-----------------------

File::File()
{
  cout << "New File: enter your desired filename" << endl;
  cin >> fileName_st;
  cout << "your new file is named " << fileName_st << endl;
  destination.open(fileName_st, ios::app);
  if(destination.is_open())
  {
//
  }
  else
  {
    cout << "Unable to open file" << endl;
  }
  destination.close();
}
*/


File::File(string fileName_st)
{
  this -> fileName_st = fileName_st;
}

File::~File()
{

}

void File::setDest(string newFileName_st)
{
  destination.open(newFileName_st, ios::app);
  if(!(destination.is_open()))
  {
    cout << "Unable to open file" << endl;
  }
  destination.close();
}

string File::findType(string fileName_st)
{
  map<string,string> extensionMap_mp;
  extensionMap_mp.insert(pair<string,string>(".txt","text_file"));
  return ".txt";
}

int File::openFileReadMode()
{
  destination.open(fileName_st, ios::in);
  if(destination.fail())
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

int File::closeFile()
{
  destination << endl;
  destination.close();
}

int File::openFileWriteMode()
{
  destination.open(fileName_st, ios::out);
  if(destination.fail())
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
