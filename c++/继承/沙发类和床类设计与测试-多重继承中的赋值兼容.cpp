/*设有家具类Furniture，包含数据家具类型、家具材料和家具价格。要求设计沙发类Sofa和床类Bed都来自同一个基类Furniture，Sofa类新增了座位数，Bed类新增了床的类型。定义一个普通函数show用于输出不同派生类对象的家具信息*/
#include<iostream>  
#include<string>  
using namespace std;  
class Furniture       //家具类  
{     
protected:            
    string type;         //家具类型  
    string mat;      //家具主材料  
    double price;        //家具价格  
public:  
    Furniture(){};  
    Furniture(const string &type1, const string &mat1, double price1): type(type1),  
                mat (mat1),price(price1){}  
    string getMaterial(){ return mat; }  
    double getPrice(){ return price; }  
    string getType(){ return type; }  
}; 
class Sofa:public Furniture  //沙发类，继承自家具类  
{  
private:
    int seatNum;        //座位数  
public:
    Sofa(const string &type1, const string &mat1, double price1, int seatNum1): Furniture(type1, mat1, price1), seatNum(seatNum1){}  
    int getSeatNum(){ return seatNum; }  
};
class Bed:public Furniture   //床类，继承自家具类  
{  
private:    string bedType;     //床的类型  
public:
    Bed(const string &type1, const string &mat1, double price1, const string &bedType1): Furniture(type1, mat1, price1), bedType(bedType1){}  
    string getBedType(){ return bedType; }  
};
void show(Sofa &s)
{    cout<<"家具类型:"<<s.getType()<<",主材料:"<<s.getMaterial()<<",价格:"<<s.getPrice()<<endl;  
}
void show(Bed &b)
{    cout<<"家具类型:"<<b.getType()<<",主材料:"<<b.getMaterial()<<",价格:"<<b.getPrice()<<endl;  
}
int main()  
{  
    Sofa sofa1("沙发","木材",870.00,3);  
    Bed  bed1("床","铁",1280.00,"双人");      
    show(sofa1);   
    show(bed1);  
    return 0;  
}
/*家具类型:沙发,主材料:木材,价格:870↵
家具类型:床,主材料:铁,价格:1280↵*/