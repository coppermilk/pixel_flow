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

    void setup_current_activity_type_scores_hash();

    std::vector<int> current_activity_type_scores_hash;

    uint8_t brightness_levels;

    Pixel map(int x, int in_min, int in_max, Pixel out_min, Pixel out_max);

    Board *pBoard;
    Data *pData;
    std::string current_activity_type;
    std::vector <std::string> current_activitys_type;

public:

    enum class Mode {
        DEBUG, ACTIVITY
    };


    ControllerBoard(Board *pBoard, ControllerBoard::Mode mode);

    explicit ControllerBoard(Board *pBoard, Data *pData);

    static void debug_shuffle(Board *pBoard);

    void set_mode_activity(Data &activities_data, const std::string &type, const Pixel &min_brightest,
                           const Pixel &max_brightest, bool days_of_week_offset = true);

    void set_mode_activity(const std::string &type, const Pixel &min_brightest, const Pixel &max_brightest);

    void reset_current_mode_activity(const Pixel &min_brightest, const Pixel &max_brightest);

    uint8_t get_height() const;

    uint8_t get_width() const;

    Pixel get_pixel(uint16_t i) const;

    std::string get_current_activity_type();

    std::vector <std::string> get_current_activitys_type();

    std::map <std::string, std::pair<Pixel, Pixel>> min_max_pixels_in_activityes_types;


};

#endif //PIXEL_FLOW_SRC_CONTROLLERBOARD_H
