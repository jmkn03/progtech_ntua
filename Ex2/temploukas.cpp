#include<stdexcept>
#include<iostream>
class Move {
 private:
 int apo;
 int fkalenum;
 int sto;
 int valenum;
 public:
 // Take sc coins from heap sh and put tc coins to heap th.
 Move(int sh, int sc, int th, int tc);

 int getSource() const;
 int getSourceCoins() const;
 int getTarget() const;
 int getTargetCoins() const;

 friend ostream & operator << (ostream &out, const Move &move);
 };
 Move::Move(int sh,int sc,int th,int tc){
   apo=sh;
   fkalenum=sc;
   sto=th;
   valenum=tc;
   }
int Move::getSource() const{
   return apo;
   }
int Move::getSourceCoins() const{
   return fkalenum;
   }
int Move::getTarget() const{
   return sto;
   }
int Move::getTargetCoins() const{
   return valenum;
   }
ostream & operator << (ostream &out, const Move &move){
   out<<"takes "<<move.fkalenum<<" coins from heap "<<move.apo<<" and puts ";
   if (move.valenum==0)
      out<<"nothing";
   else
      out<<move.valenum<<" coins to heap "<<move.sto;
   return out;}

   class State {
 private:
 int stives;
 int* selinia=new int[stives];
 int pextes;
 int cur;
 public:
// State with h heaps, where the i-th heap starts with c[i] coins.
// A total of n players are in the game, numbered from 0 to n-1,
// and player 0 is the first to play.
State(int h, const int c[], int n);
~State();

void next(const Move &move) throw(logic_error);
bool winning() const;

int getHeaps() const;
int getCoins(int h) const throw(logic_error);

int getPlayers() const;
int getPlaying() const;

friend ostream & operator << (ostream &out, const State &state);
};
State::State(int h, const int c[], int n){
  stives=h;
  for (int i=0;i<stives;i++)
    selinia[i]=c[i];
  pextes=n;
  cur=0;
  }
State::~State(){
  delete [] selinia;
  }
void State::next(const Move &move) throw(logic_error) {
   if (move.getSource() < 0 || move.getSource() >= stives)
     throw logic_error("invalid heap");
   if (move.getSourceCoins()>selinia[move.getSource()] || move.getTargetCoins()>= move.getSourceCoins())
     throw logic_error("invalid  coins");
   selinia[move.getSource()]=selinia[move.getSource()]-move.getSourceCoins();
   selinia[move.getTarget()]=selinia[move.getTarget()]+move.getTargetCoins();
   if (cur<pextes-1)
     cur++;
   else
     cur=0;
   }
bool State::winning()const{
  for (int l=0;l<stives;l++){
    if (selinia[l]!=0)
      return false;
   }
   return true;
  }
int State::getHeaps()const{
  return stives;
  }
int State::getCoins(int h)const throw(logic_error){
   return selinia[h];
   }
int State::getPlayers()const{
   return pextes;
   }
int State::getPlaying()const{
   return cur;
}
ostream & operator << (ostream &out, const State &state){
   for (int a=0;a<state.stives - 1; a++)
     out<<state.selinia[a]<<", ";
   out<<state.selinia[state.stives-1]<<" with "<<state.cur<<"/"<<state.pextes<<" playing next";
   }
