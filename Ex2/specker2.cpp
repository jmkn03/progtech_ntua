#include <iostream>
#include <cmath>

using namespace std;

class Player{
public:
    Player(const string &n){
        name = n;
    }

    virtual ~Player(){ }

    virtual const string & getType() const = 0;
    virtual Move play(const State &s) = 0;

    friend ostream & operator << (ostream &out, const Player &player){
        out << player.getType() << " player " << player.name;
        return out;

    }
protected:
    string name;
};

class GreedyPlayer : public Player{
public:
    GreedyPlayer(const string &n) : Player(n){
        name = n;
        coins = nullptr;
    }

    ~GreedyPlayer() override{
        delete []coins;
    }

    const string & getType()const override {
        static const string type = "Greedy";
        return type;
    }
    Move play(const State &s) override{
        coins = new int[s.getHeaps()];
        for(int i=0; i<s.getHeaps(); i++){
            coins[i] = s.getCoins(i);
        }

        int max=-1;
        int first = -1;
        for(int i=0; i<s.getHeaps(); i++){
            if(coins[i]>max){
                max = coins[i];
                first = i;
            }
        }
        int i=0;

        int Sheap,Scoin,Theap,Tcoin;
        Sheap = first;
        Scoin = coins[Sheap];

        return Move(Sheap,Scoin,Theap,Tcoin);
    }

private:
    string name;
    int *coins;
};

class SpartanPlayer : public Player{
public:
    SpartanPlayer(const string &n) : Player(n){
        name = n;
        coins = nullptr;
    }

    ~SpartanPlayer() override{
        delete []coins;
    }

    const string & getType() const override {
        static const string type = "Spartan";
        return type;
    }
    Move play(const State &s) override{
        coins = new int[s.getHeaps()];
        for(int i=0; i<s.getHeaps(); i++){
            coins[i] = s.getCoins(i);
        }

        int max=-1;
        int first = -1;
        for(int i=0; i<s.getHeaps(); i++){
            if(coins[i]>max){
                max = coins[i];
                first = i;
            }
        }

        int i=0;

        int Sheap,Scoin,Theap,Tcoin;
        Sheap = first;
        Scoin=1;

        return Move(Sheap,Scoin,Theap,Tcoin);

    }
private:
    string name;
    int *coins;
};

class SneakyPlayer : public Player{
public:
    SneakyPlayer(const string &n) : Player(n){
        name = n;
        coins = nullptr;
    }

    ~SneakyPlayer()override{
        delete []coins;
    }

    const string & getType()const override {
        static const string type = "Sneaky";
        return type;
    }
    Move play(const State &s) override {
        coins = new int[s.getHeaps()];
        for(int i=0; i<s.getHeaps(); i++){
            coins[i] = s.getCoins(i);
        }

        int min=1000000;
        int first = 0;
        for(int i=0; i<s.getHeaps(); i++){
            if(coins[i]<min && coins[i] > 0){
                min = coins[i];
                first = i;
            }
        }
        int i=0;

        int Sheap,Scoin,Theap,Tcoin;
        Sheap = first;
        Scoin = coins[Sheap];

        return Move(Sheap,Scoin,Theap,Tcoin);
    }

private:
    string name;
    int *coins;
};

class RighteousPlayer : public Player{
public:
    RighteousPlayer(const string &n) : Player(n){
        name = n;
        coins = nullptr;
    }

    ~RighteousPlayer() override{
        delete []coins;
    }

    const string & getType() const override {
        static const string type = "Righteous";
        return type;
    }
    Move play(const State &s)override{
        coins = new int[s.getHeaps()];
        for(int i=0; i<s.getHeaps(); i++){
            coins[i] = s.getCoins(i);
        }

        int max=-1;
        int first = -1;
        for(int i=0; i<s.getHeaps(); i++){
            if(coins[i]>max){
                max = coins[i];
                first = i;
            }
        }

        int lfirst=0;
        int i=0;

        int min=coins[0];
        for(int i=1; i<s.getHeaps(); i++){
            if(coins[i]<min){
                min = coins[i];
                lfirst = i;
            }
        }

        int Sheap,Scoin,Theap,Tcoin;
        Sheap = first;
        if(max%2==0)
            Scoin = max/2;
        else
            Scoin = (max+1) / 2;
        Tcoin = Scoin - 1;
        Theap = lfirst;

        return Move(Sheap,Scoin,Theap,Tcoin);
    }

private:
    string name;
    int *coins;
};
