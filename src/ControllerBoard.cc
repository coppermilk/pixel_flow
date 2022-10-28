//
// Created by zvgdb on 26.10.22.
//

#include "ControllerBoard.h"

ControllerBoard::ControllerBoard(Board* pBoard, ControllerBoard::Mode mode)
{
	this->pBoard = pBoard;
	if (mode == Mode::DEBUG)
	{
		debug_shuffle(pBoard);
	}
}

void ControllerBoard::debug_shuffle(Board* pBoard)
{
	for (int i = pBoard->size(); i > 0; i--)
	{
		pBoard->set_pixel(pBoard->size() - i, i - 1);
	}
}

ControllerBoard::ControllerBoard(Board* pBoard)
{
	this->pBoard = pBoard;
}

void ControllerBoard::set_mode_activity(const Data& activities, const std::string& type, bool is_need_days_of_week_offset) const
{
	using namespace boost::gregorian;
	using namespace boost::posix_time;

	date today = second_clock::local_time().date();
	date last_day_than_can_be_show_in_board = today - days(pBoard->size());
	long day_of_week_offset = today.day_of_week();

	pBoard->reset_all_pixel();

	for (auto& type_activity : activities.data)
	{
		if (type_activity.first == type)
		{
			for (auto& days_and_score : type_activity.second)
			{
				if ((last_day_than_can_be_show_in_board <= days_and_score.first)  && (days_and_score.first <= today))
				{
					date_period dp = { days_and_score.first, today };
					long day_offset_from_today = dp.length().days();
					if(is_need_days_of_week_offset){
						pBoard->set_pixel(pBoard->size() - day_offset_from_today - (7 - day_of_week_offset), days_and_score.second);
					}else{
						pBoard->set_pixel(pBoard->size() - day_offset_from_today - 1, days_and_score.second);
					}
				}
			}
			break;
		}
	}
}




//// Setting the pixels on the board based on the data in the activities_data.
//void ControllerBoard::set_mode_activity(const std::vector<std::tuple<std::string,
//																	 std::map<boost::gregorian::date,
//																			  int>>>& activities_data,
//		const std::string& type,
//		bool days_of_week_offset) const
//{
//	using namespace boost::gregorian;
//	using namespace boost::posix_time;
//
//	date today = second_clock::universal_time().date();
//	date last_day_than_can_be_show_in_board = today - days(pBoard->size());
//	long day_of_week_offset = today.day_of_week();
//
//	pBoard->reset_all_pixel();
//
//	for (auto& activity : activities_data)
//	{
//		if (std::get<0>(activity) == type)
//		{
//			for (auto& days_and_score : std::get<1>(activity))
//			{
//				if ((last_day_than_can_be_show_in_board <= days_and_score.first) && (days_and_score.first <= today))
//				{
//					date_period dp = { days_and_score.first, today };
//					long day_offset_from_today = dp.length().days();
//
//					if (days_of_week_offset)
//					{
//						pBoard->set_pixel(pBoard->size() - day_offset_from_today - day_of_week_offset + 1,
//								days_and_score.second);
//					}
//					else
//					{
//						pBoard->set_pixel(pBoard->size() - day_offset_from_today - 1, days_and_score.second);
//					}
//
//				}
//			}
//			break;
//		}
//	}
//}
