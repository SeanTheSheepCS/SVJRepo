#include "File.h"
class Writer
{
public:
//Manager Functions
 Writer(File selectedFile_Fl);
 ~Writer();
 //Getter and Setter Functions
 //Implementer Functions
 int write_char(char source_c);
private:
 File destination_Fl;
};
