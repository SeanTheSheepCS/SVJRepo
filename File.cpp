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
  destination.open(fileName_st);
  if(destination.is_open())
  {
//
  }
  else
  {
    cout << "Unable to open file" << endl;
  }
}
File::File(string fileName_st)
{
  destination.open(fileName_st);
  if(destination.is_open())
    {
    language = findType(fileName_st);
  }
  else
  {
    cout << "Unable to open file" << endl;
  }
}

File::~File()
{
  destination.close();
}
fstream File::getDest()
{

}


void File::setDest(string newFileName_st)
{
  destination.open(newFileName_st);
  if(!(destination.is_open()))
  {
    cout << "Unable to open file" << endl;
  }
}

File::findType(string fileName_st)
{
  map<string,string> extensionMap_mp;
  extensionMap_mp.insert(pair<string,string>(".txt","text_file"));
  return ".txt";
}
