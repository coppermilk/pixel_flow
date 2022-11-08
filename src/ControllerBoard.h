#ifndef PIXEL_FLOW_SRC_CONTROLLERBOARD_H
#define PIXEL_FLOW_SRC_CONTROLLERBOARD_H

#include <boost/log/trivial.hpp>
#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <map>
#include "Board.h"
#include "Data.h"

using std::map;
using std::string;
using boost::gregorian::date;

class ControllerBoard {

 public:
  enum class Mode {
    DEBUG, ACTIVITY
  };

  enum class setting {
    NUMBER_BRIGHTNESS_LEVELS = 8
  };

  ControllerBoard(Board *pBoard, ControllerBoard::Mode mode);

  explicit ControllerBoard(Board *pBoard);

  static void debug_shuffle(Board *pBoard);

  void set_mode_activity(const Data &activities_data, const std::string &type, bool days_of_week_offset = true) const;

  Board *pBoard;
};

#endif //PIXEL_FLOW_SRC_CONTROLLERBOARD_H
