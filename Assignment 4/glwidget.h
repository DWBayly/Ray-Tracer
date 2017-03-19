//-------------------------------------------------------------------------------------------
//  University of Victoria Computer Science Department
//	FrameWork for OpenGL application under QT
//  Course title: Computer Graphics CSC305
//-------------------------------------------------------------------------------------------
//These two lines are header guiardians against multiple includes
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QProgressBar>
#include "foundation.h"
#include <QtGui>
#include <QtOpenGL>
#include <math.h>
struct Sphere
{
public:
    QVector3D center;
    double radius;
    int colorR;
    int colorG;
    int colorB;
    float refl;
};
struct Plane
{
public:
    QVector3D V0;
    QVector3D V1;
    QVector3D V2;
    int colorR;
    int colorG;
    int colorB;
    float refl;
};
struct Light
{
public:
    QVector3D center;
    int radius;
    int colorR;
    int colorG;
    int colorB;
    long intensity;
};
struct Ray{
    QVector3D Origin;
    QVector3D direction;
    long maxDist;
    int depth;
};

//This is our OpenGL Component we built it on top of QGLWidget
class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    //Constructor for GLWidget
    GLWidget(QWidget *parent = 0);

    //Destructor for GLWidget
    ~GLWidget();
    int offset;
    void openImage(QString fileBuf);
    void saveImage( QString fileBuf);
    void makeImage();
    void about();
    void help();
    long findIntersect(Ray r, Sphere t);
    QColor setLighting(Ray r,Light light1,Light light2,int v,int index);
    long findIntersectL(Ray r, Light t);
    double findIntersectP(Ray r, Plane p);
    void zoomplus();
    void zoomminus();
    void xplus();
    void xminus();
    void yplus();
    void yminus();
    void lxplus();
    void lxminus();
    void lyplus();
    void lyminus();
    void lzplus();
    void lzminus();
    void setL1R(int a);
    void setL2R(int a);
    void setL1G(int a);
    void setL2G(int a);
    void setL1B(int a);
    void setL2B(int a);
    void setSCR(int a);
    void setSCG(int a);
    void setSCB(int a);
    void toggleS1();
    void toggleS2();
    QColor rayTrace(Ray r);



protected:
    //Initialize the OpenGL Graphics Engine
    void initializeGL();

    //All our painting stuff are here
    void paintGL();

    //When user resizes main window, the scrollArea will be resized and it will call this function from
    //its attached GLWidget
    void resizeGL(int w, int h);



private:
    QVector3D CameraPos;
    Light L1;
    Light L2;
    QColor ambiant;
    int ox;
    int oy;
    int lx;
    int ly;
    int lz;
    int SCR;
    int SCG;
    int SCB;
    Sphere scene[10];
    Plane p[10];
    QPoint lastMousePoint;
    bool Rotating;
    bool Scaling;
    bool perspCameraDirty;
    void clear();
    int renderWidth, renderHeight;
    void displayImage();
    bool vs1;
    bool vs2;
    QProgressBar* pbar;
    void prepareImageDisplay(QImage* myimage); // converts from Qt to opengl format
    QImage glimage, qtimage;  // paintGL will display the gl formatted image
    // keep the qtimage around for saving (one is a copy of the other

};


#endif
