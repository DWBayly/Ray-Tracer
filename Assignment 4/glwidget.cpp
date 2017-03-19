//-------------------------------------------------------------------------------------------
//   Painting with Flowsnakes
// fsnake program modified to use open gl vertex arrays  Brian Wyvill October 2012
// added save/restore and postscript driver November 2012
// fixed memory management November 2012 delete works properly now.
// added progress bar to show memory usage.
//-------------------------------------------------------------------------------------------
/*CSC 305 Assignment 3/4
 * Written by David Bayly V00786662
 * Based on code Written by Brian Wyvil
 * This program features:
 * Style/documentation ?/2
 * Reflections-4pts
 * Multiple light sources 3 pts
 * Ability to set Arbitrary Camera View point 4 pts
 * Interactive UI for camera, material and light source Parameters 4 pts
 * Cast sufficient rays to be anti-Aliased -4pts
 * Put Sphere in room like space and render walls in different colors 3pts
 * Make Sphere reflective and reflect the color of the walls 3pts
 * total points = ?/2 + 25/23
 *
 *

*/
#include "glwidget.h"
#include <qcolor.h>
GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{

}
GLWidget::~GLWidget()
{    

}
void GLWidget::clear()
{
     updateGL();
}
void GLWidget::initializeGL()
{
    SCR=255;//Sphere color red
    SCG=0;//green
    SCB=0;// blue
    vs1=false;//Light source 1 visible?
    vs2=false;//Light source 2 visible?
    offset=-900;
    ox=0;//light and camera offsets
    lx=0;
    ly=0;
    oy=0;
    lz=0;
    ambiant=QColor(100,100,100);
    //set base light color and radius
    L1.colorR=255;
    L1.colorG=0;
    L1.colorB=0;
    L1.intensity=0.7;
    L1.radius=100;
    L2.colorR=0;
    L2.colorG=0;
    L2.colorB=255;
    L2.intensity=0.7;
    L2.radius=100;
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel( GL_FLAT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glPointSize(5);
}
void GLWidget::zoomplus(){
    offset=offset+100;
}
void GLWidget::zoomminus(){//zoom camera out
    offset=offset-100;
}
void GLWidget::xminus(){//move camera left
    ox=ox-100;
}
void GLWidget::xplus(){//move camera Right
    ox=ox+100;
}
void GLWidget::yminus(){//camera up
    oy=oy-100;
}
void GLWidget::yplus(){//camera down
    oy=oy+100;
}
void GLWidget::lxminus(){//light movement methods
    lx=lx-150;
}
void GLWidget::lxplus(){
    lx=lx+150;

}
void GLWidget::lyminus(){
    ly=ly-150;

}
void GLWidget::lyplus(){
    ly=ly+150;

}
void GLWidget::lzminus(){
    lz=lz-150;
}
void GLWidget::lzplus(){
    lz=lz+150;
}
void GLWidget::toggleS1(){//view light methods
    if(vs1){
        vs1=false;
    }else{
        vs1=true;
    }
}
void GLWidget::toggleS2(){
    if(vs2){
        vs2=false;
    }else{
        vs2=true;
    }
}
void GLWidget::setSCR(int a){//Sphere color methods
    SCR=a;
}
void GLWidget::setSCG(int a){
    SCG=a;
}
void GLWidget::setSCB(int a){
    SCB=a;
}
void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    displayImage();
}
void GLWidget::resizeGL( int w, int h )
{
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0.0,GLdouble(w),0,GLdouble(h),-10.0,10.0);
    glFlush();
    glMatrixMode(GL_MODELVIEW);
    glViewport( 0, 0, (GLint)w, (GLint)h );
    cerr << "gl new size "<< w SEP h NL;
    renderWidth = w;
    renderHeight = h;
}
void GLWidget::openImage(QString fileBuf)
{     
    QImage myImage;
    myImage.load(fileBuf);
    prepareImageDisplay(&myImage);
}
void GLWidget::prepareImageDisplay(QImage* myimage)
{   
    glimage = QGLWidget::convertToGLFormat( *myimage );  // flipped 32bit RGBA stored as mi
    updateGL();    
}
void GLWidget::displayImage()
{
    if (glimage.width()==0) {
        cerr << "Null Image\n";
        return;
    } else {
        glRasterPos2i(0,0);
        glDrawPixels(glimage.width(), glimage.height(), GL_RGBA, GL_UNSIGNED_BYTE, glimage.bits());
        glFlush();
    }
}
void GLWidget::saveImage( QString fileBuf )
{
    // there is no conversion  back toQImage
    // hence the need to keep qtimage as well as glimage
    qtimage.save ( fileBuf );   // note it is the qtimage in the right format for saving
}

