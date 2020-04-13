//
//  matrix.hpp
//  math base
//
//  Created by alex on 29/03/2020.
//  Copyright © 2020 alex. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
namespace Amath
    {
    template<typename T>
    void swap(T &a,T &b)
    {
        T c;
        c=a;
        a=b;
        b=c;
    }
template<typename T>
class Matrix
{
public:
    Matrix(int h, int l): hight(h), lenght(l){
        matrix = new T *[hight];
               for (int i = 0; i < hight; i++) {
                   matrix[i] = new T [lenght];
               }
    }
    Matrix(int s):hight(s), lenght(s){
        matrix = new T *[hight];
               for (int i = 0; i < hight; i++) {
                   matrix[i] = new T [lenght];
               }
    }
    void setElement(int h, int l,T e)
    {
        if((h<hight)&&(l<lenght))
        {
        matrix[h][l]=e;
    }
        else
        {
            std:: cout <<"Eror";
        }
    }
    T getElement(int h, int l)
     {
         if((h<hight)&&(l<lenght))
         {
         return matrix[h][l];
     }
         else
         {
             std:: cout <<"Eror element not found";
             return 0;
         }
     }
    T detrminator()
    {
        if(hight==lenght)
        {
            T resultat = 0;
        int c=1;
        int hhight=hight-1,hlenght=lenght-1;
        if(hight>2)
        {
        for(int i=0;i<lenght;i++)
        {
        Matrix *helper = new Matrix<T>(hhight,hlenght);
            for(int j=1;j<hight;j++)
            {
                for(int k=0;k<i;k++)
                {
                    helper->setElement(k, j-1,this->getElement(k, j));
                }
                for(int k=i;k<hlenght;k++)
                {
                    helper->setElement(k, j-1,this->getElement(k+1, j));
                
                }
            }
             resultat+=helper->detrminator()*c*this->getElement(i, 0);
            c*=-1;
            delete helper;
         
    }
        }
        else if(hight==2)
        {
            resultat=this->getElement(0, 0)*this->getElement(1, 1)-this->getElement(0, 1)*this->getElement(1, 0);
        }
            else
            {
                resultat=this->getElement(0, 0);
            }
        return resultat;
        
    }
        else
        {
            std:: cout << " Determinator cannot be calculated";
            return 0;
        }
    }
    void swapRow(int a,int b)
    {
        for(int i=0;i<lenght;i++)
        {
            swap<T>(matrix[a][i],matrix[b][i]);
        }
    }
    void swapColum(int a,int b)
    {
        for(int i=0;i<hight;i++)
        {
            swap<T>(matrix[i][a],matrix[i][b]);
        }
    }
    void deleteRow(int a)
    {
        
        for(int j=0;j<hight;j++)
        {
            for(int k=a;k<lenght-1;k++)
            {
                matrix[j][k]=matrix[j][k+1];
            }
            //delete matrix[j][lenght];
    }
        lenght--;
    }
    void deleteColum(int a)
    {
        
        for(int j=0;j<lenght;j++)
        {
            for(int k=a;k<hight-1;k++)
            {
                this->matrix[k][j]=this->matrix[k+1][j];
            }
            //delete matrix[hight][j];
        }
        hight--;
    }
    Matrix transsmition()
    {
        Matrix *help= new Matrix<T>(lenght,hight);
        for(int j=0;j<lenght;j++)
        {
            for(int i=0;i<hight;i++ )
            {
                help->setElement(i, j, matrix[j][i]);
            }
        }
        return help;
        delete help;
    }
    void multipRow(int r,T m)
    {
        for(int i=0;i<lenght;i++)
        {
            matrix[r][i]*=m;
        }
    }
    void multipColum(int r,T m)
     {
         for(int i=0;i<hight;i++)
         {
             matrix[i][r]*=m;
         }
     }
    void sumRow(int a,int b)
    {
        for(int i=0;i<lenght;i++)
        {
            matrix[b][i]+=matrix[a][i];
        }
    }
    void sumColum(int a,int b)
       {
           for(int i=0;i<hight;i++)
           {
               matrix[i][b]+=matrix[i][a];
           }
       }
    void setTriangle()
    {
       if(lenght>=hight)
       {
           int z=-1;
           for(int i=0;i<hight;i++)
           {
               z++;
               if(z==lenght)
               {
                   break;
               }
               for(int j=i;(j<hight)&&(matrix[i][z]==0);j++)
               {
                   swapRow(i, j);
               }
            while(matrix[i][z]==0)
            {
                if(z+1!=lenght)
                z++;
                else
                {
                    z++;
                    break;
                }
            }
               if(z==lenght)
               {
                   break;
               }
               for(int k=i+1;k<hight;k++)
                {
                    if(matrix[k][z]!=0)
                    {
                      const  T a=-1*matrix[k][z]/matrix[i][z];
                    this->multipRow(i, a);
                    this->sumRow(i,k);
                        this->multipRow(i, 1/a);
                    }
                }
           }
       }
        else
        {
            int z=-1;
                      for(int i=0;i<lenght;i++)
                      {
                          z++;
                          if(z==hight)
                                                   {
                                                       break;
                                                   }
                          for(int j=i;(j<lenght)&&(matrix[z][i]==0);j++)
                          {
                              swapColum(i, j);
                          }
                       while(matrix[z][i]==0)
                       {
                           if(z+1!=hight)
                           z++;
                           else
                           {
                               z++;
                               break;
                           }
                       }
                          if(z==hight)
                          {
                              break;
                          }
                          for(int k=i+1;k<lenght;k++)
                           {
                               if(matrix[z][k]!=0)
                               {
                                  const T a=-1*matrix[z][k]/matrix[z][i];
                               this->multipColum(i, a);
                               this->sumColum(i,k);
                                   this->multipColum(i, 1/a);
                               }
                           }
                      }
        }
    }
int Rang()
    {
        Matrix *helper = new Matrix<T>(hight, lenght);
        for(int i=0;i<lenght;i++)
        {
            for(int j=0;j<hight;j++)
            {
                helper->setElement(j, i, matrix[j][i]);
            }
        }
        if(lenght>=hight)
        {
            helper->setTriangle();
            int c=hight;
            for(int j=0;j<hight;j++)
            {
                int d=0;
                for(int i=0;i<lenght;i++)
                {
                    if(helper->getElement(j, i)!=0)
                    {
                        d++;
                    }
                }
                if(d==0)
                {
                    c--;
                }
            }
            return c;
        }
        else
        {
            helper->setTriangle();
            int c=lenght;
            for(int j=0;j<lenght;j++)
            {
                int d=0;
                for(int i=0;i<hight;i++)
                {
                    if(helper->getElement(i, j)!=0)
                    {
                        d++;
                    }
                }
                if(d==0)
                {
                    c--;
                }
            }
               return c;
        }
     
    }
void  operator=(Matrix<T> &m)
    {
        if((m.hight==this->hight)&&(m.lenght==this->lenght))
      for(int i=0;i<hight;i++)
            {
                for(int j=0;j<lenght;j++)
                {
                    this->matrix[i][j]=m.matrix[i][j];
                }
            }
        else
        {
            std::cout<< "Erorr diffirent sizes";
        }
    }
    void operator+=(Matrix<T> &m)
    {
         if((m.hight==this->hight)&&(m.lenght==this->lenght))
       for(int i=0;i<hight;i++)
             {
                 for(int j=0;j<lenght;j++)
                 {
                     this->matrix[i][j]+=m.matrix[i][j];
                 }
             }
         else
         {
             std::cout<< "Erorr diffirent sizes";
         }
     }
    void operator-=(Matrix<T> &m)
     {
          if((m.hight==this->hight)&&(m.lenght==this->lenght))
        for(int i=0;i<hight;i++)
              {
                  for(int j=0;j<lenght;j++)
                  {
                      this->matrix[i][j]-=m.matrix[i][j];
                  }
              }
          else
          {
              std::cout<< "Erorr diffirent sizes";
          }
     }
    Matrix operator +(Matrix<T> m)
        {
            Matrix *resultat = new Matrix<T>(this->hight,this->lenght);
            if((m.hight==this->hight)&&(m.lenght==this->lenght))
                 for(int i=0;i<hight;i++)
                       {
                           for(int j=0;j<lenght;j++)
                           {
                              resultat->matrix[i][j]=this->matrix[i][j]+m.matrix[i][j];
                           }
                           return resultat;
                           delete resultat;
                       }
                   else
                   {
                       std::cout<< "Erorr diffirent sizes";
                       throw;
                   }
               }
    T minor(int h, int l)
    {
        Matrix *helper=new Matrix<T>(hight,lenght);
        helper->deleteColum(h);
        helper->deleteRow(l);
        return helper->detrminator();
        delete helper;
    }
private:
    int  hight;
    int lenght;
   T **matrix;
};
    };
#endif /* matrix_hpp */
