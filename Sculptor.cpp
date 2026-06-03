#include "Sculptor.h"
#include <fstream>
#include <cmath>
#include <iomanip>

//construtor
Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];
    for(int i = 0; i < nx; i++) {
        v[i] = new Voxel*[ny];
        for(int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];
            for(int k = 0; k < nz; k++) {
                v[i][j][k].show = false;
            }
        }
    }
}

//destrutor
Sculptor::~Sculptor() {
    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
}

//cor
void Sculptor::setColor(float r, float g, float b, float a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

//putvoxel
void Sculptor::putVoxel(int x, int y, int z) {
    if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].show = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

//cutvoxel
void Sculptor::cutVoxel(int x, int y, int z) {
    if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].show = false;
    }
}

//putbox
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for(int i = x0; i <= x1; i++) {
        for(int j = y0; j <= y1; j++) {
            for(int k = z0; k <= z1; k++) {
                putVoxel(i, j, k);
            }
        }
    }
}

//cutbox
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for(int i = x0; i <= x1; i++) {
        for(int j = y0; j <= y1; j++) {
            for(int k = z0; k <= z1; k++) {
                cutVoxel(i, j, k);
            }
        }
    }
}

//esfera
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {
    for(int i = xcenter - radius; i <= xcenter + radius; i++) {
        for(int j = ycenter - radius; j <= ycenter + radius; j++) {
            for(int k = zcenter - radius; k <= zcenter + radius; k++) {
                if((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter) <= radius*radius) {
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

//cutesfera
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
    for(int i = xcenter - radius; i <= xcenter + radius; i++) {
        for(int j = ycenter - radius; j <= ycenter + radius; j++) {
            for(int k = zcenter - radius; k <= zcenter + radius; k++) {
                if((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter) <= radius*radius) {
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

//elipse
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    for(int i = xcenter - rx; i <= xcenter + rx; i++) {
        for(int j = ycenter - ry; j <= ycenter + ry; j++) {
            for(int k = zcenter - rz; k <= zcenter + rz; k++) {
                if(rx != 0 && ry != 0 && rz != 0) {
                    float eq = ((float)(i-xcenter)*(i-xcenter))/(rx*rx) +
                               ((float)(j-ycenter)*(j-ycenter))/(ry*ry) +
                               ((float)(k-zcenter)*(k-zcenter))/(rz*rz);
                    if(eq <= 1.0f) {
                        putVoxel(i, j, k);
                    }
                }
            }
        }
    }
}

//cutelipsoide
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    for(int i = xcenter - rx; i <= xcenter + rx; i++) {
        for(int j = ycenter - ry; j <= ycenter + ry; j++) {
            for(int k = zcenter - rz; k <= zcenter + rz; k++) {
                if(rx != 0 && ry != 0 && rz != 0) {
                    float eq = ((float)(i-xcenter)*(i-xcenter))/(rx*rx) +
                               ((float)(j-ycenter)*(j-ycenter))/(ry*ry) +
                               ((float)(k-zcenter)*(k-zcenter))/(rz*rz);
                    if(eq <= 1.0f) {
                        cutVoxel(i, j, k);
                    }
                }
            }
        }
    }
}

//OFF
void Sculptor::writeOFF(const char* filename) {
    std::ofstream fout(filename);

    int totalVoxels = 0;

    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int k = 0; k < nz; k++) {
                if(v[i][j][k].show) {
                    totalVoxels++;
                }
            }
        }
    }

    int totalVertices = totalVoxels * 8;
    int totalFaces = totalVoxels * 6;

    fout << "OFF\n";
    fout << totalVertices << " " << totalFaces << " 0\n";

    //vértices
    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int k = 0; k < nz; k++) {
                if(v[i][j][k].show) {
                    float x = i;
                    float y = j;
                    float z = k;

                    fout << x-0.5 << " " << y+0.5 << " " << z-0.5 << "\n";
                    fout << x-0.5 << " " << y-0.5 << " " << z-0.5 << "\n";
                    fout << x+0.5 << " " << y-0.5 << " " << z-0.5 << "\n";
                    fout << x+0.5 << " " << y+0.5 << " " << z-0.5 << "\n";
                    fout << x-0.5 << " " << y+0.5 << " " << z+0.5 << "\n";
                    fout << x-0.5 << " " << y-0.5 << " " << z+0.5 << "\n";
                    fout << x+0.5 << " " << y-0.5 << " " << z+0.5 << "\n";
                    fout << x+0.5 << " " << y+0.5 << " " << z+0.5 << "\n";
                }
            }
        }
    }

    int index = 0;

    //faces
    for(int i = 0; i < nx; i++) {
        for(int j = 0; j < ny; j++) {
            for(int k = 0; k < nz; k++) {
                if(v[i][j][k].show) {

                    this->r = v[i][j][k].r;
                    this->g = v[i][j][k].g;
                    this->b = v[i][j][k].b;
                    this->a = v[i][j][k].a;

                    fout << std::fixed << std::setprecision(1);

                    fout << "4 " << index+0 << " " << index+3 << " " << index+2 << " " << index+1 << " "
                         << r << " " << g << " " << b << " " << a << "\n";

                    fout << "4 " << index+4 << " " << index+5 << " " << index+6 << " " << index+7 << " "
                         << r << " " << g << " " << b << " " << a << "\n";

                    fout << "4 " << index+0 << " " << index+1 << " " << index+5 << " " << index+4 << " "
                         << r << " " << g << " " << b << " " << a << "\n";

                    fout << "4 " << index+0 << " " << index+4 << " " << index+7 << " " << index+3 << " "
                         << r << " " << g << " " << b << " " << a << "\n";

                    fout << "4 " << index+3 << " " << index+7 << " " << index+6 << " " << index+2 << " "
                         << r << " " << g << " " << b << " " << a << "\n";

                    fout << "4 " << index+1 << " " << index+2 << " " << index+6 << " " << index+5 << " "
                         << r << " " << g << " " << b << " " << a << "\n";

                    index += 8;
                }
            }
        }
    }

    fout.close();
}