void GLWidget::makeImage( )
{   
    QImage myimage(renderWidth, renderHeight, QImage::Format_RGB32);
    QColor color[9];
    QColor colorf;
    //TODO: Ray trace a simple circle following the tutorial!
    QVector3D CamPt (3*renderWidth/2+ox,3*renderHeight/2+oy,offset);//Camera origin point
    QVector3D SP(1000,1000,-200);
    QVector3D LightPt2(1200,1000,200);//second light source origin
    QVector3D LightPt(lx+1300,ly+600,-100+lz);//first light source origin
    scene[0].center=SP;
    scene[0].colorR=SCR;
    scene[0].colorG=SCG;
    scene[0].colorB=SCB;
    scene[0].radius=220;
    scene[0].refl=0.5;
    SP.setX(800);
    SP.setY(600);
    SP.setZ(-200);
    scene[1].center=SP;
    scene[1].colorR=255-SCR;
    scene[1].colorG=255-SCG;
    scene[1].colorB=255-SCB;
    scene[1].radius=220;
    scene[1].refl=0.5;
    L1.center=LightPt;
    L2.center=LightPt2;
    Ray r;
    r.Origin=CamPt;
    //create box
    p[0].colorB=255;
    p[0].colorG=0;
    p[0].colorB=0;
    QVector3D SP1(500,500,0);
    p[0].V0=SP1;
    QVector3D SP2(1500,500,0);
    p[0].V1=SP2;
    QVector3D SP3(1500,1500,0);
    p[0].V2=SP3;
    SP2.setY(1500);
    SP2.setX(500);
    p[1].V1=SP2;
    p[1].V0=SP1;
    p[1].V2=SP3;
    p[2].V0=SP2;
    SP2.setZ(-1000);
    p[2].V1=SP2;
    SP2.setY(500);
    p[2].V2=SP2;
    p[3].V0=SP2;
    SP2.setZ(0);
    p[3].V1=SP2;
    SP2.setY(1500);
    p[3].V2=SP2;
    SP2.setX(500);
    SP2.setY(500);
    SP2.setZ(0);
    p[4].V0=SP2;
    SP2.setZ(-1000);
    p[4].V1=SP2;
    SP2.setX(1500);
    p[4].V2=SP2;
    p[5].V0=SP2;
    SP2.setZ(0);
    p[5].V1=SP2;
    SP2.setX(500);
    p[5].V2=SP2;
    SP2.setY(1500);
    SP2.setX(500);
    SP2.setZ(0);
    p[6].V0=SP2;
    SP2.setZ(-1000);
    p[6].V1=SP2;
    SP2.setX(1500);
    p[6].V2=SP2;
    p[7].V0=SP2;
    SP2.setZ(0);
    p[7].V1=SP2;
    SP2.setX(500);
    p[7].V2=SP2;
    for (int i=0;i<renderWidth; ++ i){
        for(int j=0;j < renderHeight; ++j){
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                  QVector3D dir(i*3+k,j*3+l,r.Origin.z()+900);//cast ray
                  r.direction=dir-CamPt;
                  r.direction.normalize();
                  r.depth=5;
                  color[3*k+l]=rayTrace(r);
                }
            }
            //take average of previous 9 rays cast
            colorf.setRed((color[0].red()+color[1].red()+color[2].red()+color[3].red()+color[4].red()+color[5].red()+color[6].red()+color[7].red()+color[8].red())/9);
            colorf.setBlue((color[0].blue()+color[1].blue()+color[2].blue()+color[3].blue()+color[4].blue()+color[5].blue()+color[6].blue()+color[7].blue()+color[8].blue())/9);
            colorf.setGreen((color[0].green()+color[1].green()+color[2].green()+color[3].green()+color[4].green()+color[5].green()+color[6].green()+color[7].green()+color[8].green())/9);
            myimage.setPixel(i,j, colorf.rgb());//set color
        }
    }
    qtimage=myimage.copy(0, 0,  myimage.width(), myimage.height());

    prepareImageDisplay(&myimage);
}
QColor GLWidget::rayTrace(Ray r){
    QColor ret(0,0,0);
    if(r.depth==0){
        return ret;
    }
    float max[3];
    int index[2];
    max[0]=max[1]=max[2]=index[0]=index[1]=0;
    int cur;
    QColor color= ret;
    int o=8;
    for(int k=0;k<o;k++){
        cur=findIntersectP(r,p[k]);
        if(cur>max[0]){
            max[0]=cur;
            index[0]=k;
        }
    }
    if(max[0]>0){
        QColor tmp(0,0,0);
        if(index[0]<2){
            tmp.setBlue(255);
        }else if(index[0]<4){
            tmp.setRed(255);
        }else if(index[0]<6){
            tmp.setGreen(255);
        }else{
            tmp.setBlue(255);
            tmp.setGreen(255);
        }
        color=tmp;
    }
    for(int k=0;k<10;k++){
        cur=findIntersect(r,scene[k]);
        if(cur>max[1]){
            max[1]=cur;
            index[1]=k;
        }
    }
    cur=findIntersectL(r,L1);
    max[2]=findIntersectL(r,L2);
    index[2]=1;
    if(cur>max[2] && vs1){
        max[2]=cur;
        index[2]=0;
    }else if(!(vs2)){
        max[2]=0;
    }
    if(max[1]>max[0] && max[1]>max[2] && max[1]>0){
        color=setLighting(r,L1,L2,max[1],index[1]);
    }else if(max[2]>max[1] && max[2]>max[0] && max[2]>0){
        if(index[2]==0){
            color=qRgb(L1.colorR,L1.colorG,L1.colorB);
        }else if(index[2]==1){
            color=qRgb(L2.colorR,L2.colorG,L2.colorB);
        }else{
            color=ret;
        }
    }

    return color;
}

