//-------------------------------------------------------------------------------------------
//  This is a demo. program for open gl vertex arrays
//-------------------------------------------------------------------------------------------
#include <QtGui>
#include <QtOpenGL>
#include "window.h"
//#include <glm.h>
#define BIT0 0x00000001   // alpha
#define BIT1 0x00000002   // no buttons
#define BIT2 0x00000004   // set don't use native dialog

//------------------------------------------------------------------------------------
// Creates and initializes the main window for application
//------------------------------------------------------------------------------------
Window::Window(QWidget *parent):QDialog(parent)
{
    //We create an instance of GLWidget component we built in glwidget.h
	m_glWidget = new GLWidget;
	
	//Setup application interface. Creates all the required components and sliders.
	setupUi(this);
    //We need to attach our m_glWidget to glWidgetArea
    //All our drawings will be on glWidgetArea
    glWidgetArea->setWidget(m_glWidget);


}
void Window::zoomplus(){
    m_glWidget->zoomplus();
}
void Window::zoomminus(){
    m_glWidget->zoomminus();
}
void Window::xplus(){
    m_glWidget->xplus();
}
void Window::xminus(){
    m_glWidget->xminus();
}
void Window::yplus(){
    m_glWidget->yplus();
}
void Window::yminus(){
    m_glWidget->yminus();
}
void Window::lxplus(){
    m_glWidget->lxplus();
}
void Window::lxminus(){
    m_glWidget->lxminus();
}
void Window::lyplus(){
    m_glWidget->lyplus();
}
void Window::lyminus(){
    m_glWidget->lyminus();
}
void Window::lzplus(){
    m_glWidget->lzplus();
}
void Window::lzminus(){
    m_glWidget->lzminus();
}
void Window::toggleS1(){
    m_glWidget->toggleS1();
}
void Window::toggleS2(){
    m_glWidget->toggleS2();
}
void Window::setL1R(int a){
    m_glWidget->setL1R(a);
}
void Window::setL2R(int a){
    m_glWidget->setL2R(a);
}
void Window::setL1G(int a){
    m_glWidget->setL1G(a);
}
void Window::setL2G(int a){
    m_glWidget->setL2G(a);
}
void Window::setL1B(int a){
    m_glWidget->setL1B(a);
}
void Window::setL2B(int a){
    m_glWidget->setL2B(a);
}
void Window::setSCR(int a){
    m_glWidget->setSCR(a);
}
void Window::setSCG(int a){
    m_glWidget->setSCG(a);
}
void Window::setSCB(int a){
    m_glWidget->setSCB(a);
}

void Window::openImage()
{
    QString fileBuf;

    qDebug() << " opening image\n";
    fileBuf = QFileDialog::getOpenFileName(this,  "Open Image", "~/", "Image Files (*.png *.jpg)" );
    if (fileBuf=="") return;   // cancelled
   // QMessageBox::information( this, "Qtglskel: Opened image file ", fileBuf, QMessageBox::Ok );

    qDebug()<< "calling open in glwidget "<< fileBuf  NL;
    m_glWidget->openImage(fileBuf);
}

void Window::saveImage()
{
    QString fileBuf;

    qDebug() << " saving image\n";
    fileBuf = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "/home/untitled.png",
                               tr("Images (*.png *.xpm *.jpg)"));
     if (fileBuf=="") return;   // cancelled
   // QMessageBox::information( this, "Qtglskel: Opened image file ", fileBuf, QMessageBox::Ok );
    qDebug()<< "calling save in glwidget "<< fileBuf  NL;
    m_glWidget->saveImage(fileBuf);
}

void Window::makeImage()
{
    m_glWidget->makeImage();
}
void Window::aboutBut()
{
    m_glWidget->about();
}

void Window::helpBut()
{
    m_glWidget->help();
}

