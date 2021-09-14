#include <iostream>

using namespace std;

class operations {
    private:
        char* number;
        bool parity; //positive = false
        int numlength;
        void doubleMemory(int length, char* newNumber) { // unnecessary
            int tempLength = length * 2;
            char* temp = new char[tempLength];

        }

        void halfMemory(int length, char* newNumber) { // unnecessary
            int tempLength = length / 2;
            
            char* temp = new char[length / 2];
        }
    public:
        char* add(operations* othernumber) { //IF THE RESULT IS NEGATIVE THIS WILL BREAK;
            int length = othernumber->getLength();
            char* temp = othernumber->getNumber();
            bool othernumber_parity = othernumber->getParity();
            int biggerlength = (length > numlength) ? length : numlength;
            char* result = new char[biggerlength+2];
            int carry = 0;
            for (int i = 0; i < biggerlength; i++) {
                // cout << "i " << i << endl;
                int olddigit = (int)number[numlength-i-1] - 48; // '0' = 48;
                int newdigit = (int)temp[length-i-1] - 48;
                // cout << "olddigit " << olddigit << endl;
                // cout << "newdigit " << newdigit << endl;
                if (parity) { // first is positive, hence second is negative
                    olddigit = olddigit * -1;
                }
                if (othernumber_parity) {
                    newdigit = newdigit * -1;
                }
                int newnumber = olddigit + newdigit + carry;
                if (newnumber >= 10) {
                    carry = 1;
                    newnumber -=10;
                } else if (newnumber >= 0) {
                    carry = 0;
                } else if (newnumber < -10) {
                    carry = -2;
                    newnumber +=20;
                } else {
                    carry = -1;
                    newnumber += 10;
                }
                if (i == biggerlength-1) {
                    switch(carry) {
                        case 1:
                            result[0] = '+';
                            result[1] = '1';
                            break;
                        case -1:
                            result[0] = '-';
                            result[1] = '1';
                            break;
                        case -2:
                            result[0] = '-';
                            result[1] = '2';
                            break;
                        case 0:
                            result[0] = '+';
                            result[1] = '0';
                    }
                }
                // cout << "carry " << carry << endl;
                // cout << "newnumber " << newnumber << endl;
                //take the rightmost digit in both of the numbers and add them after deciding if they are positive and negative.
                //if the result is negative, take one off the next digit
                result[length-i+1] = (char)(newnumber+48); // '0' = 48;
            }
            return result;
        }
        char* getNumber() const {
            return number;
        }
        int getLength() const {
            return numlength;
        }
        bool getParity() const {
            return parity;
        }
        operations(char* inputNumber, int length) {
            number = inputNumber;
            numlength = length;
            parity = (inputNumber[0] == '-');
        }

        ~operations() {
            delete [] number;
            number = nullptr;
            numlength = 0;
        }
};