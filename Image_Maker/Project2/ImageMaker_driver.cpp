//
//  ImageMaker_driver.cppImageMaker_driver
//  CS.3240
//
//  Created by Joel munoz on 4/6/18.
//  Copyright © 2018 Joel Muñoz. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Image_Maker.hpp"


using namespace std;


int main(){
    
    ifstream inFile;
    ofstream outFile;
    string inFileName;
    string outFileName;
    string outPutLabel;
    string command;
    int uno, dos,tres,cuarto,cinco,seis;
    
    
    ImageMaker imageObj;
    
    inFile.open("inoutDriverData.txt");
    outFile.open("test.ppm");
    

    try {
        // if fil doesnt open, an exceptions will be thrown
        if (!inFile) {
                // throws an exception to be caught
                throw "inFile did not open!";
        }
        else{
            inFile >> command;
            while (command != "quit" || "Quit") {
                if (command == "DrawLine") {
                    inFile >> uno;
                    inFile >> dos;
                    inFile >> tres;
                    inFile >> cuarto;
            
                    imageObj.DrawLine(uno, dos, tres, cuarto);
                    imageObj.SaveImage("text.ppm");
                }
                else if (command == "DrawRectangle"){
                    inFile >> uno;
                    inFile >> dos;
                    inFile >> tres;
                    inFile >> cuarto;
                    imageObj.DrawRectangle(uno, dos, tres, cuarto);
                    imageObj.SaveImage("text.ppm");
                }
                else if (command == "DrawTriangle"){
                    inFile >> uno;
                    inFile >> dos;
                    inFile >> tres;
                    inFile >> cuarto;
                    inFile >> cinco;
                    inFile >> seis;
                    
                    imageObj.DrawTriangle(uno, dos, tres, cuarto, cinco, seis);
                    imageObj.SaveImage("text.ppm");
                }
                else if(command == "DrawPixel"){
                    inFile >> uno;
                    inFile >> dos;
                    
                    imageObj.DrawPixel(uno, dos);
                    imageObj.SaveImage("text.ppm");
                }
                else if (command == "SetColor"){
                    
                }
                
                else if (command == "PrintRGB"){
                    
                }
                else if (command == "PrintSize"){
                    
                }
                else if (command == "Load" ){
                    inFile >> inFileName;
                    
                    if (!inFile) {
                        throw "File name not correct" << endl;
                    }
                    else{
                        imageObj.LoadImage(inFileName);
                    }
                }
                else if (command == "Save"){
                    imageObj.SaveImage("text.ppm")
                }
            }
        }
        // catches exceptions
    } catch (string exceptionstring) {
        cout << exceptionstring << endl;
    }
    
    inFile.close();
    outFile.close();

  return 0;

    
}
