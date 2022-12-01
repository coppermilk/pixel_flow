#ifndef PIXEL_FLOW_SRC_CONTROLLERBOARD_H
#define PIXEL_FLOW_SRC_CONTROLLERBOARD_H

#include <boost/log/trivial.hpp>
#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <map>
#include "Board.h"
#include "Data.h"
#include "Pixel.h"

using std::map;
using std::string;
using boost::gregorian::date;

class ControllerBoard {

 private:

  /**
  * @brief A private method that is called in the constructor. It is used to set up
  * the `current_activity_type_scores_hash` vector.
  */
  void setup_current_activity_type_scores_hash();

  /**
  * @brief A vector of integers for store current scores.
  */
  std::vector<int> current_activity_type_scores_hash;

  /**
  * @brief
  */
  // uint8_t brightness_levels;
  /**
  * @brief It's a function that maps a value from one range to Pixels, except zero.
  * @param x values to map.
  * @param in_min minimum input values to map.
  * @param in_max maximum input values to map.
  * @param out_max Pixel with minimum RGB color.
  * @param out_min Pixel with maximum RGB color.
  */
  Pixel map(int x, int in_min, int in_max, Pixel out_min, Pixel out_max);

  /**
  * @brief It's a pointer to a Board object. That manipulated.
  */
  Board *pBoard;

  /**
  * @brief It's a pointer to a Data object. That parsed.
  */
  Data *pData;

  /**
  * @brief It's a string that stores the current activity type.
  */
  std::string current_activity_type;

  /**
  * @brief It's a vector of strings that stores the current activity types.
  */
  std::vector<std::string> current_activitys_type;

 public:
  /**
  * @brief It's a enum class that stores the modes of the board.
  * @param DEBUG for increment shuffle every pixel of board.
  * @param ACTIVITY not used.
  */
  enum class Mode {
    DEBUG, ACTIVITY
  };

  /**
  * @brief It's a constructor for debugging.
  * @param mode pointer to board to control.
  * @param pBoard mode for board setup.
  */
  ControllerBoard(Board *pBoard, ControllerBoard::Mode mode);

  /**
  * @brief  It's a constructor.
  * @param pBoard pointer to Board for manipulation.
  * @param pData pointer Data for parsing.
  */
  explicit ControllerBoard(Board *pBoard, Data *pData);

  /**
  * @brief It's a function that shuffles the pixels of the board.
  * @param pBoard pointer to board for shuffles pixels.
  */
  static void debug_shuffle(Board *pBoard);

  /**
  * @brief It's a function that sets the mode of the board to activity.
   * @param activities_data data for parsing.
   * @param type type to setup.
   * @param min_brightest Pixel with minimum RGB brightest.
   * @param max_brightest Pixel with maximum RGB brightest.
   * @param days_of_week_offset bool value to make days of week offset.
  */
  void set_mode_activity(Data &activities_data, const std::string &type, const Pixel &min_brightest,
                         const Pixel &max_brightest, bool days_of_week_offset = true);

  /**
  * @brief It's a function that sets the mode of the board to activity.
  * @param type type to setup.
  * @param min_brightest Pixel with minimum RGB brightest.
  * @param max_brightest Pixel with maximum RGB brightest.
  */
  void set_mode_activity(const std::string &type, const Pixel &min_brightest, const Pixel &max_brightest);

  /**
  * @brief It's a function that sets new color in current mode activity.
  * @param min_brightest Pixel with minimum RGB brightest.
  * @param max_brightest Pixel with maximum RGB brightest.
  */
  void reset_current_mode_activity(const Pixel &min_brightest, const Pixel &max_brightest);

  /**
  * @brief It's a function that returns the height of the board.
  */
  uint8_t get_height() const;

  /**
  * @brief It's a function that returns the width of the board.
  */
  uint8_t get_width() const;

  /**
  * @brief It's a function that returns the pixel of the board by index.
  * @param i index of pixels to return.
  */
  Pixel get_pixel(uint16_t i) const;

  /**
  * @brief It's a function that returns the current activity type.
  */
  std::string get_current_activity_type();

  /**
  * @brief It's a function that returns the current activity types.
  */
  std::vector<std::string> get_current_activitys_type();

  /**
  * @brief It's a map that stores the minimum and maximum pixels for each activity type.
  */
  std::map<std::string, std::pair<Pixel, Pixel>> min_max_pixels_in_activityes_types;
};

#endif //PIXEL_FLOW_SRC_CONTROLLERBOARD_H
