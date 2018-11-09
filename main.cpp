//#include <stdio.h>
#include <iostream>
#include "Writer.h"
#include "File.h"

using namespace std;

int test();

int main()
{
  test();
  return 0;
}

int test()
{
  File* testFile = new File("texty_boiiii.txt");
  Writer* lovecraft = new Writer(*testFile);
  lovecraft -> write_char('t');
  lovecraft -> write_char('e');
  lovecraft -> write_char('s');
  lovecraft -> write_char('t');
  return 0;
}
