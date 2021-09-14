#include <iostream>
#include "class.cpp"

using namespace std;

int main() {
    int length = 1000;
    int length2 = 1000;
    char* temp = new char[length];
    for (int i = 0; i < length; i++) {
        temp[i] = '1';
    }
    operations num(temp, length);
    char* temp2 = new char[length2];
    for (int i = 0; i < length2; i++) {
        temp2[i] = '1';
    }
    operations num2(temp2,length2);
    operations* ptr = &num2;
    cout << num.add(ptr);
    return 0;
}