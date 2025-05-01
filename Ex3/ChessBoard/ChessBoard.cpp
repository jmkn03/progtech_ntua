#include<iomanip>
#include<stdexcept>
#include<iostream>

using namespace std;

class ChessBoardArray{
protected:

    class Row{
    public:

        Row(ChessBoardArray &a,int i): cba(a),  RowNumber(i) {}

        int& operator [] (int i) const {
            return cba.select(RowNumber , i);
        }

    private:
        ChessBoardArray &cba;
        int RowNumber;
    };

    class ConstRow{
    public:

        ConstRow(const ChessBoardArray &a,int i):cba(a), RowNumber(i) {}

        int operator [] (int i) const{
           return cba.select(RowNumber,i);
        }

    private:
        const ChessBoardArray &cba;
        int RowNumber;
    };

public:
    ChessBoardArray(unsigned size = 0, unsigned base = 0);

    ChessBoardArray(const ChessBoardArray &a);

    ~ChessBoardArray(){
        delete [] Data;
    }

    int& select(int i,int j);

    int select(int i,int j) const;

    const Row operator [] (int i){
        return Row(*this,i);
    }

    const ConstRow operator [] (int i) const{
        return ConstRow(*this,i);
    }

    ChessBoardArray & operator = (const ChessBoardArray &a){
        delete [] Data;
        Base=a.Base;
        Size=a.Size;
        int size2d = (Size*Size+1)/2;
        Data=new int[size2d];

        for(unsigned i=0; i<size2d; ++i)
            Data[i]=a.Data[i];

        return *this;
    }

    friend ostream& operator << (ostream &out, const ChessBoardArray &a){
        for(int line=0;line<a.Size;line++){
            for(int column=0;column<a.Size;column++){
                out<<setw(4);

                if((line+column)%2==0)
    				cout<<a.select(line+a.Base,column+a.Base);
    			else cout<<0;
            }
            out<<endl;
        }
        return out;
    }

private:

    unsigned int loc(int i,int j) const throw(out_of_range){

        int tempi=i-Base, tempj=j-Base;
        if(tempi<0 || tempi>=Size || tempj<0 || tempj>=Size || (i+j)%2==1) throw out_of_range("invalid index");

        return (tempi*Size +tempj)/2;
    }

    int Size,Base;
    int *Data;
};

ChessBoardArray::ChessBoardArray (unsigned size,unsigned base){
    Size = size; // size x size/2
    Base = base;
    int size2d = (Size*Size+1)/2;

    Data = new int[size2d];

    for(int i=0;i<size2d;i++)
        Data[i]=0;
}

ChessBoardArray::ChessBoardArray(const ChessBoardArray &a){
    Size = a.Size;
    Base = a.Base;
    int size2d = (Size*Size+1)/2;

    Data = new int[size2d];

    for(int i=0;i<size2d;i++)
        Data[i]=a.Data[i];
}

int& ChessBoardArray::select(int i,int j){
    return Data[loc(i,j)];
}

int ChessBoardArray::select(int i,int j) const{
    return Data[loc(i,j)];
}
