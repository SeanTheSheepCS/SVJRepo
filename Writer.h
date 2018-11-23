#include "File.h"

#ifndef WRITER_H
#define WRITER_H

typedef struct Element
{
  char ch;
} Element;


typedef struct Node
{
  Element* data_EP;
  Node* next;
} Node;


typedef struct Cursor
{
  int row;
  int col;
} Cursor;

class Writer
{
public:
//Manager Functions
 Writer(File & selectedFile_Fl);
 ~Writer();
 //Getter and Setter Functions
 //Implementer Functions
 int backspace(int row, int col);
 int readFile();
 int saveFile();

 void insertAt(char input_c);
private:
  //Helper
  void removeAt();
  void destroy();
  //data members
  Node* head_NP;
  File* destination_Fl;
  Cursor* currentLocation_cu;
};
#endif
