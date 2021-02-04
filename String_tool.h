

//
// Created by xin777 on 2020/11/19.
//


#ifndef UNTITLED2_STRING_TOOL_H
#define UNTITLED2_STRING_TOOL_H


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

class String_tool {
public:
    std::string  &trim(std::string &);
    void split(std::string& s, std::string& delim,std::vector< std::string >* ret);
    char* readFile(char* file);
    void writeFile(char* file, char* content);
    void writeFile(char* file, char* content, char mode);
    bool exsitFile(char* file);

};


#endif //UNTITLED2_STRING_TOOL_H
