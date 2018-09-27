#include "display.h"
void display() {
    static Vec pos[10];
    static Vec anc[10];
    static int carflag[10] = {0};
    static int j = 0;
    static Car car[10];
    static int k=0;//flag: if k!=0, then we can know that the loop has covered generating the random number
    static int lot[10]={0};
    static int emptylot[10]={0};
    static int num=0;
    if (k==0){
        srand(time(NULL));
        lot[rand()%10]=3;
        for (int i=0;i<10;i++){
            if(lot[i]!=3) lot[i]=rand()%4;
            if(lot[i]==3) {
                emptylot[num]=i;num++;
            }
        }
    }
	
	
    if (carflag[j]==0&&j<num) carflag[j]=1;
    CarParking(&pos[j], &anc[j], &carflag[j], emptylot[j]);
    if (carflag[j] == 10) j++;
    glClear(GL_COLOR_BUFFER_BIT);

    CarPark();

    //rectangle (center block)
    glColor3f(0.4f, 0.2f, 0.7f);    //color setting
    glRectf(-80, 7, 80, 25);
    for (int i=0;i<10;i++){
        if (carflag[i] != 0) {
            Car ttmp(pos[i], anc[i]);
            car[i] = ttmp;
            car[i].draw();
        }
    }

    static Vec ufoanc(7,0);
    for(int i=0;i<10;i++){
        if(lot[i]==0){
            if(i<=4){
                Vec ufopos(-68+34*i,-48);
                UFO ufo(ufopos,ufoanc);
                ufo.draw();
            }
            else{
                Vec ufopos(238-34*i,78);
                UFO ufo(ufopos,ufoanc);
                ufo.draw();
            }
        }
    }
    ufoanc=ufoanc<<0.02;

    static float kk=0.4;static int airflag=0;
    for(int i=0;i<10;i++){
        if(lot[i]==1){
            if(i<=4){
                Vec airpos(-68+34*i,-52);
                Aircraft air(airpos,kk);
                air.draw();
            }
            else{
                Vec airpos(238-34*i,66);
                Aircraft air(airpos,kk);
                air.draw();
            }
        }
    }
    if (airflag==0) kk*=1.01;
    else if(airflag==1) kk/=1.01;
    if(kk>0.5) airflag=1;
    if(kk<0.3) airflag=0;

    for(int i=0;i<10;i++){
        if(lot[i]==2){
            if(i<=4){
                Vec recpos(-75+34*i,-56);
                Vec size(30/2,52/2);
                rectangle rec;
                rec.setAnchor(size);
                rec.setPosition(recpos);
                rec.setAngle(PI/3);
                rec.setcolor(sinf(0.01*k+i),cosf(0.01*k+i),sinf(0.01*k-i));
                rec.draw();
            }
            else{
                Vec recpos(231-34*i,62);
                Vec size(30/2,52/2);
                rectangle rec;
                rec.setAnchor(size);
                rec.setPosition(recpos);
                rec.setAngle(PI/3);
                rec.setcolor(cosf(0.01*k+2*i),sinf(0.01*k+i),sinf(0.01*k-3*i));
                rec.draw();
            }
        }
    }
    glFlush();
    k++;
}