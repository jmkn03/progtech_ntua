#ifndef CONTEST
#include ”babyratio.hpp”
#endif
#include <iostream>
#include <cmath>

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

    rational rational::add (rational r) {

        int NewNom=nom*r.den + r.nom*den;
        int NewDen=den*r.den;

        int GCD=r.gcd(NewNom,NewDen);

        rational NewRat=rational(NewNom/GCD , NewDen/GCD);
        return NewRat;

    }


    rational rational::sub (rational r){

        int NewNom=nom*r.den - r.nom*den;
        int NewDen=den*r.den;

        int GCD=r.gcd(NewNom,NewDen);

        rational NewRat=rational(NewNom/GCD , NewDen/GCD);
        return NewRat;

    }

    rational rational::mul(rational r){

        int NewNom = nom*r.nom;
        int NewDen = den*r.den;

        rational NewRat = rational(NewNom,NewDen);
        return NewRat;
    }

    rational rational::div(rational r){

        int NewNom = nom*r.den;
        int NewDen = den*r.nom;

        rational NewRat = rational(NewNom,NewDen);
        return NewRat;

    }

    void rational::print(){

    if(nom < 0 && den > 0)
        cout << nom << "/" << den;

    else if(nom > 0 && den < 0)
        cout << (0-nom) << "/" << abs(den);

    else
        cout << nom << "/" << den;


    }

