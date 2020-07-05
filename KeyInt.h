#ifndef KEYINT_H
#define KEYINT_H

#include "IKey.h"
#include <string>
using namespace std;

class KeyInt:public IKey{
private:
    int keyint;
public:
    KeyInt(int);
    ~KeyInt();
    int getKey();
    bool equals(IKey*);
};


#endif /* KEYINT_H */