QColor GLWidget::setLighting(Ray r ,Light light1, Light light2, int v,int index){
    /*This method determines the color of a pixel that has intersected a sphere
     * The shading on the sphere is Phong.
     * It uses a recursive call to rayTrace to get reflections.
     *
    */
   QVector3D D=r.Origin+v*r.direction;//Intersection point on sphere
   QVector3D N=(D-scene[index].center)/scene[index].radius;//Normal of the sphere
   //N.normalize();
   QVector3D L1=light1.center-D;//Vector to lightsource 1
   QVector3D L2=light2.center-D;//vector to lightsource 2
   L1.normalize();
   L2.normalize();
   float factor1 = 0.9*N.dotProduct(N,L1);//calculate lighting coefficients
   float factor2 = 0.9*N.dotProduct(N,L2);
   if(factor1<0){
       factor1=0;//if factors are negative,make it zero
   }
   if(factor2<0){
       factor2=0;
   }
    //set base colors
   long colorR=scene[index].colorR*0.1+factor1*light1.colorR+factor2*light2.colorR;
   long colorG=scene[index].colorG*0.1+factor1*light1.colorG+factor2*light2.colorG;
   long colorB=scene[index].colorB*0.1+factor1*light1.colorB+factor2*light2.colorB;
   Ray r2;//cast new ray from the surface of the sphere
   r2.depth=r.depth-1;
   r2.direction=r.direction-2.0f*D.dotProduct(r.direction,N)*N;
   r2.Origin=D;
   QColor a=rayTrace(r2);

   //make sure all values are positive
   if(a.red()<1){
       a.setRed(0);
   }
   if(a.green()<1){
       a.setGreen(0);
   }
   if(a.blue()<1){
       a.setBlue(0);
   }
       colorR=(a.red()*0.25+colorR);//add values to scene
       colorG=(a.green()*0.25+colorG);
       colorB=(a.blue()*0.25+colorB);
   if(colorR>255){
       colorR=255;//ensure colors are within limits
   }
   if(colorG>255){
       colorG=255;
   }
   if(colorB>255){
       colorB=255;
   }

   return QColor(colorR,colorG,colorB);
}
void GLWidget::setL1R(int a){//The following methods determine lighting properties
    L1.colorR=a;
}
void GLWidget::setL2R(int a){
    L2.colorR=a;
}
void GLWidget::setL1G(int a){
    L1.colorG=a;
}
void GLWidget::setL2G(int a){
    L2.colorG=a;
}
void GLWidget::setL1B(int a){
    L1.colorB=a;
}
void GLWidget::setL2B(int a){
    L2.colorB=a;
}
double GLWidget::findIntersectP(Ray r, Plane p){
//triangles, how do they work?
    QVector3D U=p.V1-p.V0;
    QVector3D V=p.V2-p.V0;
    QVector3D N=V.crossProduct(U,V);//Normal vector of plane/trangle
    QVector3D W0=r.Origin-p.V0;
    double a= -N.dotProduct(N,W0);
    double b=N.dotProduct(N,r.direction);
    if(fabs(b)<0.001){
        return 0;
    }
    double t=a/b;
    if(t<0.0){
        return 0;
    }
    QVector3D I=r.Origin+t*r.direction;//intersection point with plane
    float uu,uv,vv,wu,wv,D;
    uu=U.dotProduct(U,U);
    uv=U.dotProduct(U,V);
    vv=U.dotProduct(V,V);
    QVector3D W=I-p.V0;
    wu=W.dotProduct(W,U);
    wv=W.dotProduct(W,V);
    D=uv*uv-uu*vv;
    float s,l;
    s=(uv*wv-vv*wu)/D;
    if(s<0.0 || s>1.0){//determine if the point is within the bounds of the triangle
        return 0;
    }
    l=(uv*wu-uu*wv)/D;
    if(l<0.0 || (s+l)>1.0){
        return 0;
    }

    return t;//return the distance from the camera of the intersection point
}
long GLWidget::findIntersectL(Ray r, Light t){
    //intersections found using geometric method
    //Algorithm found at http://www.scratchapixel.com/old/lessons/3d-basic-lessons/lesson-7-intersecting-simple-shapes/ray-sphere-intersection/
    QVector3D L = t.center - r.Origin;
        int tca = L.dotProduct(L,r.direction);
        if(tca<0){
                return 0;
        }else{
            int d2 = L.dotProduct(L,L) - tca*tca;
            if(d2>t.radius){
                    return 0;
            }else{
                int thc = sqrt(t.radius-d2);
                int t0= tca - thc;
                int t1=tca + thc;
                if (t1<t0){//return closest intersection point
                    return t1;
                }
               return t0;
            }

        }
}

