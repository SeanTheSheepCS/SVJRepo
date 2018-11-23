//file.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "File.h"

using namespace std;

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
File::File(string fileName_st)
{
  destination.open(fileName_st, ios::app);

  if(destination.is_open())
  {
    language = findType(fileName_st);
  }
  else
  {
    cout << "Unable to open file" << endl;
  }
  destination.close();
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
  if(!destination)
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
  destination.close();
}

int File::openFileWriteMode()
{
  destination.open(fileName_st, ios::out);
  if(!destination)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
