#include <GL/glut.h>
#include <cmath>
#include "figures.h"
figure::~figure() {}

//----------1  Rectangle

void rectangle::draw() {
    glColor3f(r, g, b); glBegin(GL_QUADS); glVertex2f(position.getX(),position.getY());
    glVertex2f((position+anchor*0.5+(anchor*0.5<<ang*(-2))).getX(), (position+anchor*0.5+(anchor*0.5<<ang*(-2))).getY());
    glVertex2f((position+anchor).getX(), (position+anchor).getY());
    glVertex2f((position+anchor*0.5-(anchor*0.5<<ang*(-2))).getX(),(position+anchor*0.5-(anchor*0.5<<ang*(-2))).getY());
    glEnd();
}
//------------2 Triangle
void Triangle::draw() {
    Vec length(anchor.getX(),anchor.getY());
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(position.getX(), position.getY());
    glVertex2f(position.getX()+length.getX(),position.getY()+length.getY());
    length= length<<M_PI/3;
    glVertex2f(position.getX()+length.getX(),position.getY()+length.getY());
    glEnd();
}


void Trapezoid::draw() {
    Vec length(anchor.getX(),anchor.getY());
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(position.getX(), position.getY());
    glVertex2f(position.getX()+length.getX(),position.getY()+length.getY());
    length= length<<M_PI/6;
    length=length*0.8660254038;
    glVertex2f(position.getX()+length.getX(),position.getY()+length.getY());
    length= length<<M_PI/6;
    length=length*0.5773502692;
    glVertex2f(position.getX()+length.getX(),position.getY()+length.getY());
    glEnd();
}

void Circle::draw() {
    int i = 0;
    float R=sqrtf(anchor.getX()*anchor.getX()+anchor.getY()*anchor.getY());
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (i = 0; i < 100; i++)
    {
        glVertex2f(position.getX()+R*cosf(2*PI/100*i), position.getY()+R*sinf(2*PI/100*i));
    }
    glEnd();
}

void HalfCircle::draw() {
    int i = 0;
    Vec tmp=anchor;
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (i=0; i <50; i++)
    {
        glVertex2f(position.getX()+tmp.getX(), position.getY()+tmp.getY());
        tmp=tmp<<0.02*PI;
        tmp*2;
    }
    glEnd();
}

void Group::draw() {/*
    for(int i=0;i<10;i++)
    { fig[i]->draw();
    }*/
}

    void Group::rotate(float angle){
   anchor= anchor<<angle;
}
/*
Group::~Group(){
    for(int i=0;i<10;i++)
    {delete fig[i];

    }};*/
void Aircraft::zoom(float* _k){
int static i=0;
if(k>=0.01 && i==0) zoomout(_k);
else if (k<=0.03) { i=1; zoomin(_k); }
else i=0;
}
void Aircraft::zoomout(float* _k){
    k/=1.01; *_k=k;
}
void Aircraft::zoomin(float* _k){
k*=1.01; *_k=k;
}
Occupied::Occupied() {
    figu=new rectangle;
    figu->setAnchor(anchor);
    figu->setPosition(position);
    figu->setAngle(1.03038);
    paint(&r,&g,&b);
    figu->setcolor(r,g,b);
}
void Occupied::draw() {
    figu->draw();
}
void Occupied::paint(float *r, float *g, float *b) {
    *r=(float)rand()/RAND_MAX; *g=(float)rand()/RAND_MAX;
    *b=(float)rand()/RAND_MAX;
    }
