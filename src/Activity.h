#ifndef PIXEL_FLOW_SRC_ACTIVITY_H
#define PIXEL_FLOW_SRC_ACTIVITY_H

#include <string>
#include <boost/date_time/gregorian/greg_date.hpp>

/**
* @brief A class that represents an activity.
*/
class Activity
{
private:

	boost::gregorian::date date;
	/**
	* @brief A variable that stores the type of the activity.
	*/
	std::string type;

	/**
	* @brief A variable that stores the score of the activity.
	*/
	unsigned int score;
public:

	/**
	* @brief A copy constructor.
	* @param activity Value to copy.
	*/
	Activity(Activity& activity);


	/**
	* @brief A constructor that takes a string (activity type) as a parameter.
	*/
	explicit Activity(std::string type);


	/**
	* @brief An overloaded operator that increments the score of the activity.
	*/
	Activity& operator++();


	/**
	* @brief Setting the score of the activity.
	* @param score Value to setting.
	*/
	void set_score(unsigned int score);


	/**
	* @brief A C++17 feature that tells the compiler to warn the user if the return value of the function is not used.
	* @return Score value.
	*/
	[[nodiscard]] unsigned int get_score() const;


	/**
	* @brief A function that returns the type of the activity.
	* @return String (type of the activity).
	*/
	std::string get_type();
};


#endif //PIXEL_FLOW_SRC_ACTIVITY_H
