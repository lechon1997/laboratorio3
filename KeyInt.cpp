#include "KeyInt.h"

KeyInt::KeyInt(int key){
    this->keyint=key;
};

KeyInt::~KeyInt(){
    
};

int KeyInt::getKey(){
    return this->keyint;
}

bool KeyInt::equals(IKey* key){
    KeyInt *k=dynamic_cast<KeyInt*>(key);
    if(k->getKey()==this->getKey()){
        return true;
    }else{
        return false;
    }
}
