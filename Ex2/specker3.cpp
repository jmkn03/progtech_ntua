#include <iostream>

using namespace std;

class Game {
public:
    Game(int heaps, int players){

        CurrentPl = 0;
        h=heaps;
        pl=players;
        htemp=0;
        ptemp=0;

        Heaps = new int[heaps];
        Players = new Player*[players];

    }
    ~Game(){
        delete []Heaps;
        delete []Players;
    }

    void addHeap(int coins) throw(logic_error){
        if(coins<0) throw logic_error("invalid coins");

        Heaps[htemp] = coins;
        htemp++;
    }

    void addPlayer(Player *player) throw(logic_error){

        if(player == nullptr) throw logic_error("invalid Name");
        if(ptemp >= pl) throw logic_error("invalid Players");

        Players[ptemp] = player;
        ptemp++;
    }

    void play(ostream &out) throw(logic_error){

        State CurrentSt = State(h,Heaps,pl);
        while(!CurrentSt.winning()){

            out<<"State: ";
            for(int i=0;i<h-1;i++)
                out<<Heaps[i] << ", ";
            out<<Heaps[h-1] << " with " << CurrentPl << "/" << pl << " playing next"<<endl;

            Move NextMove = Players[CurrentPl]->play(CurrentSt);
            CurrentSt.next(NextMove);

            for(int i=0;i<h;i++)
                Heaps[i]=CurrentSt.getCoins(i);

            int SourceHeap = NextMove.getSource();
            int SourceCoins = NextMove.getSourceCoins();
            int TargetHeap = NextMove.getTarget();
            int TargetCoins = NextMove.getTargetCoins();

            out<<*Players[CurrentPl] << " takes " << SourceCoins << " coins from heap "  << SourceHeap << " and puts ";
            if(TargetCoins==0) out<<"nothing"<<endl;
            else out<<TargetCoins << " coins to heap " << TargetHeap<<endl;

            if(CurrentPl<pl-1) CurrentPl++;
            else CurrentPl=0;

        }
        out<<"State: ";
        for(int i=0;i<h-1;i++)
            out<<Heaps[i] << ", ";
        out<<Heaps[h-1] << " with " << CurrentPl << "/" << pl << " playing next"<<endl;

        if(CurrentPl > 0)
            out<<*Players[CurrentPl-1]<<" wins"<<endl;
        else  out<<*Players[pl-1]<<" wins"<<endl;

    }

    int getPlayers() const{
        return pl;
    }

    const Player *getPlayer(int p) const throw(logic_error){
        if(p<0 || p>pl) throw logic_error("invalid player number");
        return Players[p];
    }


private:
    int *Heaps,h,pl,htemp,ptemp;
    Player **Players;
    int CurrentPl;
};
