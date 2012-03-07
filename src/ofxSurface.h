//
//  ofxSurface.h
//  ofxSurface
//
//  Created by Patricio González Vivo on 3/5/12.
//  Copyright (c) 2012 PatricioGonzalezVivo.com. All rights reserved.
//

#ifndef OFXSURFACE
#define OFXSURFACE

#include "ofMain.h"
#include "ofxXmlSettings.h"

class ofxSurface {
public:
  
    ofxSurface();
    
    // The nId number it´s the name of the instance on the .xml file. This
    // allows saving multiples surface parameters in one single config file
    //
    void    loadSettings( string _configFile = "config.xml", int _nId = -1);
    void    saveSettings( string _configFile = "config.xml", int _nId = -1);
    
    // Load and Draw ( super simple )
    //
    void    draw( ofTexture &texture );
    
private:
    void    doMask();                       // Update the mask
    void    doSurfaceToScreenMatrix();      // Update the SurfaceToScreen transformation matrix
    void    doScreenToSurfaceMatrix();      // Update the ScreenToSurface transformation matrix
    void    doGaussianElimination(float *input, int n); // This is used making the matrix
    
    // Mouse & Key Events from the testApp
    //
	void    _mouseMoved(ofMouseEventArgs &e);
    void    _mousePressed(ofMouseEventArgs &e);
    void    _mouseDragged(ofMouseEventArgs &e);
    void    _mouseReleased(ofMouseEventArgs &e);
    void    _keyPressed(ofKeyEventArgs &e);
    void    _keyReleased(ofKeyEventArgs &e);
    
    // Mask variables
    //
    ofFbo       maskFbo;
    ofShader    maskShader;
    vector<ofPoint> maskCorners;
	int         selectedMaskCorner;
    
    // Texture varialbes
    //
    ofPolyline  textureCorners;
    int         selectedTextureCorner;
    int         textureWidth, textureHeight;
    
    ofPoint     src[4];
    ofMatrix4x4 surfaceToScreenMatrix;
    ofMatrix4x4 screenToSurfaceMatrix;
    GLfloat     glMatrix[16];
        
    // General Variables
    //
    string      configFile;
    ofVec2f     mouseLast;
    int         width, height, nId; 
    bool        bEditMask, bEditMode;
};
#endif
