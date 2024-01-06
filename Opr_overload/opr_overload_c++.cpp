#include <iostream>
class A
{
    
    int m = 0;
    
    public:

    //constructors wont retuen anything..........
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

    bool operator!=(const A &rhs)
    {

        if(this->m == rhs.m)
          return true;
          else
          return false;
       
    }

    A operator + (const A &rhs)
    {

       this->m += rhs.m;
       return *this;
       
    }


    //using as friend function allows calling directly as cout<<A.
    //if we dont use as friend function we need to call as a.operator<<(std::cout);
    friend std::istream& operator>>(std::istream& os, A &a)
    {
        os>>a.m;
        return os;
    }
    void *operator new(size_t t)
    {
        return :: operator new(t);
    }

    void operator delete(void* m)
    {
        :: operator delete(m);
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
   

    m[0] = n + c;

     std::cout<<*m;
  
    return 0;
}