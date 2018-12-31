#include <X11/Xlib.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {

    Display * display;
    XWindowAttributes attr;
    XButtonEvent start;
    XEvent ev;
    Window foc;
    int revert_to;

    // Exit if display doesn't instantiate
    if(!(display = XOpenDisplay(0x0))) {
        return 1;
    }

    XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("q")),
        Mod1Mask, DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("a")),
        Mod1Mask, DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("d")),
        Mod1Mask, DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("s")),
        Mod1Mask, DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("Return")),
        Mod1Mask, DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym("Backspace")),
        Mod1Mask, DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync);

    // Capture mouse 1 and 3 keys
    // Mouse 1 moves windows when Mod1 is held
    // Mouse 3 resizes windows when Mod1 is held
    XGrabButton(display, 1, Mod1Mask, DefaultRootWindow(display), True,
        ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);
    XGrabButton(display, 3, Mod1Mask, DefaultRootWindow(display), True,
        ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);

    start.subwindow = None;

    // Infinite loop
    for(;;) {

        XNextEvent(display, &ev);
	    XGetInputFocus(display, &foc, &revert_to);

    	if(ev.type == KeyPress && ev.xbutton.subwindow != None) {

            // Close window with mod+q
    	    if(ev.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("q"))) {
    	        XDestroyWindow(display, foc);
            }

            // Lower windows with mod+w
    	    else if (ev.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("a"))) {
                XLowerWindow(display, foc);
            }

            // Raise windows with mod+e
    	    else if (ev.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("s"))) {
                XRaiseWindow(display, foc);
            }
    	}

    	if(ev.type == KeyPress) {

            // Open simple terminal with mod+return
    	    if(ev.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("Return"))) {
                system("st &");
            }

            // Open dmenu with mod+d
    	    if(ev.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("d"))) {
                system("dmenu_run");
            }

            // Close aphelia with mod+backspace
    	    else if(ev.xkey.keycode == XKeysymToKeycode(display, XStringToKeysym("Backspace"))) {
                XCloseDisplay(display);
            }
    	}

    	if(ev.type == ButtonPress && ev.xbutton.subwindow != None) {

    	    XGetWindowAttributes(display, ev.xbutton.subwindow, &attr);
    	    XSetInputFocus(display, ev.xbutton.subwindow, RevertToParent, CurrentTime);
    	    start = ev.xbutton;
    	}

    	else if(ev.type == MotionNotify && start.subwindow != None) {

            int xdiff = ev.xbutton.x_root - start.x_root;
            int ydiff = ev.xbutton.y_root - start.y_root;

            XMoveResizeWindow(display, start.subwindow,
                attr.x + (start.button==1 ? xdiff : 0),
                attr.y + (start.button==1 ? ydiff : 0),

                MAX(100, attr.width + (start.button==3 ? xdiff : 0)),
                MAX(50, attr.height + (start.button==3 ? ydiff : 0)));
    	}

        else if(ev.type == ButtonRelease) {

            start.subwindow = None;
        }
    }
}
