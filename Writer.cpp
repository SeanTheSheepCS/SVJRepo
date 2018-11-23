//Writer.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "Writer.h"
#include <cassert>

using namespace std;

Writer::Writer(File& selectedFile_Fl)
{
  destination_Fl = &selectedFile_Fl;
  head_NP = nullptr;
  currentLocation_cu = new Cursor{0,0};
}
Writer::~Writer()
{

}

int Writer::readFile()
{
  //converts text file to a linked list
  Node* prev_Nd = nullptr;
  int success = destination_Fl -> openFileReadMode();
  if(success == 0)
  {
    //Opening file failed!
    cout << "Failed to open the file." << endl;
    return 0;
  }
  char current_ch;
  Node* current_Nd = nullptr;
  while(!(destination_Fl -> destination).eof())
  {
    (destination_Fl -> destination) >> current_ch;
    current_Nd = new Node {new Element {current_ch}, nullptr};
    assert(current_Nd!=nullptr || (current_Nd -> data_EP) != nullptr);

    //if first element makes head and previous point to the newly created node
    if(head_NP == nullptr)
    {
      head_NP = current_Nd;
    }

    //if 2nd or more element makes previous link to the new node, then previous point to the new node
    else
    {
      prev_Nd -> next = current_Nd;
    }
    prev_Nd = current_Nd;
  }

  //close file after reading
  cout << "File successfully Opened and Read" << endl;
  destination_Fl -> closeFile();
  return 1;
}

int Writer::saveFile()
{
  //takes linked list and converts to text file
  int success = destination_Fl -> openFileWriteMode();
  if(success == 0)
  {
    //Opening file failed!
    cout << "Failed to save the file." << endl;
    return 0;
  }
  Node* current_Nd = head_NP;
  while (current_Nd != nullptr)
  {
    destination_Fl -> destination << (current_Nd -> data_EP -> ch);
    current_Nd = current_Nd -> next;
  }
  cout << "File successfully Saved" << endl;
  //close file after reading
  destination_Fl -> closeFile();
  return 1;
}

void Writer::insertAt(char input_c)
{

  Node* newNode_NP = new Node{new Element {input_c}, nullptr};

  Node* prev_NP = nullptr;
  Node* atLocation_NP = head_NP;
  //cycle through \n's until on the correct row
  int i = 0;
  while(currentLocation_cu -> row != i)
  {
    while(atLocation_NP -> data_EP -> ch != '\n')
    {
      if(atLocation_NP != nullptr)
      {
        prev_NP = atLocation_NP;
        atLocation_NP = atLocation_NP -> next;
      }
      else
      {
        //Invalid row or column :(
        cout << "Cursor at Invalid Location!" << endl;
        return;
      }
    }
    i++;
  }

  //Move col elements forward to get to the right place.
  for(int j = 0; j < currentLocation_cu -> col; j++)
  {
    prev_NP = atLocation_NP;
    atLocation_NP = atLocation_NP -> next;
  }

  //Place the character into the list.
  if(prev_NP != 0)
  {
    prev_NP -> next = newNode_NP;
    newNode_NP -> next = atLocation_NP;
  }
  else
  {
    head_NP = newNode_NP;
    newNode_NP -> next = atLocation_NP;
  }

}
