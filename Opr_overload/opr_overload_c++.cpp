#include <iostream>
class A
{
    
    int m = 0;
    
    public:
    A(int n = 0):m{n}
    {
    }
    A(const A &a)
    {
        if(this != &a)
            this->m = a.m;
    }
    
    A operator=(const A &a)
    {
        this->m = a.m;
        return *this;
    }
    
  friend std::istream& operator>>(std::istream& os, A &a)
    {
        os>>a.m;
        return os;
    }
    void *operator new(size_t t)
    {
        return :: operator new(t);
    }
    
 friend std::ostream& operator<<(std::ostream& os,const A &n) 
    {
        os << "Value: " << n.m;
        return os;
    }
    
};



int main() {
    // Write C++ code here

    
    A n(900);
    A c;
    A* m = new A[10];
    c = n;
    std::cout<<c<<*m;
  
    return 0;
}