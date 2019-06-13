// Gl_template.c
//Wy��czanie b��d�w przed "fopen"
#define  _CRT_SECURE_NO_WARNINGS

// �adowanie bibliotek:
#ifdef _MSC_VER                         // Check if MS Visual C compiler
#  pragma comment(lib, "opengl32.lib")  // Compiler-specific directive to avoid manually configuration
#  pragma comment(lib, "glu32.lib")     // Link libraries
#endif

// Ustalanie trybu tekstowego:
#ifdef _MSC_VER        // Check if MS Visual C compiler
#   ifndef _MBCS
#      define _MBCS    // Uses Multi-byte character set
#   endif
#   ifdef _UNICODE     // Not using Unicode character set
#      undef _UNICODE 
#   endif
#   ifdef UNICODE
#      undef UNICODE 
#   endif
#endif

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <gl\glu.h>             // GLU library
#include < Sysinfoapi.h >        
#include <math.h>				// Define for sqrt
#include <stdio.h>
#include "../resource.h" // About box resource identifiers.
#include "Solid.h"
#include "Wheel.h"
#include "Camera.h"
#include "Rover.h"
#include "Object.h"
#include "Game.h"
#include "../AntTweakBar/AntTweakBar.h"
#include "CheckPoint.h"


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define glRGB(x, y, z)	glColor3ub((GLubyte)x, (GLubyte)y, (GLubyte)z)
#define BITMAP_ID 0x4D42		// identyfikator formatu BMP

// Color Palette handle
HPALETTE hPalette = NULL;

// Application name and instance storeage
static LPCTSTR		lpszAppName = "Mars Rover XD";
static HINSTANCE	hInstance;

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat zRot = 0.0f;

static GLsizei lastHeight;
static GLsizei lastWidth;

unsigned int LoadTexture(const char* file, GLenum textureSlot)
{
	GLuint texHandle;
	// Copy file to OpenGL
	glGenTextures(textureSlot, &texHandle);
	glBindTexture(GL_TEXTURE_2D, texHandle);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	const auto data = stbi_load(file, &width, &height, &nrChannels, 0);
	if (data)
	{
		//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		gluBuild2DMipmaps(GL_TEXTURE_2D, nrChannels, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		//error
	}
	stbi_image_free(data);
	return texHandle;
}
// Opis tekstury
BITMAPINFOHEADER	bitmapInfoHeader;	// nag��wek obrazu
unsigned char*		bitmapData;			// dane tekstury
unsigned int		tekstury[3];			// obiekt tekstury

// Declaration for Window procedure
LRESULT CALLBACK WndProc(HWND    hWnd, UINT    message, WPARAM  wParam, LPARAM  lParam);

// Dialog procedure for about box
BOOL APIENTRY AboutDlgProc(HWND hDlg, UINT message, UINT wParam, LONG lParam);

// Set Pixel Format function - forward declaration
void SetDCPixelFormat(HDC hDC);


// Change viewing volume and viewport.  Called when window is resized
void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat nRange = 6000.0f;
	GLfloat fAspect;
	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	lastWidth = w;
	lastHeight = h;

	fAspect = (GLfloat)w / (GLfloat)h;
	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	/*
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange * h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange * w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);
	*/
	// Establish perspective: 
	
	gluPerspective(90.0f,fAspect,10.0, nRange);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// This function does any needed initialization on the rendering
// context.  Here it sets up and initializes the lighting for
// the scene.
void SetupRC()
{
	// Light values and coordinates
	GLfloat  ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 2.0f };
	GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat	 lightPos[] = { 50.0f, 50.0f, 50.0f, 1.0f };
	GLfloat  specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glEnable(GL_DEPTH_TEST);	// Hidden surface removal
	glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
	//glEnable(GL_CULL_FACE);		// Do not calculate inside of jet

	// Enable lighting
	glEnable(GL_LIGHTING);

	// Setup and enable light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);

	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);

	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// All materials hereafter have full specular reflectivity
	// with a high shine
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 64);

	// White background
	glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
	// Black brush
	glColor3f(0.0, 0.0, 0.0);
}

