//
// Created by xin777 on 2020/11/19.
//
#ifndef STRING_TOOL_C
#define STRING_TOOL_C

#include "String_tool.h"

using namespace std;

//删除开头和结尾的空格
std::string  &String_tool::trim( std::string &s) {
    if(s.empty()){
        return s;
    }
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ")+1); //从最后一个非空字符开始向后全部删除
    return s;
}

//注意：当字符串为空时，也会返回一个空字符串
void String_tool::split(std::string& s, std::string& delim,std::vector< std::string >* ret)
{
    size_t last = 0;
    size_t index=s.find_first_of(delim,last);

    while (index!=std::string::npos)
    {
        ret->push_back(s.substr(last,index-last));
        last=index+1;
        index=s.find_first_of(delim,last);
    }
    if (index-last>0)
    {
        ret->push_back(s.substr(last,index-last));
    }
}

char* String_tool::readFile(char* file){
    ifstream f(file);
    if(!f.is_open()){
        cout << "Error opening file";
        exit(1);
    }
    f.seekg(0, ios::end);
    long length = f.tellg();
    f.seekg(0);
    cout << "file size: " << length << " bytes." << endl;
    char *ans = new char[length];
    f.read(ans, length);

    cout << ans;
    f.close();
    return ans;
}
//app追加, ate定位到最后, in打开文件用于读取, out打开文件用于写入
void String_tool::writeFile(char* file, char* content){
    ofstream f(file);
    if(!f.is_open()){
        cout << "Error opening file";
        exit(1);
    }
    f.write(content, strlen(content));
    cout << "write success" << endl;
    f.close();

}

void String_tool::writeFile(char* file, char* content, char mode){
    ofstream f;
    if(mode == 'a'){
        f.open(file, ios::app);
    }else if(mode == 'w'){
        f.open(file);
    }
    if(!f.is_open()){
        cout << "Error opening file";
        exit(1);
    }
    f.write(content, strlen(content));
    cout << "write success" << endl;
    f.close();
}
bool String_tool::exsitFile(char* FileName)
{
    struct stat my_stat;
    return (stat(FileName, &my_stat) == 0);
}


#endif STRING_TOOL_C