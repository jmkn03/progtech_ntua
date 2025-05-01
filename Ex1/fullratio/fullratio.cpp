#include <iostream>
#include <iostream>
#ifndef CONTEST
#include ”fullratio.hpp”
#endif

using namespace std;

rational::rational (int n, int d) {

    int GCD=gcd(n,d);

    nom=n/GCD;
    den=d/GCD;

}

int rational::gcd(int a,int b){

    if(a==0)
        return b;
    return gcd(b%a,a);

}

rational operator + (const rational &x, const rational &y){

    int NewNom=x.nom*y.den + y.nom*x.den;
    int NewDen=x.den*y.den;

    int GCD=y.gcd(NewNom,NewDen);

    rational NewRat=rational(NewNom/GCD , NewDen/GCD);
    return NewRat;
}

rational operator - (const rational &x, const rational &y){

    int NewNom=x.nom*y.den - y.nom*x.den;
    int NewDen=x.den*y.den;

    int GCD=y.gcd(NewNom,NewDen);

    rational NewRat=rational(NewNom/GCD , NewDen/GCD);
    return NewRat;

}

rational operator * (const rational &x, const rational &y){
    int NewNom = x.nom*y.nom;
    int NewDen = x.den*y.den;

    rational NewRat = rational(NewNom,NewDen);
    return NewRat;

}

rational operator / (const rational &x, const rational &y){

    int NewNom = x.nom*y.den;
    int NewDen = x.den*y.nom;

    rational NewRat = rational(NewNom,NewDen);
    return NewRat;

}

ostream & operator << (std::ostream &out, const rational &x){

    if(x.nom < 0 && x.den > 0)
        cout << x.nom << "/" << x.den;

    else if(x.nom > 0 && x.den < 0)
        cout << (0-x.nom) << "/" << abs(x.den);

    else
        cout << x.nom << "/" << x.den;
}

