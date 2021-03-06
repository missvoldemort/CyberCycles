#ifndef STATES_H
#define STATES_H
#include "game.h"
#include <osg/Group>
#include <osgViewer/Viewer>
#include <osg/Camera>
#include <osgGA/GUIEventHandler>

using namespace osg;

class StateManager
{
	public:
		enum state
		{
			MENU,
			GAME,
			EXIT
		};
		
		bool transFromMenuToGame;
		
		state currentState;		
		StateManager();
		
		void enterMenu(ref_ptr<Group> root, ref_ptr<osgViewer::Viewer> viewer);
		void exitMenu();
		
		void enterGame(ref_ptr<osg::Group> root, ref_ptr<osgViewer::Viewer> viewer);
		void enterGame();
		void exitGame();
		
		//public game items
		ref_ptr<Camera> gameCam; //so keyboardhandler can use without getter methods
		/* Have to use the one camera for all states for now
		 * otherwise segmentation fault
		 * most likely to do with threading that is handled on the osg side
		 */
		ref_ptr<Camera> cam;
	
	private:
		
		//main menu items
		ref_ptr<Node> mainMenuNode;
        ref_ptr<Projection> menuProjectionMatrix;
		ref_ptr<Camera> mainMenuCam;
		//these are the root and view the main menu was attached to
		ref_ptr<Group> menuRoot;
		ref_ptr<osgViewer::Viewer> menuViewer;
		
		//game items
		ref_ptr<Group> gameNode;
		//these are the root and view the main menu was attached to
		ref_ptr<Group> gameRoot;
		ref_ptr<osgViewer::Viewer> gameViewer;
		
		void removeAllEventHandlers();
};
#endif
