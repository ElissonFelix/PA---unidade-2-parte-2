//      g++ *.cpp -o escultor.exe      .\escultor.exe

#include <vector>

#include "Sculptor.h"
#include "FiguraGeometrica.h"

#include "PutBox.h"

int main(){

    Sculptor s(30,30,30);

    std::vector<FiguraGeometrica*> figuras;

    figuras.push_back(
        new PutBox(
            5,15,
            5,15,
            5,15,
            0,1,0,1
        )
    );

    for(auto fig : figuras){
        fig->draw(s);
    }

    s.writeOFF("teste.off");

    return 0;
}