GLfloat pos[3] = { 2000,0,0 };
auto rover = new Rover{ pos };
auto camera = new Camera{pos};
GLfloat rot[] = { 90,1,0,0 };
GLfloat pos_terrain[3] = { 0,0,-5};
GLfloat pos1[3] = {0,800,10};
GLfloat pos2[3] = { 200,0,10 };
GLfloat color1[3] = { 1,1,1 };
GLfloat color2[3] = { 0.8,0.59,0.07 };
GLfloat color3[3] = { 0.7,0.49,0.05 };
auto terrain = new Object{"planenew.obj", color1, pos_terrain, rot, 100 }; //mars.obj
auto cubeStone = new Object{"cube-stone.obj", color2, pos1, rot, 100 };
auto sphereStone = new Object{"sphere-stone.obj", color3, pos2, rot, 100 };


int collision2 = 0;

auto game = new Game;
GLfloat posC1[3] = { 2000,0,0 };
auto c1 = new CheckPoint{ posC1 };


void gameStart() {
	game->add(posC1);
	game->start();
}

int lastTime = GetTickCount();
// Called to draw scene
void RenderScene(void)
{	
	bool g = false;
	if (!g) {
		gameStart();
		g = true;
	}
	else {
		game->draw();
	}

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Save the matrix state and do the rotations
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glRotatef(zRot, 0.0f, 0.0f, 1.0f);

	/////////////////////////////////////////////////////////////////
	// MIEJSCE NA KOD OPENGL DO TWORZENIA WLASNYCH SCEN:		   //
	/////////////////////////////////////////////////////////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tekstury[0]);
	terrain->draw();
	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tekstury[1]);
	cubeStone->draw();
	sphereStone->draw();
	glDisable(GL_TEXTURE_2D);

	glPushMatrix();

	rover->update();
	//glTranslatef(0, (velL + velR) / 2, 0); // dodanie wektora do wps�rz�dnych
	//glRotatef(rotAngle * 180 / GL_PI, 0.0f, 0.0f, 1.0f);
	//glTranslatef(pos[0], pos[1], pos[2]);
	//glTranslatef(-pos[0], -pos[1], -pos[2]);
	rover->draw();
	glPopMatrix();

	//c1->draw();


	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	TwInit(TW_OPENGL, NULL);
	TwBar* bar;
	bar = TwNewBar("Parametry");

	float posx = rover->getPosx();
	float posy = rover->getPosy();
	   	 
	float distance2 = sqrt((posx - pos2[0]) * (posx - pos2[0]) + (posy - pos2[1]) * (posy - pos2[1]));
	if (distance2 <= 110) {
		collision2 = 1;
		rover->collision();
	}
	else {
		collision2 = 0;
	}
	
//	game->check(rover->pos);

	TwWindowSize(800, 600);
	TwAddButton(bar, "Martian rover", NULL, NULL, "");
	TwAddVarRO(bar, "Velocity", TW_TYPE_FLOAT, &rover->velocity, "");
	TwAddVarRO(bar, "Velocity L", TW_TYPE_INT32, &rover->velL, "");
	TwAddVarRO(bar, "Velocity R", TW_TYPE_INT32, &rover->velR, "");
	TwAddSeparator(bar, "Position", "pos");
	TwAddVarRO(bar, "X", TW_TYPE_FLOAT, &rover->pos[0], "");
	TwAddVarRO(bar, "Y", TW_TYPE_FLOAT, &rover->pos[1], "");
	TwAddSeparator(bar, NULL, "");
	TwAddVarRO(bar, "kolizja z obiektem 2", TW_TYPE_INT32, &collision2, "");

	TwDraw();

	camera->setPosition(rover->pos, -rover->alfa);
	camera->update();
	// Flush drawing commands
	glFlush();
	while (GetTickCount() < lastTime + 16) {
		Sleep(2);
	}
	lastTime = GetTickCount();
}

