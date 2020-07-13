
#ifndef KEYSTRING_H
#define KEYSTRING_H
#include "IKey.h"
#include <string>
using namespace std;

class KeyString:public IKey{
private:
    string keystring;
public:
    KeyString(string);
    ~KeyString();
    string getKey();
    bool equals(IKey*);
};

#endif /* KEYSTRING_H */