long GLWidget::findIntersect(Ray r, Sphere t){
    //intersections found using geometric method
    //Algorithm found at http://www.scratchapixel.com/old/lessons/3d-basic-lessons/lesson-7-intersecting-simple-shapes/ray-sphere-intersection/
    QVector3D L = t.center - r.Origin;
    int tca = L.dotProduct(L,r.direction);
    if(tca<0){
            return 0;
    }else{
        int d2 = L.dotProduct(L,L) - tca*tca;//check distance from center
        if(d2>t.radius*t.radius){
                return 0;
        }else{
            int thc = sqrt(t.radius*t.radius-d2);
            int t0= tca - thc;//use quadratic formula to find intersection points
            int t1=tca + thc;
            if (t1<t0){
                return t1;//return nearest point
            }
           return t0;
        }

    }
}
void GLWidget::about()
{
    QString vnum;
    QString mess, notes;
    QString title="Images in Qt and Opengl ";

    vnum.setNum ( MYVERSION );
    mess="Qt OpenGl image demo Release Version: ";
    mess = mess+vnum;
    notes = "\n\n News: Every QImage is now on stack, there is no way for memory leak. -- Lucky";
    mess = mess+notes;
    QMessageBox::information( this, title, mess, QMessageBox::Ok );
}

void GLWidget::help()
{
    QString vnum;
    QString mess, notes;
    QString title="qtglimages";
    vnum.setNum ( MYVERSION);
    mess="Simple Image Handling in Qt/Opengl by Brian Wyvill Release Version: ";
    mess = mess+vnum;
    notes = "\n\n Save and Load images for display.  Also Make an image such as output from a ray tracer. ";
    mess = mess+notes;
    QMessageBox::information( this, title, mess, QMessageBox::Ok );
}

