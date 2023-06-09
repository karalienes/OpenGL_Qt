#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    setSurfaceType(QWindow::OpenGLSurface);
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(2,1); //OpenGL 2.1
    setFormat(format);

    context = new QOpenGLContext;
    //Sets the format the OpenGL context should be compatible with.
    //You need to call create() before it takes effect.
    //When the format is not explicitly set via this function,
    //the format returned by QSurfaceFormat::defaultFormat() will be used.
    //This means that when having multiple contexts,
    //individual calls to this function can be replaced by one single call to
    //QSurfaceFormat::setDefaultFormat() before creating the first context.
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);

    openGLFunctions = context->functions();

}

MainWindow::~MainWindow()
{

}

void MainWindow::initializeGL()
{

}

void MainWindow::resizeGL(int w, int h)
{

}

void MainWindow::paintGL()
{
    // Initialize clear color (cornflower blue)
    glClearColor(0.39f, 0.58f, 0.93f, 1.f);

    // Clear color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Render quad
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(-0.5f, 0.5f);
    glEnd();

    glFlush();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintGL();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{

}

