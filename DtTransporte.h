
#ifndef TRANSPORTE_H
#define TRANSPORTE_H
#include <String>
using namespace std;

class DtTransporte{
private:
    string pie;
    string bici;
    string moto;
public:
    DtTransporte();
    ~DtTransporte();
    string getPie();
    string getBici();
    string getmoto();
};


#endif /* TRANSPORTE_H */

