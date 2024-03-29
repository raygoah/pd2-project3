#include "horizontal.h"

Horizontal::Horizontal()
{

}

Horizontal::~Horizontal()
{

}

int Horizontal::condition(Blank *a[10][10], Blank *focus)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    if(num!=0 && num!=5){
        if(num<10){
        if(C>=1 && C<=7 &&(num==a[R][C-1]->number||num==a[R][C-1]->number/10)
                        &&(num==a[R][C+1]->number||num==a[R][C+1]->number/10)
                        &&(num==a[R][C+2]->number||num==a[R][C+2]->number/10)){
            return 1;
        }
        if(C>=2 && C<=8 &&(num==a[R][C-2]->number||num==a[R][C-2]->number/10)
                        &&(num==a[R][C-1]->number||num==a[R][C-1]->number/10)
                        &&(num==a[R][C+1]->number||num==a[R][C+1]->number/10)){
            return 2;
        }
    }
    }
    return 0;
}

void Horizontal::spawn(Blank *a[10][10], Blank *focus, int mode)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    int FiveN[4]={0};
    Destroy *d;
    switch(mode){//switch


        case 1:
        focus->number=focus->number*10+1;

        if(a[R][C-1]->number/10!=0)FiveN[0]=a[R][C-1]->number%10;
        FiveN[1]=a[R][C]->number;
        if(a[R][C+1]->number/10!=0)FiveN[2]=a[R][C+1]->number%10;

        if(a[R][C+2]->number/10!=0)FiveN[3]=a[R][C+2]->number%10;
            switch(FiveN[0]){
            case 0:
                a[R][C-1]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C-1]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C-1]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C-1]);
                delete d;
                break;
           }
            switch(FiveN[1]){
            case 0:
                a[R][C]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C]);
                delete d;
                break;
           }
                switch(FiveN[2]){
                case 0:
                    a[R][C+1]->number=0;
                    break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+1]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+1]);
                    delete d;
                    break;
                case 3:
                    d=new NineBlock;
                    d->eliminate(a,a[R][C+1]);
                    delete d;
                    break;
               }
                switch(FiveN[3]){
                case 0:
                    a[R][C+2]->number=0;
                    break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+2]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+2]);
                    delete d;
                    break;
                case 3:
                    d=new NineBlock;
                    d->eliminate(a,a[R][C+2]);
                    delete d;
                    break;
               }

        break;
        /**********************/
    case 2:
    focus->number=focus->number*10+1;
    if(a[R][C-2]->number/10!=0)FiveN[0]=a[R][C-2]->number%10;
    if(a[R][C-1]->number/10!=0)FiveN[1]=a[R][C-1]->number%10;
    FiveN[2]=a[R][C]->number;
    if(a[R][C+1]->number/10!=0)FiveN[3]=a[R][C+1]->number%10;

    for(int i=0;i<2;i++){
        Destroy *d;
        switch(FiveN[i]){
        case 0:
            a[R][C-2+i]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[R][C-2+i]);
            delete d;
            break;
        case 2:
            d=new Horizontal;
            d->eliminate(a,a[R][C-2+i]);
            delete d;
            break;
        case 3:
            d=new NineBlock;
            d->eliminate(a,a[R][C-2+i]);
            delete d;
            break;
       }
    }

            Destroy *d;
            switch(FiveN[2]){
            case 0:
                a[R][C]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C]);
                delete d;
                break;
           }
            switch(FiveN[3]){
            case 0:
                a[R][C+1]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C+1]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C+1]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C+1]);
                delete d;
                break;
           }



    break;

        /*******************************************************/

}
}

void Horizontal::eliminate(Blank *a[10][10], Blank *focus)
{
    int R=focus->row;
    focus->number=0;
    int TenN[10]={0};
    Destroy* d;
    for(int i=0;i<10;i++){
        if(a[R][i]->number/10!=0){
            TenN[i]=a[R][i]->number%10;
        }
        }
    for(int i=0;i<10;i++)
    {
        switch(TenN[i]){
        case 0:
            a[R][i]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[R][i]);
            delete d;
            break;
        case 2:
            d=new Horizontal;
            d->eliminate(a,a[R][i]);
            delete d;
            break;
        case 3:
            d=new NineBlock;
            d->eliminate(a,a[R][i]);
            delete d;
            break;
        }
    }
}

