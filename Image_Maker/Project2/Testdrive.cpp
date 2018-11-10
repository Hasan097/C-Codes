#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include "Image.h"

using namespace std;

int main()
{
	ifstream inFile;       // file containing operations
	string inFileName;     // input file external name
	string command;        // operation to be executed
	ImageMaker OP;		   // Class Object

	int number;
	int item;
	UnsortedInt list;

	bool found;
	int numCommands;

	// Prompt for file names, read file names, and prepare files
	cout << "Enter name of input command file and press enter: " << endl;
	cin >> inFileName;
	inFile.open(inFileName.c_str());

	if (!inFile)
	{
		cout << "File not found." << endl;
		exit(2);
	}

	inFile >> command;

	numCommands = 0;
	while (command != "Quit")
	{
		cout << command;
		if (command == "PutItem")
		{
			
		}
		else if (command == "DeleteItem")
		{
			//inFile >> item;
			cin >> item;
			list.DeleteItem(item);
			outFile << item;
			outFile << " is deleted." << endl;
		}
		else if (command == "GetItem")
		{
			//inFile >> item;
			cin >> item;
			item = list.GetItem(item, found);
			if (found)
				outFile << item << " found in list." << endl;
			else
				outFile << item << " not in list." << endl;
		}
		else if (command == "GetLength")
			outFile << "Length is " << list.GetLength() << endl;
		else if (command == "IsFull")
			if (list.IsFull())
				outFile << "List is full." << endl;
			else outFile << "List is not full." << endl;
		else if (command == "MakeEmpty")
			list.MakeEmpty();
		else if (command == "PrintList")
			PrintList(outFile, list);
		else cout << " Command not recognized." << endl;
		numCommands++;
		cout << " Command number " << numCommands << " completed."
			<< endl;
		inFile >> command;
		//cin >> command;
	}

	cout << "Quit" << endl << "Testing completed." << endl;
	inFile.close();
	outFile.close();
	return 0;
}
}

ImageMaker::ImageMaker() {
	width = 0;
	height = 0;
	red = green = blue = 0;
}

ImageMaker::ImageMaker(string filename) {
	ifstream in;
	in.open(filename.c_str());

	string first;
	int w, h;
	in >> first;
	in >> w >> h;
	
	width = w;
	height = h;

	in.close();
}

void ImageMaker::LoadImage(string filename) {
	ifstream in;
	in.open(filename.c_str());

	if (!in)
		throw ("ERROR file not found");
	else {
		string first;
		int w, h, c;
		in >> first;
		in >> w >> h >> c;

		SetWidth(w);
		SetHeight(h);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				in >> image[j][i][RED];
				in >> image[j][i][GREEN];
				in >> image[j][i][BLUE];
			}
		}
	}
	in.close();
}

void ImageMaker::SaveImage(string filename) {
	ofstream out;

	out.open(filename.c_str());

	out << "P3" << endl << width << " " << height << endl;
	out << MAX_COLOR << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			out << image[j][i][RED] << " ";
			out << image[j][i][GREEN] << " ";
			out << image[j][i][BLUE] << " ";
		}
		out << endl;
	}
	out.close();
}

int ImageMaker::GetWidth() {
	return width;
}

int ImageMaker::GetHeight() {
	return height;
}

void ImageMaker::SetWidth(int wid) {
	if (wid < 0 || wid > MAX_WIDTH)
		cout << "incorrect width";
	else
		width = wid;
}

void ImageMaker::SetHeight(int hei) {
	if (hei < 0 || hei > MAX_HEIGHT)
		cout << "Incorrect height";
	else
		height = hei;
}

int ImageMaker::GetRed() {
	return red;
}

int ImageMaker::GetGreen() {
	return green;
}

int ImageMaker::GetBlue() {
	return blue;
}

void ImageMaker::SetRed(int newR) {
	if (newR < 0 || newR > MAX_COLOR)
		cout << "Incorrect color number";
	else
		red = newR;
}

void ImageMaker::SetGreen(int newG) {
	if (newG < 0 || newG > MAX_COLOR)
		cout << "Incorrect color number";
	else
		green = newG;
}

void ImageMaker::SetBlue(int newB) {
	if (newB < 0 || newB > MAX_COLOR)
		cout << "Incorrect color number";
	else
		blue = newB;
}

void ImageMaker::DrawPixel(int x, int y) {
	SetRed(250);
	SetGreen(0);
	SetBlue(0);

	if (x > 0 && x < width && y > 0 && y < height) {
		image[x][y][RED] = red;
		image[x][y][GREEN] = green;
		image[x][y][BLUE] = blue;
	}
	else
		cout << "values out of bounds";

	SaveImage("ImageSave.ppm");
}

void ImageMaker::DrawRectangle(int x1, int y1, int x2, int y2) {
	int xmax, xmin, ymax, ymin;

	if (x1 < 0 && x1 > width && x2 < 0 && x2 > width)
		cout << "x values out of bounds";
	if (y1 < 0 && y1 > height && y2 < 0 && y2 > height)
			cout << "y values out of bounds";

	if (x1 > x2) {
		xmax = x1;
		xmin = x2;
	}
	else
	{
		xmax = x2;
		xmin = x1;
	}

	if (y1 > y2) {
		ymax = y1;
		ymin = y2;
	}
	else
	{
		ymax = y2;
		ymin = y1;
	}

	SetRed(0);
	SetGreen(250);
	SetBlue(0);

	for (int k = ymin; k <= ymax; k++) 
		for (int n = xmin; n <= xmax; n++) {
			image[n][k][RED] = red;
			image[n][k][GREEN] = green;
			image[n][k][BLUE] = blue;
		}

	SaveImage("ImageSave.ppm");
}

void ImageMaker::DrawLine(int x1, int y1, int x2, int y2) {
	double y, m, b;
	int xmax, xmin, ymax, ymin;

	if (x1 < 0 && x1 > width && x2 < 0 && x2 > width)
		cout << "x values out of bounds";
	if (y1 < 0 && y1 > height && y2 < 0 && y2 > height)
		cout << "y values out of bounds";

	if (x1 > x2) {
		xmax = x1;
		xmin = x2;
	}
	else
	{
		xmax = x2;
		xmin = x1;
	}

	m = (1.0 * (y2 - y1)) / (1.0 * (x2 - x1));
	b = 1.0 * y1 - (m * x1);

	SetRed(0);
	SetGreen(0);
	SetBlue(250);

	for (int i = xmin; i <= xmax; i++) {
		y = m*i + b;
		int a = static_cast<int>(y);
		image[i][a][RED] = red;
		image[i][a][GREEN] = green;
		image[i][a][BLUE] = blue;
	}

	SaveImage("ImageSave.ppm");
}
