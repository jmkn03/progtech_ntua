#include <iostream>
#include <iostream>
using namespace std;

class imaginary
{
private:
    int real,fan;
public:
    imaginary(int a,int b)
    {
        real = a;
        fan = b;
    }
   friend imaginary operator +(imaginary p,imaginary r)
   {
       return imaginary(p.real + r.real,p.fan+r.fan);
   }

   friend ostream& operator <<(ostream& out,imaginary a){
        out << a.real << " " << a.fan << endl;
        return out;
   }
};

int main()
{
imaginary A(3,2);
imaginary B(1,2);
imaginary C = A+B;
cout << C;
}
