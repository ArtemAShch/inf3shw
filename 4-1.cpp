#include <iostream>
#include <vector>
#include <algorithm>

struct Vector
{
    std::vector<double> components;
    unsigned int dim;
};

std::ostream& operator<<(std::ostream& ostr, const Vector& vec){
    ostr << "Dimension: " << vec.dim << std::endl;
    ostr << "Components: ";
    for(int i=0;i<vec.components.size();i++){
        ostr<<vec.components[i]<<' ';
    }
    ostr<<std::endl;
    return ostr;
}

std::istream& operator>>(std::istream& istr, Vector& v){
    double a;
    std::cout << "Enter the dimension:";
    istr >> v.dim;
    std::cout << "Enter the components:";
    for(int i=0;i<v.dim;i++){
        istr >> a;
        v.components.push_back(a);
    }
    std::cout << std::endl;
    return istr;
}

Vector& operator*=(Vector& v, const double& num){
    for (auto& item : v.components){
        item*=num;
    }
    return v;
}

Vector operator*(const Vector& v, const double& num){
    Vector buff;
    buff.dim=v.dim;
    for (auto i : v.components){
        buff.components.push_back(i*num);
    }
    return buff;
}

Vector operator*(const double& num, const Vector& v)
{
    Vector buff;
    buff.dim=v.dim;
    for (auto i : v.components){
        buff.components.push_back(i*num);
    }
    return buff;
}

Vector& operator+=(Vector& a, const Vector& b)
{
    if (a.dim!=b.dim)
    {
        std::cout << "Dimension error"<<std::endl;
        return a;
    }
    for (int i=0;i<a.dim;i++){
        a.components[i]+=b.components[i];
    }
    return a;
}

Vector operator+(const Vector& a, const Vector& b)
{
    if (a.dim!=b.dim){
        std::cout << "Dimension error"<<std::endl;
        Vector empty;
        return empty;
    }
    Vector buff;
    buff.dim=a.dim;
    for(int i=0;i<a.dim;i++)
    {
        buff.components.push_back(a.components[i]+b.components[i]);
    }
    return buff;
}

Vector& operator-=(Vector& a, const Vector& b)
{
    if (a.dim!=b.dim)
    {
        std::cout << "Dimension error"<<std::endl;
        return a;
    }
    for (int i=0;i<a.dim;i++){
        a.components[i]-=b.components[i];
    }
    return a;
}

Vector operator-(const Vector& a, const Vector& b)
{
    if (a.dim!=b.dim){
        std::cout << "Dimenson error"<<std::endl;
        Vector empty;
        return empty;
    }
    Vector buff;
    buff.dim=a.dim;
    for(int i=0;i<a.dim;i++)
    {
        buff.components.push_back(a.components[i]-b.components[i]);
    }
    return buff;
}

Vector& operator-(Vector& v)
{
    for (auto& i : v.components)
    {
        i*=-1;
    }
    return v;
}

double scalar(const Vector& a, const Vector& b)
{
    if (a.dim!=b.dim)
    {
        std::cout << "Dimension error"<<std::endl;
        return 0;
    }
    double res=0;
    for (int i=0;i<a.dim;i++){
        res+=a.components[i]*b.components[i];
    }
    return res;
}

double vector_abs(const Vector& v)
{
    double a=0;
    for (auto i : v.components){
        a+=pow(i, 2);
    }

    a=pow(a, 0.5);
    return a;
}

int main(){
    Vector v;
    Vector a;
    std::cin>>v;
    std::cout<<v;
    a=v*2;
    std::cout<<a;
    a+=v;
    std::cout<<a;
    double sc;
    sc = scalar(a, v);
    std::cout<<sc;
}