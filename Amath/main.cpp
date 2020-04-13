//
//  main.cpp
//  math base
//
//  Created by alex on 27/03/2020.
//  Copyright © 2020 alex. All rights reserved.
//

#include <iostream>
#include"Amath.hpp"
#include "matrix.hpp"
#include"function.h"
int main(int argc, const char * argv[]) {
    using namespace Amath;
    int b=1,c=1;
     Matrix<float> matrix(3,3);
    Matrix<float> mat(3,3);
    for(int i=0;i<3;i++)
    {

        for(int j=0;j<3;j++)
        {
            std::cin>>b;
            matrix.setElement(i, j, b);
        }
    }
    
    mat=matrix;
    matrix.setTriangle();
    matrix.deleteColum(0);
    matrix.deleteRow(0);
    std:: cout << matrix.Rang() << std::endl;
    for(int i=0;i<2;i++)
       {
           for(int j=0;j<2;j++)
           {
               
               std::cout<<mat.getElement(i, j) << " ";
           }
           std:: cout << std::endl;
       }
    return 0;
}

