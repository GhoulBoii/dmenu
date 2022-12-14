#include <X11/Xresource.h>

void
readxresources(void)
{
	XrmInitialize();

	char* xrm;
	if ((xrm = XResourceManagerString(drw->dpy))) {
		char *type;
		XrmDatabase xdb = XrmGetStringDatabase(xrm);
		XrmValue xval;

		if (XrmGetResource(xdb, "dmenu.font", "*", &type, &xval))
			fonts[0] = strdup(xval.addr);
		else
			fonts[0] = strdup(fonts[0]);
		if (XrmGetResource(xdb, "dmenu.background", "*", &type, &xval))
			colors[SchemeNorm][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.foreground", "*", &type, &xval))
			colors[SchemeNorm][ColFg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.color1", "*", &type, &xval))
			colors[SchemeSel][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.foreground", "*", &type, &xval))
			colors[SchemeSel][ColFg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.color6", "*", &type, &xval))
			colors[SchemeOut][ColBg] = strdup(xval.addr);
		if (XrmGetResource(xdb, "dmenu.foreground", "*", &type, &xval))
			colors[SchemeOut][ColFg] = strdup(xval.addr);
		XrmDestroyDatabase(xdb);
	}
}
