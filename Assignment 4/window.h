//-------------------------------------------------------------------------------------------
//  University of Victoria Computer Science Department 
//	FrameWork for OpenGL application under QT
//  Course title: Computer Graphics CSC305
//-------------------------------------------------------------------------------------------
#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QColorDialog>
#include "ui_MainWindow.h"
#include "glwidget.h"

class GLWidget;

//Create a window and load the components from generated code ui_MainWindow.h
class Window : public QDialog, public Ui::frmMain
{
	Q_OBJECT;

public:
	//Constructor 
	Window(QWidget *parent = 0);
	
private:
	//Member variable to hold the GLWidget instance
    //We need a reference to this
    GLWidget *m_glWidget;

    private slots:
        void openImage();
        void saveImage();        
        void makeImage();
        void aboutBut();
        void helpBut();
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
        void toggleS1();
        void toggleS2();
        void setSCR(int a);
        void setSCG(int a);
        void setSCB(int a);



//protected:
   //    void  resizeEvent(QResizeEvent * );
   //      void wheelEvent(QWheelEvent *event);

};


#endif
