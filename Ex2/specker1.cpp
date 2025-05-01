#include <iostream>
#include <stdexcept>

using namespace std;



class Move{

private:
    int Sheap,Scoin,Theap,Tcoin;

public:
    Move(int sh, int sc, int th, int tc){
        Sheap = sh;
        Scoin = sc;
        Theap = th;
        Tcoin = tc;
    }

    int getSource() const{
        return Sheap;
    }

    int getSourceCoins() const{
        return Scoin;
    }
    int getTarget() const{
        return Theap;
    }

    int getTargetCoins() const{
        return Tcoin;
    }

    friend ostream & operator << (ostream &out, const Move &move){

        if(move.Tcoin !=0)
            out << "takes " << move.Scoin << " coins from heap " << move.Sheap << " and puts " << move.Tcoin << " coins to heap " << move.Theap;
        else
            out << "takes " << move.Scoin << " coins from heap " << move.Sheap << " and puts nothing";

        return out;
    }



};


class State{

private:
    int heaps, maxHeaps, *coins, players, playing;

public:
    State(int h, const int c[], int n){
        heaps = h;
        maxHeaps = h;
        players = n;
        coins = new int [h];

        for(int i =0; i<h; i++){
            coins[i] = c[i];
        }

        playing = 0;
    }
    ~State(){
        delete []coins;
    }

    void next(const Move &move) throw(logic_error){

        int sh = move.getSource();

        if (sh < 0 || sh >= maxHeaps) throw logic_error("invalid heap");

        int th = move.getTarget();
        int sc = move.getSourceCoins();
        int tc = move.getTargetCoins();

        coins[sh]-=sc;

        if (coins[sh] < 0 || tc >= sc) throw logic_error("invalid coins");

        coins[th]+=tc;

        if(players == 1) throw logic_error("invalid players");

        if(playing < players - 1)
            playing++;
        else
            playing = 0;

    }

    bool winning() const{
        for(int i=0; i<heaps; i++)
            if(coins[i] != 0)
                return false;
        return true;
    }

    int getHeaps() const{
        return heaps;
    }

    int getCoins(int h) const throw(logic_error){
        if (h < 0 || h >= maxHeaps) throw logic_error("invalid heap");

        return coins[h];
    }

    int getPlayers() const{
        return players;
    }

    int getPlaying() const{
        return playing;
    }

    friend ostream & operator << (ostream &out, const State &state){

        for(int i=0;i<state.heaps-1;i++)
                out<<state.coins[i]<<", ";
        out<<state.coins[state.heaps-1];
        out<<" with "<<state.playing<<"/"<<state.players<<" playing next";

        return out;
    }

};
