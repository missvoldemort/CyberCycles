#ifndef MAINMENU_H
#define MAINMENU_H

#include <osgViewer/Viewer>
#include <osg/LineWidth>
#include <osg/Geometry>
#include <osg/ShapeDrawable>
#include <osgDB/ReadFile> 
#include <osgText/Font>
#include <osgText/Text>
#include <osg/MatrixTransform>
#include <osg/Geode>
#include <osg/Projection>
#include <osg/ShapeDrawable>
#include <osg/Geometry>
#include <osgGA/TrackballManipulator>


using namespace osg;
class MainMenu
{
//	const int mapSelected = 0;
 //   const int playSelected = 1;
	public:	
		MainMenu();
		ref_ptr<Node> getMenuNode();
    private:
        int numMaps;
        unsigned int selection;
        
};

#endif
