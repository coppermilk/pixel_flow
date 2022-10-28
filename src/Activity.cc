#include "Activity.h"

#include <utility>

Activity::Activity(std::string type)
{
	this->type = std::move(type);
	score = 0;
}

Activity& Activity::operator++()
{
	++score;
	return *this;
}

Activity::Activity(Activity& activity)
{
	this->type = activity.type;
	this->score = activity.score;
}

void Activity::set_score(unsigned int score_val)
{
	this->score = score_val;
}

std::string Activity::get_type()
{
	return type;
}

unsigned int Activity::get_score() const
{
	return score;
}

