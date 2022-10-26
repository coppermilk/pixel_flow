//
// Created by zvgdb on 26.10.22.
//

#include "ControllerBoard.h"

ControllerBoard::ControllerBoard(Board * pBoard, ControllerBoard::Mode mode)
{
	this->pBoard = pBoard;
	if(mode == Mode::DEBUG){
		debug_shuffle(pBoard);
	}
}

void ControllerBoard::debug_shuffle(Board* pBoard)
{
	for(int i = pBoard->size() - 1; i >= 0; i--){
		pBoard->push_back(Pixel(i));
	}
}
