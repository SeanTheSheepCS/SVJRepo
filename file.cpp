//file.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "File.h"

using namespace std;


File::File(string fileName_st)
{
  this -> fileName_st = fileName_st;
}

File::~File()
{

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
  return 0;
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
