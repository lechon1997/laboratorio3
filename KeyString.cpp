
#include "KeyString.h"

KeyString::KeyString(string key){
    this->keystring=key;
};
KeyString::~KeyString(){
    
};

string KeyString::getKey(){
    return this->keystring;
}

bool KeyString::equals(IKey* key){
    KeyString *k=dynamic_cast<KeyString*>(key);
    if(k->getKey()==this->getKey()){
        return true;
    }else{
        return false;
    }
}