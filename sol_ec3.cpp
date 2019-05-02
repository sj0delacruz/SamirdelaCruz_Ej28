#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;



int main(){
    ofstream outfile;
    int nX=200,nTim=3000,K=210;
    float dX=0.03,dTim=0.9,SPH=900,RHO=2700;

    double temp[nX][2], temp_pl[nX][200];

    for (int ix=1; ix<nX-1; ix++){
        temp[ix][0]=100;
    }
    temp[0][0]=0,temp[0][1]=0,temp[nX-1][0]=0,temp[nX-1][1]=1;
    float c1=K/(SPH*RHO)*dTim/(dX*dX);
    int m=1;
    int ix1;
    for (int t=1; t<nTim; t++){
        for (int ix=1; ix<nX-1; ix++){
            temp[ix][1]=temp[ix][0]+c1*(temp[ix+1][0]+temp[ix-1][0]-2*temp[ix][0]);
        }
        
            ix1=1;
            while (ix1<nX-1){
                temp_pl[ix1][m]=temp[ix1][1];
                ix1+=1;
            }
            
        
        for (int ix=1; ix<nX-1; ix++){
            temp[ix][0]=temp[ix][1];
        }
    }
    outfile.open("dat_ec3.dat");
    /*imprime*/
    for(int j=0;j<200;j++){
        for(int i=0;i<nX;i++){
          outfile << temp_pl[i][j] << endl;
        }
    }
    return 0;
}

