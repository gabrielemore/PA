#include <iostream>
#include <memory>
#include <cstring>
using namespace std;

void setA(char* input){
    char* rawString = new char[sizeof(strlen(input))+1];
    strcpy(rawString,input);
    if(rawString != nullptr && *rawString != '\0')
        rawString[0] = 'A';

    cout << "Stringa modificata raw: " << rawString << endl;
    //Essendo il puntatore a raw, devo deallocarlo manualmente
    delete[] rawString;
}

void setA_smart(char* input ){
    unique_ptr<char> smartString(new char[sizeof(strlen(input))+1]);
    strcpy(smartString.get(),input);
    if(smartString != nullptr && smartString.get()[0] != '\0')
        smartString.get()[0] = 'A';

    cout << "Stringa modificata raw: " << *smartString << endl;
    //Non devo deallocarlo io, verrà deallocato in automatico
}

int main() {

    char input[] = "Esempio";

    //Puntatore raw
    setA(input);
    //Puntatore smart
    setA_smart(input);



    return 0;
}