// Select the pixel format for a given device context
void SetDCPixelFormat(HDC hDC)
{
	int nPixelFormat;

	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),  // Size of this structure
		1,                                                              // Version of this structure    
		PFD_DRAW_TO_WINDOW |                    // Draw to Window (not to bitmap)
		PFD_SUPPORT_OPENGL |					// Support OpenGL calls in window
		PFD_DOUBLEBUFFER,                       // Double buffered
		PFD_TYPE_RGBA,                          // RGBA Color mode
		24,                                     // Want 24bit color 
		0,0,0,0,0,0,                            // Not used to select mode
		0,0,                                    // Not used to select mode
		0,0,0,0,0,                              // Not used to select mode
		32,                                     // Size of depth buffer
		0,                                      // Not used to select mode
		0,                                      // Not used to select mode
		PFD_MAIN_PLANE,                         // Draw in main plane
		0,                                      // Not used to select mode
		0,0,0 };                                // Not used to select mode

	// Choose a pixel format that best matches that described in pfd
	nPixelFormat = ChoosePixelFormat(hDC, &pfd);

	// Set the pixel format for the device context
	SetPixelFormat(hDC, nPixelFormat, &pfd);
}

// If necessary, creates a 3-3-2 palette for the device context listed.
HPALETTE GetOpenGLPalette(HDC hDC)
{
	HPALETTE hRetPal = NULL;	// Handle to palette to be created
	PIXELFORMATDESCRIPTOR pfd;	// Pixel Format Descriptor
	LOGPALETTE *pPal;			// Pointer to memory for logical palette
	int nPixelFormat;			// Pixel format index
	int nColors;				// Number of entries in palette
	int i;						// Counting variable
	BYTE RedRange, GreenRange, BlueRange;
	// Range for each color entry (7,7,and 3)


// Get the pixel format index and retrieve the pixel format description
	nPixelFormat = GetPixelFormat(hDC);
	DescribePixelFormat(hDC, nPixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

	// Does this pixel format require a palette?  If not, do not create a
	// palette and just return NULL
	if (!(pfd.dwFlags & PFD_NEED_PALETTE))
		return NULL;

	// Number of entries in palette.  8 bits yeilds 256 entries
	nColors = 1 << pfd.cColorBits;

	// Allocate space for a logical palette structure plus all the palette entries
	pPal = (LOGPALETTE*)malloc(sizeof(LOGPALETTE) + nColors * sizeof(PALETTEENTRY));

	// Fill in palette header 
	pPal->palVersion = 0x300;		// Windows 3.0
	pPal->palNumEntries = nColors; // table size

	// Build mask of all 1's.  This creates a number represented by having
	// the low order x bits set, where x = pfd.cRedBits, pfd.cGreenBits, and
	// pfd.cBlueBits.  
	RedRange = (1 << pfd.cRedBits) - 1;
	GreenRange = (1 << pfd.cGreenBits) - 1;
	BlueRange = (1 << pfd.cBlueBits) - 1;

	// Loop through all the palette entries
	for (i = 0; i < nColors; i++)
	{
		// Fill in the 8-bit equivalents for each component
		pPal->palPalEntry[i].peRed = (i >> pfd.cRedShift) & RedRange;
		pPal->palPalEntry[i].peRed = (unsigned char)(
			(double)pPal->palPalEntry[i].peRed * 255.0 / RedRange);

		pPal->palPalEntry[i].peGreen = (i >> pfd.cGreenShift) & GreenRange;
		pPal->palPalEntry[i].peGreen = (unsigned char)(
			(double)pPal->palPalEntry[i].peGreen * 255.0 / GreenRange);

		pPal->palPalEntry[i].peBlue = (i >> pfd.cBlueShift) & BlueRange;
		pPal->palPalEntry[i].peBlue = (unsigned char)(
			(double)pPal->palPalEntry[i].peBlue * 255.0 / BlueRange);

		pPal->palPalEntry[i].peFlags = (unsigned char)NULL;
	}


	// Create the palette
	hRetPal = CreatePalette(pPal);

	// Go ahead and select and realize the palette for this device context
	SelectPalette(hDC, hRetPal, FALSE);
	RealizePalette(hDC);

	// Free the memory used for the logical palette structure
	free(pPal);

	// Return the handle to the new palette
	return hRetPal;
}

// Entry point of all Windows programs
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG                     msg;            // Windows message structure
	WNDCLASS        wc;                     // Windows class structure
	HWND            hWnd;           // Storeage for window handle

	hInstance = hInst;

	// Register Window style
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	// No need for background brush for OpenGL window
	wc.hbrBackground = NULL;

	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
	wc.lpszClassName = lpszAppName;

	// Register the window class
	if (RegisterClass(&wc) == 0)
		return FALSE;


	// Create the main application window
	hWnd = CreateWindow(
		lpszAppName,
		lpszAppName,

		// OpenGL requires WS_CLIPCHILDREN and WS_CLIPSIBLINGS
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,

		// Window position and size
		448, 156,
		1024, 768,
		NULL,
		NULL,
		hInstance,
		NULL);

	// If window was not created, quit
	if (hWnd == NULL)
		return FALSE;


	// Display the window
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	// Process application messages until the application closes
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

// Window procedure, handles all messages for this program
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HGLRC hRC;               // Permenant Rendering context
	static HDC hDC;                 // Private GDI Device context

	switch (message)
	{
		// Window creation, setup for OpenGL
	case WM_CREATE:
		// Store the device context
		hDC = GetDC(hWnd);

		// Select the pixel format
		SetDCPixelFormat(hDC);

		// Create palette if needed
		hPalette = GetOpenGLPalette(hDC);

		// Create the rendering context and make it current
		hRC = wglCreateContext(hDC);
		wglMakeCurrent(hDC, hRC);
		SetupRC();
		//glGenTextures(2, &texture[0]);                  // tworzy obiekt tekstury			

		tekstury[0] = LoadTexture("textures/mars.png", 1);
		tekstury[1] = LoadTexture("textures/mars2.png", 1);
		tekstury[2] = LoadTexture("textures/metal2.png", 1);

		//// �aduje pierwszy obraz tekstury:
		//bitmapData = LoadBitmapFile((char*)"mars.bmp", &bitmapInfoHeader);

		//glBindTexture(GL_TEXTURE_2D, texture[0]);       // aktywuje obiekt tekstury

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		//// tworzy obraz tekstury
		//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader.biWidth,
		//	bitmapInfoHeader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

		//if (bitmapData)
		//	free(bitmapData);

		//// �aduje drugi obraz tekstury:
		//bitmapData = LoadBitmapFile((char*)"Bitmapy\\crate.bmp", &bitmapInfoHeader);
		//glBindTexture(GL_TEXTURE_2D, texture[1]);       // aktywuje obiekt tekstury

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		//// tworzy obraz tekstury
		//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader.biWidth,
		//	bitmapInfoHeader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

		//if (bitmapData)
		//	free(bitmapData);

		

		// ustalenie sposobu mieszania tekstury z t�em
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		break;

		// Window is being destroyed, cleanup
	case WM_DESTROY:
		// Deselect the current rendering context and delete it
		wglMakeCurrent(hDC, NULL);
		wglDeleteContext(hRC);

		// Delete the palette if it was created
		if (hPalette != NULL)
			DeleteObject(hPalette);

		// Tell the application to terminate after the window
		// is gone.
		PostQuitMessage(0);
		break;

		// Window is resized.
	case WM_SIZE:
		// Call our function which modifies the clipping
		// volume and viewport
		ChangeSize(LOWORD(lParam), HIWORD(lParam));
		break;


		// The painting function.  This message sent by Windows 
		// whenever the screen needs updating.
	case WM_PAINT:
	{
		// Call OpenGL drawing code
		RenderScene();

		SwapBuffers(hDC);

		// Validate the newly painted client area
		ValidateRect(hWnd, NULL);
		InvalidateRect(hWnd, NULL, FALSE);
	}
	break;

	// Windows is telling the application that it may modify
	// the system palette.  This message in essance asks the 
	// application for a new palette.
	case WM_QUERYNEWPALETTE:
		// If the palette was created.
		if (hPalette)
		{
			int nRet;

			// Selects the palette into the current device context
			SelectPalette(hDC, hPalette, FALSE);

			// Map entries from the currently selected palette to
			// the system palette.  The return value is the number 
			// of palette entries modified.
			nRet = RealizePalette(hDC);

			// Repaint, forces remap of palette in current window
			InvalidateRect(hWnd, NULL, FALSE);

			return nRet;
		}
		break;


		// This window may set the palette, even though it is not the 
		// currently active window.
	case WM_PALETTECHANGED:
		// Don't do anything if the palette does not exist, or if
		// this is the window that changed the palette.
		if ((hPalette != NULL) && ((HWND)wParam != hWnd))
		{
			// Select the palette into the device context
			SelectPalette(hDC, hPalette, FALSE);

			// Map entries to system palette
			RealizePalette(hDC);

			// Remap the current colors to the newly realized palette
			UpdateColors(hDC);
			return 0;
		}
		break;

		// Key press, check for arrow keys to do cube rotation.
	case WM_KEYDOWN:
	{
		camera->update(wParam);

		rover->update(wParam);

		xRot = (const int)xRot % 360;
		yRot = (const int)yRot % 360;
		zRot = (const int)zRot % 360;

		InvalidateRect(hWnd, NULL, FALSE);
	}
	break;

	// A menu command
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			// Exit the program
		case ID_FILE_EXIT:
			DestroyWindow(hWnd);
			break;

			//Display the about box
			case ID_HELP_ABOUT:
				//DialogBox (hInstance, MAKEINTRESOURCE(IDD_DIALOG_ABOUT), hWnd, AboutDlgProc);
				break;
			
		}
	}
	break;


	default:   // Passes it on if unproccessed
		return (DefWindowProc(hWnd, message, wParam, lParam));

	}

	return (0L);
}

