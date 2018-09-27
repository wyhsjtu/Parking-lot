#include "carparking.h"
void CarParking(Vec* _pos,Vec* _anc,int* carflag,int lot){
    int flag=*carflag;
    Vec pos=*_pos;
    Vec anc=*_anc;
    if(lot<=4&&flag==3){
        if(abs(pos.getX()-(34*lot-63))<2&&anc.getX()>0){
            flag=6;
            Vec d(34*lot-63,pos.getY());
            pos=d;
        }
    }
    else if(lot>4&&flag==5){
        if(abs(pos.getX()-(-34*(lot-5)+73))<1&&anc.getX()<0){
            flag=8;
            Vec d((-34*(lot-5)+73),pos.getY());
            pos=d;
        }
    }
    if(flag==1){
        Vec a(0,0.5);
        Vec mm(0,0.4);
        anc=mm;
        pos=pos+a;
        *_pos=pos;
        if(pos.getY()==-50) flag=2;
    }
    else if(flag==2){
        anc=(anc<<-PI/100);
        pos=pos+anc*3.2;
        if(abs(anc.getY())<0.001) {anc={0.4,0};flag=3;};
    }
    else if(flag==3){
        Vec b(0.5,0);
        pos=pos+b;
        *_pos=pos;
        if(abs(pos.getX()-75)<1) flag=4;
    }
    else if(flag==4){
        anc=(anc<<PI/100);
        pos=pos+anc*2.1;
        if(abs(anc.getY())<0.001&&anc.getX()<0) {anc={-0.4,0};flag=5;};
    }
    else if(flag==5){
        Vec c(-0.5,0);
        pos=pos+c;
        *_pos=pos;
    }
    else if(flag==6){
        Vec e(0.5,0);
        pos=pos+e;
        *_pos=pos;
        if(abs(pos.getX()-(34*lot-63+30))<1) flag=7;
    }
    else if(flag==7){
        anc=(anc<<PI/100);
        pos=pos-anc*3;
        if(abs(anc.getX())<0.001){flag=10;};
    }
    else if(flag==8){
        Vec f(-0.5,0);
        pos=pos+f;
        *_pos=pos;
        if(abs(pos.getX()-(-34*(lot-5)+73-34))<1) flag=9;
    }
    else if(flag==9){
        anc=(anc<<PI/100);
        pos=pos-anc*2.3;
        if(abs(anc.getX())<0.001){flag=10;};
    }
    *_pos=pos;
    *_anc=anc;
    *carflag=flag;
}