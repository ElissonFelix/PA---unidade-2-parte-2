//      g++ *.cpp -o escultor.exe      .\escultor.exe

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

int main() {

    std::ifstream fin("desenho.txt");

    if(!fin.is_open()){
        std::cout << "Erro ao abrir o desenho." << std::endl;
        return 1;
    }

    std::vector<FiguraGeometrica*> figuras;

    std::string comando;
    Sculptor *s = nullptr;

    while(fin >> comando){

        if(comando == "dim"){
            int nx, ny, nz;

            fin >> nx >> ny >> nz;

            s = new Sculptor(nx, ny, nz);
        }

        else if(comando == "putvoxel"){
            int x, y, z;
            float r, g, b, a;

            fin >> x >> y >> z
                >> r >> g >> b >> a;

            figuras.push_back(
                new PutVoxel(x,y,z,r,g,b,a)
            );
        }

        else if(comando == "cutvoxel"){
            int x, y, z;

            fin >> x >> y >> z;

            figuras.push_back(
                new CutVoxel(x,y,z)
            );
        }

        else if(comando == "putbox"){
            int x0,x1,y0,y1,z0,z1;
            float r,g,b,a;

            fin >> x0 >> x1
                >> y0 >> y1
                >> z0 >> z1
                >> r >> g >> b >> a;

            figuras.push_back(
                new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a)
            );
        }

        else if(comando == "cutbox"){
            int x0,x1,y0,y1,z0,z1;

            fin >> x0 >> x1
                >> y0 >> y1
                >> z0 >> z1;

            figuras.push_back(
                new CutBox(x0,x1,y0,y1,z0,z1)
            );
        }

        else if(comando == "putsphere"){
            int x0,y0,z0,raio;
            float r,g,b,a;

            fin >> x0 >> y0 >> z0
                >> raio
                >> r >> g >> b >> a;

            figuras.push_back(
                new PutSphere(x0,y0,z0,raio,r,g,b,a)
            );
        }

        else if(comando == "cutsphere"){
            int x0,y0,z0,raio;

            fin >> x0 >> y0 >> z0 >> raio;

            figuras.push_back(
                new CutSphere(x0,y0,z0,raio)
            );
        }

        else if(comando == "putellipsoid"){
            int x0,y0,z0,rx,ry,rz;
            float r,g,b,a;

            fin >> x0 >> y0 >> z0
                >> rx >> ry >> rz
                >> r >> g >> b >> a;

            figuras.push_back(
                new PutEllipsoid(x0,y0,z0,rx,ry,rz,r,g,b,a)
            );
        }

        else if(comando == "cutellipsoid"){
            int x0,y0,z0,rx,ry,rz;

            fin >> x0 >> y0 >> z0
                >> rx >> ry >> rz;

            figuras.push_back(
                new CutEllipsoid(x0,y0,z0,rx,ry,rz)
            );
        }
    }

    fin.close();

    if(s == nullptr){
        std::cout << "Dimensões não definidas!" << std::endl;
        return 1;
    }

    //DESENHA
    for(auto fig : figuras){
        fig->draw(*s);
    }

    s->writeOFF("desenho.off");

    //LIBERA MEMORIA
    for(auto fig : figuras){
        delete fig;
    }

    delete s;

    std::cout << "Desenho gerado." << std::endl;

    return 0;
}