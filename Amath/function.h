//
//  Header.h
//  Amath
//
//  Created by alex on 03/04/2020.
//  Copyright © 2020 alex. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include<cmath>
namespace Amath
{
enum functionType
   {
     type_sin,type_cos,type_tg,type_ctg,type_polynum,type_expon,type_arcsin,type_arccos,type_arctg,type_arcctg,type_log,type_sh,type_ch,type_th,type_cth,type_complex,type_constant
   };
class Function
{
protected:
    virtual float value(float x)=0;
    float value(Function& x)
    {
        return this->value(x.val);
    }
    void getNum(float x)
    {
        if(insert->type!=type_constant)
        {
            insert->enter_value=x;
        }
    }
    virtual float diff(float x)=0;
    virtual float integr(float a,float b)=0;
    float enter_value,add_value,val,dif,integ;
    Function *insert;
    functionType type;
};
class constant: Function
{
public:
    constant(float x)
    {
        enter_value=add_value=val=x;
        insert=nullptr;
        type=type_constant;
    }
    float value(float x) override
    {
        return val;
    }
    float diff(float x) override
    {
        return 0;
    }
    float integr(float a, float b) override
    {
        return(b-a);
    }
};
class sin: Function
{
    sin(Function f, float v)
    {
        enter_value=add_value=v;
        insert=&f;
        type=type_sin;
    }
};
};
#endif /* Header_h */
