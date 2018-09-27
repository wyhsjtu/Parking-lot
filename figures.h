//
// Created by M S I on 2018-07-30.
//
#ifndef OPENGL_FIGURES_H
#define OPENGL_FIGURES_H
static const float PI=3.14159;
typedef struct _Point {
    float x,y;
} Point;

class Vec{
private:
    float x,y;
public:
    Vec(){
        x=-108;y=-80;
    }
    Vec(float _x, float _y){
        x=_x; y=_y;
    }
    float getX(){return x;}
    float getY() {return y;}
    //Operate on vector
    Vec operator+(Vec v){
        return Vec(x+v.getX(),y+v.getY());
    }
    //overload
    Vec operator-(Vec v){
        return Vec(x-v.getX(),y-v.getY());
    }
    Vec operator*(float k){
        return Vec(k*x,k*y);
    }

    float  getproduct(Vec v1, Vec v2){
        return v1.x*v2.x+v1.y*v2.y;
    }
    //Towards rotation
    Vec operator<<(float ang){
        return Vec(x*cosf(ang)-y*sinf(ang),y*cosf(ang)+x*sinf(ang));
    }
};

class figure {
public:
    figure():anchor(0, 0),position(0,0){}// Attention: how anchor will be defined?
    Vec getAnchor() {return anchor;}
    void setAnchor(Vec a) {anchor = a;}
    Vec getPosition() {return position;}
    void setPosition(Vec p) {position = p;}
    virtual void draw() = 0;
    virtual ~figure();
protected:
    Vec anchor;
    Vec position;
};

class coloredFig:public figure{
protected:
    float r,g,b;
public:
    coloredFig():r(0),g(0),b(0){}
    void setcolor(float _r,float _g,float _b){
        r=_r;g=_g;b=_b;
    }
};

class rectangle:public coloredFig {
public:
    //specific points need to be changed
    rectangle(){
        ang=0.25*PI;
        Vec a(1,1);
        setAnchor(a);
    };
    void setAngle(float _ang){ang=_ang;};
    void draw();

private:
    float ang;
};

class Triangle: public coloredFig{
public:
    Triangle(){
    Vec a(1,1);
        setAnchor(a);
    };
    void draw();
};

class Trapezoid: public coloredFig{//梯形
public:
    Trapezoid(){
        Vec a(1,1);
        setAnchor(a);
    };
    void draw();

};


class Circle: public coloredFig{
public:
    Circle(){
        Vec a(1,0);
        setAnchor(a);
    };
    void draw();
};

class HalfCircle: public coloredFig{
public:
    HalfCircle(){
        Vec a(1,0);
        setAnchor(a);
    };
    void draw();
};
class Group : public figure{
public:
    Group(){};
    virtual void draw();
    //virtual void move(Vec dir);
    virtual void rotate(float angle);
    //virtual void zoom()=0;
    ~Group(){};
private:
    //figure *fig[20];

};

class Occupied: public Group{
public:
    Occupied();
    virtual void draw();
private:
    rectangle* figu;
    void paint(float *r, float *g, float *b);
    float r,g,b;
};//用一种变色的矩形解决//

class Aircraft: public Group{
public:
    Aircraft(Vec pos,float _k);
    virtual void zoom(float* _k);
    virtual void draw();
    ~Aircraft(){
        delete rec[0];
        delete rec[1];
        delete rec[2];
        delete rec[3];
        delete colored[0];
        delete colored[1];
        delete colored[2];
        delete colored[3];}
private:
    rectangle* rec[4];
    coloredFig* colored[4];
    float k;
    void zoomin(float* _k);
    void zoomout(float* _k);
};
class Car: public Group{
private:
    rectangle* rec;
    coloredFig* colored[3];
public:
    Car(Vec pos, Vec anc);
    Car(){
        rec=NULL;
        colored[3]=NULL;
    }
    void rotate(Vec* anc);
    virtual void draw();
    virtual void move(Vec* dir);
    ~Car(){
        delete colored[0];
        delete colored[1];
        delete colored[2];
        delete rec;
    }
};

class UFO: public Group{
private:
    coloredFig* fig[3];
public:
    UFO(Vec pos,Vec anc);
    void rotate(Vec* anc);
    void draw();
    ~UFO(){
        delete fig[0];
        delete fig[1];
        delete fig[2];
    }
};

#endif //OPENGL_FIGURES_H
