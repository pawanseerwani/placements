#include<iostream>
using namespace std;
class a1
{  public  :
    ~a1()
{
cout<<"~a1";
}
};
class b1:public a1
{
public  :
    ~b1()
{
cout<<"~b1";
}
};
class a2
{ public  :
    virtual ~a2()
{
cout<<"~a2";
}
};
class b2: public a2
{
    public  :
virtual ~b2()
{
cout<<"~b2";
}
};
int main()
{
a1 *p = new b1;
delete p;
a2 *q= new b2;
delete q;
}
