#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>

struct Vector
{
    std::vector<T> components;
    unsigned int dim;
};
template<typename T>
std::ostream& operator<<(std::ostream& ostr, const Vector<T>& vec){
    ostr << "Dimension: " << vec.dim << std::endl;
    ostr << "Components: ";
    for(int i=0;i<vec.components.size();i++){
        ostr<<vec.components[i]<<' ';
    }
    ostr<<std::endl;
    return ostr;
}
template<typename T>
std::istream& operator>>(std::istream& istr, Vector<T>& v){
    T a;
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
template<typename T>
Vector<T>& operator*=(Vector<T>& v, const double& num){
    for (auto& item : v.components){
        item*=num;
    }
    return v;
}
template<typename T>
Vector<T> operator*(const Vector<T>& v, const double& num){
    Vector<T> buff;
    buff.dim=v.dim;
    for (auto i : v.components){
        buff.components.push_back(i*num);
    }
    return buff;
}
template<typename T>
Vector<T> operator*(const double& num, const Vector<T>& v)
{
    Vector<T> buff;
    buff.dim=v.dim;
    for (auto i : v.components){
        buff.components.push_back(i*num);
    }
    return buff;
}
template<typename T>
Vector<T>& operator+=(Vector<T>& a, const Vector<T>& b)
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
template<typename T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b)
{
    if (a.dim!=b.dim){
        std::cout << "Dimension error"<<std::endl;
        Vector<T> empty;
        return empty;
    }
    Vector<T> buff;
    buff.dim=a.dim;
    for(int i=0;i<a.dim;i++)
    {
        buff.components.push_back(a.components[i]+b.components[i]);
    }
    return buff;
}
template<typename T>
Vector<T>& operator-=(Vector<T>& a, const Vector<T>& b)
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
template<typename T>
Vector<T> operator-(const Vector<T>& a, const Vector<T>& b)
{
    if (a.dim!=b.dim){
        std::cout << "Dimenson error"<<std::endl;
        Vector<T> empty;
        return empty;
    }
    Vector<T> buff;
    buff.dim=a.dim;
    for(int i=0;i<a.dim;i++)
    {
        buff.components.push_back(a.components[i]-b.components[i]);
    }
    return buff;
}
template<typename T>
Vector<T>& operator-(Vector<T>& v)
{
    for (auto& i : v.components)
    {
        i*=-1;
    }
    return v;
}
template<typename T>
double scalar(const Vector<T>& a, const Vector<T>& b)
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
template<typename T>
double vector_abs(const Vector<T>& v)
{
    double a=0;
    for (auto i : v.components){
        a+=pow(i, 2);
    }

    a=pow(a, 0.5);
    return a;
}

int main(){
    Vector<int> v;
    Vector<int> a;
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
