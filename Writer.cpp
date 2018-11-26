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
  tail_NP = nullptr;
  currentLocation_CP = new Cursor{0,0};
}

Writer::~Writer()
{

}

void Writer::moveCursor(int numOfCols_int, int numOfCols_int)
{
  Node* currentLocation_NP;

  //Iterate through rows.
  if(numOfRows_int != 0)
  {

    /*
    DEFECTIVE
    DEFECTIVE
    DEFECTIVE
    DEFECTIVE
    */

    currentLocation_NP = cursorLoc();
    int currentCol_int = currentLocation_CP -> col; //The saved column before we mess around with the cursor.

    //GOING FORWARD
    if(numOfRows_int > 0)
    {
      for(int i = 0; i < numOfRows_int; i++) //How many rows to go down.
      {
        if(currentLocation_NP->next == nullptr)
        {
          //You have reached the end already, no need to go any further.
          break;
        }
        while(currentLocation_NP -> data_EP -> ch != '\n') //Until you hit the end of the line
        {
          currentLocation_NP = currentLocation_NP -> next;
        }
        currentLocation_NP = currentLocation_NP -> next;
        //You are now at the start of a new line.
      }
      //You now will move the original amount of columns forward you were.
      for(int j = 0; j < currentCol_int; j++)
      {
        if(currentLocation_NP -> next == nullptr)
        {
          //You have reached the end already, no need to go any further
          break;
        }
        else if(currentLocation_NP -> data_EP -> ch != '\n')
        {
          //Go no further, you have reached the end of this line.
          break;
        }
        else
        {
          currentLocation_NP = currentLocation_NP -> next;
        }
      }
    }

    //GOING BACKWARD
    if(numOfRows_int < 0)
    {
      numOfRows_int = 0-numOfRows_int;
      for(int i = 0; i < numOfRows_int; i++) //How many rows to go up.
      {
        if(currentLocation_NP->prev == nullptr)
        {
          //You have reached the start already, no need to go any further back.
          break;
        }
        while(currentLocation_NP -> data_EP -> ch != '\n') //Until you hit the end of the line
        {
          currentLocation_NP = currentLocation_NP -> prev;
        }
        currentLocation_NP = currentLocation_NP -> prev;
        //You are now at the start of a new line.
      }
      //You now will move the original amount of columns forward you were.
      for(int j = 0; j < currentCol_int; j++)
      {
        if(currentLocation_NP -> next == nullptr)
        {
          //You have reached the end already, no need to go any further
          break;
        }
        else if(currentLocation_NP -> data_EP -> ch != '\n')
        {
          //Go no further, you have reached the end of this line.
          break;
        }
        else
        {
          currentLocation_NP = currentLocation_NP -> next;
        }
      }
    }


    (currentLocation_CP -> row) += numOfRows_int;
  }


  if(numOfCols_int != 0)
  {

  }
}

Node* Writer::cursorLoc()
{
  Node* current_NP = head_NP;
  if(current_NP == nullptr)
  {
    return nullptr;
  }

  if(currentLocation_CP!=nullptr)
  {
    int i = 0;
    while(i < currentLocation_CP -> row)
    {
      //Cycle until the end of the row
      if(current_NP!=nullptr)
      {
        //increment i's every new line character
        if(current_NP -> data_EP -> ch == '\n')
        {
          i++;
        }
        //move to the next one
        current_NP = current_NP -> next;
      }
      else
      {
        currentLocation_CP -> row = i;
        break;
      }

    }

    int j = 0;
    while(j < currentLocation_CP -> col)
    {
      //Move col many to the right
      if(current_NP!=nullptr)
      {
        current_NP = current_NP -> next;
      }
      else
      {
        currentLocation_CP -> col = j;
        break;
      }
      j++;
    }
  }
  return current_NP;
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
    current_Nd = new Node {new Element {current_ch}, nullptr, nullptr};
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
      current_Nd -> prev = prev_Nd;
    }
    prev_Nd = current_Nd;
  }
  tail_NP = current_Nd;

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

  Node* newNode_NP = new Node{new Element {input_c}, nullptr, nullptr};

  Node* prev_NP = nullptr;
  Node* atLocation_NP = head_NP;
  //cycle through \n's until on the correct row
  int i = 0;
  while(currentLocation_CP -> row != i)
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
  for(int j = 0; j < currentLocation_CP -> col; j++)
  {
    prev_NP = atLocation_NP;
    atLocation_NP = atLocation_NP -> next;
  }

  //Place the character into the list.
  if(prev_NP != nullptr)
  {
    //Deals with nexts
    prev_NP -> next = newNode_NP;
    newNode_NP -> next = atLocation_NP;
    //Deals with prevs
    newNode_NP -> prev = prev_NP;
    atLocation_NP -> prev = newNode_NP;
  }
  else if(atLocation_NP == nullptr)
  {
    tail_NP = newNode_NP;
    newNode_NP -> prev = prev_NP;
    prev_NP -> next = newNode_NP;
  }
  else
  {
    head_NP = newNode_NP;
    newNode_NP -> next = atLocation_NP;
    atLocation_NP -> prev = newNode_NP;
  }

}
