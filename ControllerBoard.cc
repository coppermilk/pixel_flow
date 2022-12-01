#include "ControllerBoard.h"

Pixel ControllerBoard::map(int x, int in_min, int in_max, Pixel out_min, Pixel out_max) {

  if (!x) {
    return {0, 0, 0};
  } else {
    //TODO: DIVISION ON ZERO FIX
    uint8_t r;
    uint8_t g;
    uint8_t b;

    if (x == 1) {
      r = out_min.get_r();
      g = out_min.get_g();
      b = out_min.get_b();
    } else {
      r = (x - in_min) * (out_max.get_r() - out_min.get_r()) / (in_max - in_min) + out_min.get_r();
      g = (x - in_min) * (out_max.get_g() - out_min.get_g()) / (in_max - in_min) + out_min.get_g();
      b = (x - in_min) * (out_max.get_b() - out_min.get_b()) / (in_max - in_min) + out_min.get_b();
    }
    return {r, g, b};
  }
}

ControllerBoard::ControllerBoard(Board *pBoard, ControllerBoard::Mode mode) {
  this->pBoard = pBoard;
  if (mode == Mode::DEBUG) {
    debug_shuffle(pBoard);
  }
}

ControllerBoard::ControllerBoard(Board *pBoard, Data *pData) {
  this->pBoard = pBoard;
  this->pData = pData;
  current_activitys_type = get_current_activitys_type();
  for (auto activity : current_activitys_type) {
    min_max_pixels_in_activityes_types[activity] = std::make_pair(Pixel(0, 0, 0), Pixel(255, 255, 255));
  }
}

void ControllerBoard::debug_shuffle(Board *pBoard) {

  for (int i = pBoard->size(); i > 0; i--) {
    pBoard->set_pixel(pBoard->size() - i, i - 1);
  }
}

void ControllerBoard::set_mode_activity(Data &activities, const std::string &type, const Pixel &min_brightest,
                                        const Pixel &max_brightest,
                                        bool is_need_days_of_week_offset) {
  min_max_pixels_in_activityes_types[type] = {min_brightest, max_brightest};

  using namespace boost::gregorian;
  using namespace boost::posix_time;

  date today = second_clock::local_time().date();
  date last_day_than_can_be_show_in_board = today - days(pBoard->size());
  long day_of_week_offset = today.day_of_week();
  pBoard->reset_all_pixel();

  int max_score = activities.get_max_activy_score_in(type, pBoard->size());
  std::cout << "Max_score: " << max_score << std::endl;

  for (auto &type_activity : activities.data) {
    if (type_activity.first == type) {

      for (auto &days_and_score : type_activity.second) {
        if ((last_day_than_can_be_show_in_board <= days_and_score.first) && (days_and_score.first <= today)) {
          date_period dp = {days_and_score.first, today};
          long day_offset_from_today = dp.length().days();

          Pixel p = map(days_and_score.second, 0, max_score, min_max_pixels_in_activityes_types[type].first,
                        min_max_pixels_in_activityes_types[type].second);

          if (is_need_days_of_week_offset) {
            pBoard->set_pixel(pBoard->size() - day_offset_from_today - (7 - day_of_week_offset), p.get_r(),
                              p.get_g(), p.get_b());
          } else {

            pBoard->set_pixel(pBoard->size(), p.get_r(), p.get_g(), p.get_b());
          };
        }
      }
      break;
    }
  }
  BOOST_LOG_TRIVIAL(info) << "Set mode activity: \'" + type + "\'.";
}

void
ControllerBoard::set_mode_activity(const std::string &type, const Pixel &min_brightest, const Pixel &max_brightest) {
  auto &setup = min_max_pixels_in_activityes_types[type];
  setup.first = min_brightest;
  setup.second = max_brightest;
  current_activity_type = type;
  setup_current_activity_type_scores_hash();

  int max_score_in_current_type = *max_element(current_activity_type_scores_hash.begin(),
                                               current_activity_type_scores_hash.end());
  for (int i = 0; i < pBoard->size(); ++i) {

    Pixel p = map(current_activity_type_scores_hash[i], 0, max_score_in_current_type, setup.first, setup.second);

    pBoard->set_pixel(i, p.get_r(), p.get_g(), p.get_b());
  }
}

void ControllerBoard::reset_current_mode_activity(const Pixel &min_brightest, const Pixel &max_brightest) {
  int max_score_in_current_type = *max_element(current_activity_type_scores_hash.begin(),
                                               current_activity_type_scores_hash.end());
  for (int i = 0; i < pBoard->size(); ++i) {

    Pixel p = map(current_activity_type_scores_hash[i], 0, max_score_in_current_type, min_brightest, max_brightest);

    pBoard->set_pixel(i, p.get_r(), p.get_g(), p.get_b());
  }
}

uint8_t ControllerBoard::get_height() const {
  return pBoard->get_height();
}

uint8_t ControllerBoard::get_width() const {
  return pBoard->get_width();
}

Pixel ControllerBoard::get_pixel(uint16_t i) const {
  return pBoard->get_pixel(i);
}

std::string ControllerBoard::get_current_activity_type() {
  return current_activity_type;
}

std::vector<std::string> ControllerBoard::get_current_activitys_type() {
  return pData->get_activity_types(pData);
}

void ControllerBoard::setup_current_activity_type_scores_hash() {
  std::vector<int> hash(pBoard->size(), 0);

  using namespace boost::gregorian;
  using namespace boost::posix_time;

  date today = second_clock::local_time().date();
  date last_day_than_can_be_show_in_board = today - days(pBoard->size());
  long day_of_week_offset = today.day_of_week();
  pBoard->reset_all_pixel();

  int max_score = pData->get_max_activy_score_in(current_activity_type, pBoard->size());

  for (auto &type_activity : pData->data) {
    if (type_activity.first == current_activity_type) {
      for (auto &days_and_score : type_activity.second) {
        if ((last_day_than_can_be_show_in_board <= days_and_score.first) && (days_and_score.first <= today)) {
          date_period dp = {days_and_score.first, today};
          long day_offset_from_today = dp.length().days();

          int index = pBoard->size() - day_offset_from_today - (7 - day_of_week_offset);
          if (index >= 0 && index <= pBoard->size()) {

            hash[pBoard->size() - day_offset_from_today - (7 - day_of_week_offset)] = days_and_score.second;
          }

        }
      }
      break;
    }
  }
  current_activity_type_scores_hash = std::move(hash);
}

