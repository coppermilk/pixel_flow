//
// Created by zvgdb on 26.10.22.
//

#ifndef PIXEL_FLOW_SRC_CONTROLLERBOARD_H
#define PIXEL_FLOW_SRC_CONTROLLERBOARD_H

#include "Board.h"

class ControllerBoard
{
public:
	enum class Mode
	{
		DEBUG, ACTIVITY
	};

	ControllerBoard(Board * pBoard, ControllerBoard::Mode mode);
	static void debug_shuffle(Board * pBoard);
	static void set_activity();
	Board * pBoard;
};


#endif //PIXEL_FLOW_SRC_CONTROLLERBOARD_H