Aircraft::Aircraft(Vec pos,float _k) {
    k=_k;
    setPosition(pos);
    colored[0]=new Trapezoid;
    setAnchor({-6,-5.19615});
    colored[0]->setPosition(position+anchor*k);
    colored[0]->setAnchor({12*k,0});
    colored[0]->setcolor(0.2,0.1,0.8);

    colored[1]=new Triangle;
    setAnchor({-10,0});
    colored[1]->setPosition(position+anchor*k);
    colored[1]->setAnchor({10*k,0});
    colored[1]->setcolor(0.7,0.6,0.2);

    colored[2]=new Triangle;
    setAnchor({0,0});
    colored[2]->setPosition(position+anchor*k);
    colored[2]->setAnchor({10*k,0});
    colored[2]->setcolor(0.4,0.6,0.2);

    colored[3]=new Triangle;
    setAnchor({-5,35});
    colored[3]->setPosition(position+anchor*k);
    colored[3]->setAnchor({10*k,0});
    colored[3]->setcolor(0.4,0.3,0.8);


    rec[0]=new rectangle;
    setAnchor({-5,0});
    rec[0]->setPosition(position+anchor*k);
    rec[0]->setAngle(1.292496668);
    rec[0]->setAnchor({10 *k,35*k});
    rec[0]->setcolor(0.2,0.6,0.4);


    rec[1]=new rectangle;
    setAnchor({-1.5,20});
    rec[1]->setPosition(position+anchor*k);
    rec[1]->setAngle(1.107148718);
    rec[1]->setAnchor({3*k,6*k});
    rec[1]->setcolor(0.1,0.8,0.4);

    rec[2]=new rectangle;
    setAnchor({-4,28});
    rec[2]->setPosition(position+anchor*k);
    rec[2]->setAngle(0.7853981634);
    rec[2]->setAnchor({2*k,2*k});
    rec[2]->setcolor(0.3,0.4,0.2);

    rec[3]=new rectangle;
    setAnchor({2,28});
    rec[3]->setPosition(position+anchor*k);
    rec[3]->setAngle(0.7853981634);
    rec[3]->setAnchor({2*k,2*k});
    rec[3]->setcolor(0.6,0.4,0.7);

}
void Aircraft::draw() {
    for(int i=0;i<4;i++)
    { colored[i]->draw();
    }
    for(int i=0;i<4;i++)
    { rec[i]->draw();
    }

}

UFO::UFO(Vec pos, Vec anc) {
    setPosition(pos);
    setAnchor(anc);
    fig[0]=new HalfCircle;
    fig[0]->setAnchor(anchor);
    fig[0]->setPosition(position);
    fig[0]->setcolor(0,0,1);

    fig[1]=new Trapezoid;
    fig[1]->setAnchor(anchor*0.5);
    fig[1]->setPosition(position+anchor*0.25-(anchor*0.21<<0.5*PI));
    fig[1]->setcolor(1,1,0);

    fig[2]=new Trapezoid;
    fig[2]->setAnchor(anchor*0.5);
    fig[2]->setPosition(position-anchor*0.75-(anchor*0.18<<0.5*PI));
    fig[2]->setcolor(1,1,0);
}

void UFO::draw() {
    for (int i=0;i<3;i++){
        fig[i]->draw();
    }
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2f(position.getX()+(anchor<<0.333*PI).getX(),position.getY()+(anchor<<0.333*PI).getY());
    glVertex2f(position.getX()+(anchor*1.5<<0.333*PI).getX(),position.getY()+(anchor*1.5<<0.333*PI).getY());
    glVertex2f(position.getX()+(anchor<<0.667*PI).getX(),position.getY()+(anchor<<0.667*PI).getY());
    glVertex2f(position.getX()+(anchor*1.5<<0.667*PI).getX(),position.getY()+(anchor*1.5<<0.667*PI).getY());
    glEnd();

}

void UFO::rotate(Vec* anc) {
    anchor=(anchor<<0.02);
    *anc=anchor;
}
Car::Car(Vec pos, Vec anc) {
    setPosition(pos);
    setAnchor(anc);
    Vec p1{0,0};
    p1=anchor<<PI;//anchor is a unit vector indicate the move direction of the car.
    p1=p1*20;
    colored[0]=new Trapezoid;
    colored[0]->setPosition(position+p1);
    p1=anchor;
    p1=p1*40;
    colored[0]->setAnchor(p1);
    colored[0]->setcolor(0.1,0,0.9);

    rec=new rectangle;
    p1=anchor<<3.816333596;
    p1=p1*32.01562119;
    rec->setPosition(position+p1);
    rec->setAngle(0.3805063771);
    p1=anchor<<0.3805063771;
    p1=p1*53.85164807;
    rec->setAnchor(p1);
    rec->setcolor(0.5,0.5,0.5);

    colored[1]=new Circle;
    p1=anchor<<PI*1.25;
    p1=p1*28.28427125;
    colored[1]->setPosition(position+p1);
    p1=anchor*4;
    colored[1]->setAnchor(p1);
    colored[1]->setcolor(0,0,0);

    colored[2]=new Circle;
    p1=anchor<<PI*1.75;
    p1=p1*28.28427125;
    colored[2]->setPosition(position+p1);
    p1=anchor*4;
    colored[2]->setAnchor(p1);
    colored[2]->setcolor(0,0,0);
}
void Car::draw() {
    rec->draw();
    for(int i=0;i<3;i++)
    { colored[i]->draw();
    }
}
void Car::rotate(Vec* anc) {
    anchor=(anchor<<0.02);
    *anc=anchor;
}
void Car::move(Vec* vir) {
    position=(position<<0.02);
    *vir=position;
}



