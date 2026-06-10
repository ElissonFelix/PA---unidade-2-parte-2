//      g++ *.cpp -o escultor.exe      .\escultor.exe

#include <vector>

#include "Sculptor.h"
#include "FiguraGeometrica.h"

#include "PutVoxel.h"
#include "CutVoxel.h"

#include "PutBox.h"
#include "CutBox.h"

#include "PutSphere.h"
#include "CutSphere.h"

#include "PutEllipsoid.h"
#include "CutEllipsoid.h"

int main(){

    Sculptor s(23,23,10);

    std::vector<FiguraGeometrica*> figuras;

    //BASE
    figuras.push_back(
        new PutBox(
            3,16,
            0,7,
            1,10,
            0.43,0.31,0.22,1.0
        )
    );

    //SUPORTE 1
    figuras.push_back(
        new PutEllipsoid(
            5,7,3,
            3,10,3,
            0.43,0.31,0.22,1.0
        )
    );

    figuras.push_back(
        new CutEllipsoid(
            5,20,3,
            3,10,3
        )
    );

    //SUPORTE 2
    figuras.push_back(
        new PutEllipsoid(
            14,7,3,
            3,10,3,
            0.43,0.31,0.22,1.0
        )
    );

    figuras.push_back(
        new CutEllipsoid(
            14,20,3,
            3,10,3
        )
    );

    //MAÇÃ 1
    figuras.push_back(
        new PutSphere(
            14,16,3,
            3,
            1,0,0,1
        )
    );

    figuras.push_back(
        new PutVoxel(
            14,19,3,
            0,1,0,1
        )
    );

    figuras.push_back(
        new PutVoxel(
            14,20,3,
            0,1,0,1
        )
    );

    figuras.push_back(
        new PutVoxel(
            15,20,3,
            0,1,0,1
        )
    );

    //MAÇÃ 2
    figuras.push_back(
        new PutSphere(
            5,16,3,
            3,
            1,0,0,1
        )
    );

    figuras.push_back(
        new CutSphere(
            5,19,3,
            3
        )
    );

    figuras.push_back(
        new PutVoxel(
            5,17,3,
            1,1,0,1
        )
    );

    figuras.push_back(
        new CutVoxel(2,7,3)
    );

    figuras.push_back(
        new CutVoxel(17,7,3)
    );

    //ESCADA DA BASE
    figuras.push_back(
        new CutBox(
            3,7,
            3,7,
            6,10
        )
    );

    figuras.push_back(
        new CutBox(
            7,11,
            5,7,
            6,10
        )
    );

    figuras.push_back(
        new CutBox(
            11,15,
            7,7,
            6,10
        )
    );

    //PARTE AMARELA
    figuras.push_back(new PutVoxel(5,17,3,1,1,0,1));
    figuras.push_back(new PutVoxel(5,17,2,1,1,0,1));
    figuras.push_back(new PutVoxel(5,17,1,1,1,0,1));
    figuras.push_back(new PutVoxel(5,17,0,1,1,0,1));
    figuras.push_back(new PutVoxel(5,17,4,1,1,0,1));
    figuras.push_back(new PutVoxel(5,17,5,1,1,0,1));
    figuras.push_back(new PutVoxel(5,17,6,1,1,0,1));

    figuras.push_back(new PutVoxel(4,17,3,1,1,0,1));
    figuras.push_back(new PutVoxel(3,17,3,1,1,0,1));
    figuras.push_back(new PutVoxel(2,17,3,1,1,0,1));

    figuras.push_back(new PutVoxel(6,17,3,1,1,0,1));
    figuras.push_back(new PutVoxel(7,17,3,1,1,0,1));
    figuras.push_back(new PutVoxel(8,17,3,1,1,0,1));

    figuras.push_back(new PutVoxel(4,17,2,1,1,0,1));
    figuras.push_back(new PutVoxel(3,17,2,1,1,0,1));
    figuras.push_back(new PutVoxel(4,17,1,1,1,0,1));

    figuras.push_back(new PutVoxel(6,17,5,1,1,0,1));
    figuras.push_back(new PutVoxel(6,17,4,1,1,0,1));
    figuras.push_back(new PutVoxel(7,17,4,1,1,0,1));

    //DESENHO
    for(auto fig : figuras){
        fig->draw(s);
    }

    s.writeOFF("desenho.off");

    //LIBERAR MEMÓRIA
    for(auto fig : figuras){
        delete fig;
    }

    return 0;
}
