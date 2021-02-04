#include <iostream>
#include <string.h>

using namespace std;

class Test{
    int x, y;
public:
    void set_values(int, int);
    int area(void){
        return (x*y);
    }

};

void Test::set_values(int a, int b) {
    x = a;
    y = b;
}

int add(int a, int b)
{
    int sum = a + b;
    return sum;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int sum = 0;
    sum = add(5, 3);
    std:cout << "sum of 5 and 3 is " << sum << std::endl;

    Test rect, rectb;

    rect.set_values(3, 4);
    std::cout<< rect.area()<<std::endl;
    
    char *p = new char[5];
    p = "strin";
    //char p[6];
    //p = "strin";
    cout << "start: " << p << endl;
    for(int i=0;i<5;i++){
	cout << "i: "<< i << endl;
	cout << *p << endl;
	p++;
    }
    cout << "end: " << (p-5) << endl;

    return 0;

}
