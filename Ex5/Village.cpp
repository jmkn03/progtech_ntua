    #include <stdio.h>
    using namespace std;
    class roads{
    private:
        int *data;
        int sized;

    public:
        roads(int s){
        data=new int[s];
        sized=s;

        for(int i=0; i<s; i++)
        {
            data[i]=i;

        }
        }
        ~roads()
        {
        delete[] data;
        }

        int finds(int x)
        {
            if(x!=data[x])
            {
                return finds(data[x]);
            }
            return x;
        }





        void change(int p1, int p2)
        {
            data[p2]=p1;
        }
        int teams()
        {
            int t=0;
            for (int i=0; i<sized; i++)
            {
                if(data[i]==i)
                    t++;
            }
            return t;
        }

    };


    int main ()
    {
        int a,b;
        int M,N,K;
        scanf("%d", &N);
        scanf("%d", &M);
        scanf("%d", &K);
        roads r(N);
        for(int i=1; i<=M; i++)
        {
            scanf("%d", &a);
            scanf("%d", &b);
            int d1=r.finds(a-1);
            int d2=r.finds(b-1);
            if(d1!=d2)
            {   if(d1<d2)
                    r.change(d1,d2);
                else
                    r.change(d2,d1);
            }


        }


        int minimum=r.teams()-K;
        if(minimum<1)
           printf("1\n");
        else
            printf("%d\n" , minimum);
    return 0;

    }
