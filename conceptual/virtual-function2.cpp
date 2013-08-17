#include<iostream>
using namespace std;
class animal
{
    public :
void virtual print()
{
cout<<"animal";
}
};
class leopard: public animal
{
    public :
void print()
{
cout<<"leapard";
}
};
int main()
{
animal *p= new animal;
p->print();
}
