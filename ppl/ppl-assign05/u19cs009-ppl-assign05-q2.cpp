class Class
{

};
class Base : public Class
{

};
class D1 : virtual public Base
{

};
class D2 : virtual public Base
{

};
class MI : public D1, public D2
{

};
class Final : public MI, public Class
{
    
};