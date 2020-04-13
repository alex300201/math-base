//
//  Function.hpp
//  math base
//
//  Created by alex on 27/03/2020.
//  Copyright © 2020 alex. All rights reserved.
//

#ifndef Function_hpp
#define Function_hpp
#include<cmath>
#include <stdio.h>
namespace Amath
    {
        namespace base_operation
        {
      static int factorial(int a)
        {
            int result=1;
            for(int i=1;i<=a;i++)
            {
                result*=i;
            }
            return result;
        }
        static long factorial(long a)
               {
                   int result=1;
                   for(int i=1;i<=a;i++)
                   {
                       result*=i;
                   }
                   return result;
               }
        };
        namespace progreation
        {
          namespace progreation_arf
            {
              static int sum(int first,int diffierence, int n)
                {
                    return first*n+(diffierence*n*(n-1))/2;
                }
                static long sum(long first,long diffierence, long n)
                {
                    return first*n+(diffierence*n*(n-1))/2;
                }
                static float sum(float first,float diffierence, float n)
                {
                    return first*n+(diffierence*n*(n-1))/2;
                }
                static double sum(double first,double diffierence, double n)
                {
                    return first*n+(diffierence*n*(n-1))/2;
                }
                static int n_number(int first, int diffierence, int n)
                {
                    return first+diffierence*(n-1);
                }
                static long n_number(long first, long diffierence, long n)
                {
                    return first+diffierence*(n-1);
                }
                static float n_number(float first, float diffierence, float n)
                {
                    return first+diffierence*(n-1);
                }
                static double n_number(double first, double diffierence, double n)
                {
                    return first+diffierence*(n-1);
                }
            };
            namespace progreation_geom
            {
                static int sum(int first,int denominator, int n)
                {
                    return first*(pow(denominator,n)-1)/(denominator-1);
                }
                static long sum(long first,long denominator, long n)
                {
                    return first*(pow(denominator,n)-1)/(denominator-1);
                }
                static float sum(float first,float denominator, float n)
                {
                    return first*(pow(denominator,n)-1)/(denominator-1);
                }
                static double sum(double first,double denominator, double n)
                {
                    return first*(pow(denominator,n)-1)/(denominator-1);
                }
                static int n_number(int first, int denominator, int n)
                {
                    return first*pow(denominator,(n-1));
                }
                static long n_number(long first, long denominator, long n)
                {
                    return first*pow(denominator,(n-1));
                }
                static float n_number(float first, float denominator, float n)
                {
                    return first*pow(denominator,(n-1));
                }
                static double n_number(double first, double denominator, double n)
                {
                    return first*pow(denominator,(n-1));
                }
            };
        };
      namespace average
        {
            static int mean_arf(int a, int b)
            {
                return (a+b)/2;
            }
            static long mean_arf(long a, long b)
            {
                return (a+b)/2;
            }
            static float mean_arf(float a, float b)
            {
                return (a+b)/2;
            }
            static double mean_arf(double a, double b)
            {
                return (a+b)/2;
            }
            static int mean_geom(int a, int b)
            {
                return sqrt(a*b);
            }
            static long mean_geom(long a, long b)
            {
                return sqrt(a*b);
            }
            static float mean_geom(float a, float b)
            {
                return sqrt(a*b);
            }
            static double mean_geom(double a, double b)
            {
                return sqrt(a*b);
            }
            static int mean_harmonic(int a, int b)
            {
                return 2*(a*b)/(a+b);
            }
            static long mean_harmonic(long a, long b)
            {
                return 2*(a*b)/(a+b);
            }
            static float mean_harmonic(float a, float b)
            {
                return 2*(a*b)/(a+b);
            }
            static double mean_harmonic(double a, double b)
            {
                return 2*(a*b)/(a+b);
            }
            static int mean_sqr(int a, int b)
            {
                return sqrt((a*a+b*b)/2);
            }
            static long mean_sqr(long a, long b)
            {
                return sqrt((a*a+b*b)/2);
            }
            static float mean_sqr(float a, float b)
            {
                return sqrt((a*a+b*b)/2);
            }
            static double mean_sqr(double a, double b)
            {
                return sqrt((a*a+b*b)/2);
            }
        };
    };

        
    
  
#endif /* Function_hpp */
