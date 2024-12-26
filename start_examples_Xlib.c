#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	Display *display;
	Window window;
	XEvent event;
	int	screen;

	display = XOpenDisplay(NULL);
	if (!display)
		exit(1);
	printf("display: %d\n", display);

	screen = DefaultScreen(display);
	window = XCreateSimpleWindow(display, RootWindow(display, screen),
								10, 10, 500, 300, 1,
								BlackPixel(display, screen),
								WhitePixel(display, screen));
	XSelectInput(display, window, ExposureMask | KeyPressMask);
	XMapWindow(display, window);

	while (1)
	{
		XNextEvent(display, &event);
		if (event.type == Expose)
		{
			// рисуем прямоуголиник
			XFillRectangle(display, window, DefaultGC(display, screen), 300, 100, 100, 100);
			// Рисуем линию
			XDrawLine(display, window, DefaultGC(display, screen), 120, 100, 220, 100);
			XDrawLine(display, window, DefaultGC(display, screen), 120, 100, 220, 110);
		}
		if (event.type == KeyPress)
			break ;
	}
	XCloseDisplay(display);
	return (0);
}// cc *.c -o start_examples.o -lX11 