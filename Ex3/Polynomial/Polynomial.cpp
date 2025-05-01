#include <iostream>
#include <cmath>

using namespace std;


class Polynomial{

 protected:
    class Term{
     public:
        int exponent; // power
        int coefficient; //ex. 3x
        Term *next;
     protected:
        Term(int exp, int coeff, Term *n): exponent(exp),coefficient(coeff),next(n){}

        friend class Polynomial;
    };

 public:
     Polynomial(){ //constructor
        terms = 0;
        first = nullptr;
     }

     Polynomial(const Polynomial &p) {//copy constructor
        terms = p.terms;
        first = nullptr;
        Term *temp = p.first;

        while(temp){
            addTerm(temp->exponent,temp->coefficient);
            temp=temp->next;
        }
     }


     ~Polynomial(){//destructor
        //delete term;
        Term *temp=first;
        while(temp){
            Term *del = temp;
            temp=temp->next;
            delete del;
        }
     }

     Polynomial & operator = (const Polynomial &p){
        Term *temp = first; //beginning of polynomial (first term)
        while(temp){
            Term *del = temp;
            temp = temp->next;
            delete del;
        }

        Term *ptemp = p.first;
        while(ptemp){
            addTerm(ptemp->exponent,ptemp->coefficient);
            ptemp=ptemp->next;
        }
        return *this;

     }


     void addTerm(int expon, int coeff){

        Term *t = new Term(expon,coeff,nullptr);
        if(!first){
            first = t;
            terms++;
            return;
        }
        else if(expon > first->exponent){
            t->next = first;
            first = t;
            return;
        }
        else if(first->exponent == expon){
            first->coefficient += coeff;
            delete t;
            return;
        }

        else{
            Term *temp = first;
            while(temp->next && expon < temp->next->exponent){
                temp = temp->next;
            }

            if(expon == temp->exponent){
                temp->coefficient += coeff;
                delete t;
                return;
            }

            else if(temp->next && temp->next->exponent == expon){
                temp->next->coefficient += coeff;
                delete t;
                return;
            }
            else{
                t->next = temp->next;
                temp->next = t;
                return;
            }
        }
     }

     double evaluate(double x){
        double sum=0;

        Term *temp = first;

        if(first==nullptr)
            return 0;

        while(temp){
            sum+=temp->coefficient * pow(x,temp->exponent);
            temp = temp->next;
        }
        return sum;
     }


     friend Polynomial operator +(const Polynomial &p, const Polynomial &q){

        Term *ptemp = p.first, *qtemp=q.first;
        Polynomial a;

        while(ptemp && qtemp){
            if(ptemp->exponent == qtemp->exponent){
                int exp = ptemp->exponent;
                int co = ptemp->coefficient + qtemp->coefficient;
                a.addTerm(exp,co);
                ptemp = ptemp->next;
                qtemp = qtemp->next;

            }
            else if(ptemp->exponent > qtemp->exponent){
                a.addTerm(ptemp->exponent,ptemp->coefficient);
                ptemp=ptemp->next;
            }
            else{
                a.addTerm(qtemp->exponent,qtemp->coefficient);
                qtemp=qtemp->next;
            }
        }
        while(ptemp){
            a.addTerm(ptemp->exponent,ptemp->coefficient);
            ptemp=ptemp->next;
        }
        while(qtemp){
            a.addTerm(qtemp->exponent,qtemp->coefficient);
            qtemp=qtemp->next;
        }

        return a;
     }

     friend Polynomial operator *(const Polynomial &p, const Polynomial &q){
        Polynomial a;
        Term *ptemp=p.first;
        while(ptemp){
            Term *qtemp = q.first;
            while(qtemp){
                a.addTerm(ptemp->exponent+qtemp->exponent,ptemp->coefficient*qtemp->coefficient);
                qtemp = qtemp->next;
            }
            ptemp=ptemp->next;
        }
        return a;
     }

     friend ostream & operator <<(ostream &out, const Polynomial &p){

        Term *temp = p.first;
        if(temp == nullptr){
            out << '0';
            return out;
        }

        while(temp && temp->coefficient == 0){
            temp=temp->next;
            if(temp == nullptr){
                out << '0';
                return out;
            }
        }

        if(temp->coefficient < 0)
            out << "- ";
        if(abs(temp->coefficient) != 1)
            out << abs(temp->coefficient);
        if(temp->exponent == 0 && abs(temp->coefficient) == 1)
            out << '1';
        if(temp->exponent == 1)
            out << 'x';
        else if(temp->exponent !=0)
            out << "x^" << temp->exponent;

        temp=temp->next;

        while(temp != nullptr) {
            if(temp->coefficient != 0){
                if(temp->coefficient < 0) {
                    out << " - " ;
                }
                else {
                    out << " + ";
                }
                if(abs(temp->coefficient) != 1 || temp->exponent == 0) {
                    out << abs(temp->coefficient);
                }
                if(temp->exponent == 1) {
                    out << 'x';
                }
                else if(temp->exponent != 0) {
                    out << "x^" << temp->exponent;
                }
            }
            temp = temp->next;
        }
        return out;
     }

 private:
    int terms;
    Term *first;
    //Term *term;
};
