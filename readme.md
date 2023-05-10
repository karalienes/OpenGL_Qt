Open Graphics Library (OpenGL), a powerful rendering Application Program Interface (API), and combine it with Qt. OpenGL is a cross-language, cross platform API for drawing 2D and 3D graphics on screen through the Graphics Processing Unit (GPU) within our computer's graphics chip. In this chapter, we will be learning OpenGL 2.x instead of 3.x, because the fixed-function pipeline is easier for beginners to grasp compared to the newer programmable pipeline. Qt supports both versions, so there should be no problem switching over to OpenGL 3.x and above once you have learned the basic concepts of OpenGL rendering.

The OpenGL module must be added to the project file (.pro) in order to access header files that are related to OpenGL, such as QtOpenGL, QOpenGLFunctions, and so on. We used the QOpenGLWindow class instead of QMainWindow for the main window because it's designed to easily create windows that perform OpenGL rendering, and it offers better performance compared to QOpenGLWidget due to the fact that it has no dependencies in its widget module. We must call setSurfaceType(QWindow::OpenGLSurface) to tell Qt we prefer to use OpenGL to render the images to screen, instead of QPainter. The QOpenGLWindowclass provides several virtual functions (initializeGL(), resizeGL(), paintGL(), and so on) for us to conveniently set up OpenGL and perform graphics rendering

Computer graphics technology has been evolving rapidly over the years, so rapidly that the software industry can hardly keep up with its pace. In 2008, Khronos Group, the company that maintains and develops OpenGL, announced the release of the OpenGL 3.0 specification, which created a huge uproar and controversy throughout the industry. That was mainly because OpenGL 3.0 was supposed to deprecate the entire fixed-function pipeline from the OpenGL API, and it was simply an impossible task for the big players to make the sudden switch overnight from a fixed-function pipeline to a programmable pipeline. This resulted in two different major versions of OpenGL being maintained concurrently by the Khronos Group, namely OpenGL 2.x and 3.x.

We will be learning OpenGL 2.x instead of 3.x, because the fixed-function pipeline is easier for beginners to grasp than the programmable pipeline. It's very straightforward and less confusing for learning the basics of computer graphics programming. Qt supports both versions, so there should be no problem switching over to OpenGL 3.x (and above) once you have learned the basic concepts of OpenGL rendering

Qt uses OpenGL internally whenever it sees fit. Moreover, the new Qt Quick 2 renderer is based on OpenGL and is now a core part of Qt's graphical offering. That makes OpenGL more compatible with Qt than any other graphics APIs, such as DirectX.

We must set the OpenGL version to 2.1 and the surface format to compatibility profile so
that we can access the fixed-function pipeline, which no longer exists in the newer version.
Alternatively, you can set the surface format to QSurfaceFormat::CoreProfile if you
want to use OpenGL 3.x and above.
We called glClearColor() and glClear(GL_COLOR_BUFFER_BIT) to remove the
previous render buffer (or in layman's terms, the previous frame) and fill the entire canvas
with the color we provided. We will repeat this step after an image has been rendered so that it
clears the entire screen before we proceed to the next frame. We called glBegin(GL_QUAD)
to tell OpenGL we are about to draw a quad on the screen. After that, we provided the positions
of all the vertices (or points) to OpenGL so that it will know how the quad should be positioned
on the screen by calling glVertex2f() four times, because a quad can only be constructed
by connecting four different points. Then, we called glEnd() to inform OpenGL that we are
done with the quad.
Always call glFlush() once you are done drawing images on screen so that OpenGL clears
away all the unwanted information from the memory to give space to the next drawing.
Lastly, we must call paintGL() in the paintEvent() function, or else nothing will be
drawn on the screen. Just like what we have learned in the previous chapters, all drawings
happen within the paintEvent() function, and it will only be called by Qt when it thinks it's
necessary to refresh the screen. To force Qt to update the screen, call update() manually.
