//#include "ReadFile.h"
#include <iostream>
#include <string>

//class "constructor"
ReadFile::ReadFile(const char* file_name)
{

   input_file.open(file_name);
   closed = false;
   eof = false;
}

void ReadFile::~ReadFile()
{
   close(rf);
   delete rf;
}

bool ReadFile::eof()
{
   return rf->_eof;
}

void ReadFile::close()
{
   if (!rf->closed)
   {
      rf->input_file.close();
      rf->closed = true;
   }
}

String* ReadFile::readLine()
{
   if (rf->closed) return NULL;
   if (rf->_eof) return NULL;

   string text;
   rf->_eof = !(getline(rf->input_file, text));

   String* str = new String(text.c_str());
   return str;
}