// Dialog procedure.
BOOL APIENTRY AboutDlgProc(HWND hDlg, UINT message, UINT wParam, LONG lParam)
{

	switch (message)
	{
		// Initialize the dialog box
	case WM_INITDIALOG:
	{
		int i;
		GLenum glError;

		// glGetString demo
		
		SetDlgItemText(hDlg,IDC_OPENGL_VENDOR, (LPCSTR)glGetString(GL_VENDOR));
		SetDlgItemText(hDlg,IDC_OPENGL_RENDERER, (LPCSTR)glGetString(GL_RENDERER));
		SetDlgItemText(hDlg,IDC_OPENGL_VERSION, (LPCSTR)glGetString(GL_VERSION));
		SetDlgItemText(hDlg,IDC_OPENGL_EXTENSIONS, (LPCSTR)glGetString(GL_EXTENSIONS));

		// gluGetString demo
		SetDlgItemText(hDlg,IDC_GLU_VERSION, (LPCSTR)gluGetString(GLU_VERSION));
		SetDlgItemText(hDlg,IDC_GLU_EXTENSIONS, (LPCSTR)gluGetString(GLU_EXTENSIONS));
		

		// Display any recent error messages
		i = 0;
		do {
			glError = glGetError();
			SetDlgItemText(hDlg,IDC_ERROR1+i,(LPCSTR)gluErrorString(glError));
			i++;
		} while (i < 6 && glError != GL_NO_ERROR);


		return (TRUE);
	}
	break;

	// Process command messages
	case WM_COMMAND:
	{
		// Validate and Make the changes
		if (LOWORD(wParam) == IDOK)
			EndDialog(hDlg, TRUE);
	}
	break;

	// Closed from sysbox
	case WM_CLOSE:
		EndDialog(hDlg, TRUE);
		break;
	}

	return FALSE;
}