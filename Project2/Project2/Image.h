const int MAX_WIDTH = 640;
const int MAX_HEIGHT = 480;
const int MAX_COLOR = 255;
enum COLOR { RED, GREEN, BLUE };
using namespace std;
class ImageMaker
{
public:
	ImageMaker();					//constructor
	ImageMaker(string filename);	//another constructor

	void LoadImage(string filename);
	//pre:  filename is a valid ppm file
	//post: copy the values from file to the matrix

	void SaveImage(string filename);
	//pre:  Matrix is a intialized with validf inputs
	//post: copy values from matrix to new file

	// Size functions
	int GetWidth();
	//post: return the width

	int GetHeight();
	//post: return the height

	void SetWidth(int wid);
	//pre:  width is within bounds 0  to MAX WIDTH
	//post: set the value of width to the variable

	void SetHeight(int hei);
	//pre:  height is within bounds 0 to MAX HEIGHT
	//post: set the value of height to the variable

	// Color functions
	int GetRed();
	//post: return red

	int GetGreen();
	//post: return green

	int GetBlue();
	//post: return blue

	void SetRed(int newR);
	//pre:  the value of newR is within bounds 0 to 255
	//post: set the red to the variable

	void SetGreen(int newG);
	//pre:  the value of newG is within bounds 0 to 255 
	//post: set the new color to the variable

	void SetBlue(int newB);
	//pre:  the value of newB is within bounds 0 to 255 
	//post: set the new color to the variable

	// Drawing methods
	void DrawPixel(int x, int y); // Uses red, green, blue for the color
	//pre:  values of x and y are within bounds 0 to width and height
	//post: a pixel is colored and displayed

	void DrawRectangle(int x1, int y1, int x2, int y2);
	//pre:  values of x's and y's are within bounds 0 to width and height
	//post: a rectangle outline is displayed with specific colors

	void DrawLine(int x1, int y1, int x2, int y2);
	//pre:  values of x's and y's are within bounds 0 to width and height
	//post: a line is colored and displayed

private:
	int width;
	int height;
	int red; // Used by draw methods
	int green; // Used by draw methods
	int blue; // Used by draw methods
	short image[MAX_WIDTH][MAX_HEIGHT][3];
};