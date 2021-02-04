
#include <cctype>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include "cmake-build-debug/String_tool.h"
#include <stack>
#include <sys/stat.h>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <thread>
using namespace std;

bool FileExist(const char* FileName)
{
    struct stat my_stat;
    return (stat(FileName, &my_stat) == 0);
}

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int flag = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] %2 == 1){
                flag += 1;
                if(flag == 3){
                    return true;
                }
            }else{
                flag = 0;
            }
        }
        return false;
    }
};

typedef struct{
    int n;
    char *str;
}params;

int thread_func1(){
    sleep(1);
    cout << "func1" << endl;
    return 1;
}

void thread_func2(int n, string s){
    cout << "func2:" << endl;
    cout << n << endl;
    cout << s << endl;
}



int main() {
    cout << "hello" << endl;
    string s;
//    std::cout << "test" << endl;
////    char* tj;
////    cin >> tj;
////    unordered_map<int, int> hashtable;
//    /*
//    vector<int> a;
//    a.insert(a.begin(), 0);
//    vector<string> b{10,"a"};
//
//    map<int, int> temp;
//    temp[0] += 1;
//    cout << temp[0] << endl;
//    cout << temp[1];
//    cout << 7/2 << endl;
//
//    Solution test;
//    vector<int> data{2,2,1,1,2,2};
//
//    int test2 = 3;
//
//    auto s0 = to_string(5);
//
//    string test3("  this a    test for ");
//    String_tool s;
//    cout << test3 << endl << s.trim(test3) << endl << test3 << endl;
//    s.trim(test3) += 'l';
//    cout << test3 << endl;
//
//    std::vector<std::string> test4;
//    string kg(" ");
//    s.split(test3, kg, &test4);
//    test3.substr(3,6);
//    cout << test3.substr(3,3)  << "test:" <<test3.find("t",3) << endl;
//    string test5(test3,2,1);
//    cout << test5<< endl;
//    test5.insert(test5.size(), 5, '!');
//    cout << test5.size() << endl << test5[5];
//    char ch = 97;
//    ch = ch+1;
//    unsigned int j = 2;
//    int i = 3;
//    unsigned int dm = i;
//    if(-1 > test5.find("!"))
//    cout << endl << "yes";
//    unordered_map<char, int> tem;
//    tem['a'] = 0;
//    tem['b'] = 1;
//    string test6 = "SADdfsdf";
//    test6[0] = tolower(test6[0]);
//    test6 = "new";
//    vector<int> nums{8,1,2,2,3};
//     */
//
//
//    /*
//     * char dataf[100];
//    ofstream outfile;
//    outfile.open("test.dat", ios::ate);
//    cout << "writing to the file" << outfile.is_open() << endl;
//    cout << "enter your name: ";
//    cin.getline(dataf, 100);
//
//    string datas;
//    outfile << dataf;
//    outfile << "test2" << endl;
//    outfile.close();
//
//    ifstream infile;
//    infile.open("test.data");
//    cout << "reading from the file: " << endl;
//    infile >> dataf;
//    cout << dataf << endl;
//    infile >> datas;
//    cout << datas << endl;
//    infile.close();
//    const char* filename="test.dat";
//    long l,m;
//    ifstream infile;
//    infile.open(filename);
//    l = infile.tellg();
//    infile.seekg(0, ios::end);
//    m = infile.tellg();
//    infile.seekg(0, ios::end);
//    long size = infile.tellg();
//    string datas;
//    infile.seekg(0);
//    infile >> datas;
//    string data_test;
//    char *data_ch;
//    infile.seekg(0);
//    infile.read(data_ch, size);
//    infile.close();
//    cout << "file length: " << m-l << endl;
//    cout << "test: " << data_ch << endl;
//    cout << datas.length();
//    */
//
//    String_tool test;
//    string str = "test.dat";
//
//    test.writeFile("test.dat", "write test", 'a');
//    test.readFile("test.dat");
//    pid_t t = getpid();
//    cout << endl << "pid: " << t << endl;
//    /*
//    char* it;
//    char *its = "-p";
//    cin >> it;
//    cout << "it is :" << it << endl << strlen(it) << endl;
//    if(it == "-p"){
//        cout << "ans is ok " << endl;
//    }
//    */
    params i;
    (i).n = 1;
    (i).str = "test";
    cout << "start " << (&i)->n << endl << (&i)->str << endl;
    char a[10]="1234567\0";

    cout << strcmp(a, "1234567\0");

//    thread threads[2];
//    threads[0] = thread(thread_func1);
//    threads[1] = thread(thread_func2, 2, "string");
//    threads[0].join();
//    threads[1].join();
//    char strf[] = "str";
//    char *p = strf;
//    cout << p;

//
//
//
//    return 0;
//

}

