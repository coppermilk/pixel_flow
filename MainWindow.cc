#include "MainWindow.h"

MainWindow::MainWindow(ControllerBoard *pControllerBoard, QWidget *parent)
        : QMainWindow(parent) {
    // A function that is creating the GUI.
    ui.setupUi(this);

    // This is a pointer to the controller board.
    this->pControllerBoard = pControllerBoard;

    // This is a functions that is changing the color in the pixel board.
    connect(ui.horizontalSliderMaxRedBrightness, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui.horizontalSliderMaxBlueBrightness, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui.horizontalSliderMaxGreenBrightness, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui.horizontalSliderMinRedBrightness, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui.horizontalSliderMinBlueBrightness, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui.horizontalSliderMinGreenBrightness, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));

    // This is a function that is changing the activity in the combo box.
    connect(ui.comboBoxActivityType, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxActivityChanged(int)));
    // This is a function that is changing the time in the combo box.
    connect(ui.comboBoxTimer, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxTimeChanged(int)));

    // This is a loop that is adding the activity types to the combo box.
    auto activity_types = pControllerBoard->get_current_activitys_type();
    for (auto &type: activity_types) {
        if (!type.empty()) {
            ui.comboBoxActivityType->addItem(QString::fromStdString(type));
        }
    }




    // This is a timer that is changing the activity every time the timer is done.
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(timeChanged()));
    timer->start(1000);
    std::vector<int> seconds_parametes_to_select_in_comboBoxTimer = {3, 60, 900, 1800, 3600};
    sec = *seconds_parametes_to_select_in_comboBoxTimer.begin() % 60;
    min = *seconds_parametes_to_select_in_comboBoxTimer.begin() / 60;

    // This is a loop that is adding the activity types to the combo box.
    for (auto &second: seconds_parametes_to_select_in_comboBoxTimer) {
        if (second) {
            ui.comboBoxTimer->addItem(QString::number(second));
        }
    }
    // This is a function that is changing the color in the pixel board.
    onColorChanged();

}

MainWindow::~MainWindow() {
    delete timer;
}


void MainWindow::onColorChanged() {

    // This is a constant that is changing the size of the pixel board.
    const int led_size = 12;

    // This is a function that is changing the color in the pixel board.
    colorMax.setRgb(ui.horizontalSliderMaxRedBrightness->value(), ui.horizontalSliderMaxGreenBrightness->value(),
                    ui.horizontalSliderMaxBlueBrightness->value());
    colorMin.setRgb(ui.horizontalSliderMinRedBrightness->value(), ui.horizontalSliderMinGreenBrightness->value(),
                    ui.horizontalSliderMinBlueBrightness->value());
    QPalette paletteMax = ui.widgetMaxPixelBrightnessColor->palette();
    QPalette paletteMin = ui.widgetMinPixelBrightnessColor->palette();
    paletteMax.setColor(QPalette::Window, colorMax);
    paletteMin.setColor(QPalette::Window, colorMin);
    ui.widgetMaxPixelBrightnessColor->setPalette(paletteMax);
    ui.widgetMinPixelBrightnessColor->setPalette(paletteMin);
    Pixel pixelMin(ui.horizontalSliderMinRedBrightness->value(), ui.horizontalSliderMinGreenBrightness->value(),
                   ui.horizontalSliderMinBlueBrightness->value());
    Pixel pixelMax(ui.horizontalSliderMaxRedBrightness->value(), ui.horizontalSliderMaxGreenBrightness->value(),
                   ui.horizontalSliderMaxBlueBrightness->value());
    pControllerBoard->set_mode_activity(ui.comboBoxActivityType->currentText().toStdString(), pixelMin, pixelMax);

    // Fill the image with colors:
    // This is a constant that is changing the size of the pixel board.
    int size_x = this->pControllerBoard->get_width();

    // This is a constant that is changing the size of the pixel board.
    int size_y = this->pControllerBoard->get_height();

    // Creating image for represent board state as image.
    QImage image = std::move(QImage(size_x * led_size, size_y * led_size, QImage::Format_RGB32));

    // This is a loop that is changing the color in the QImage.
    // Follow board y.
    for (int y = 0; y < size_y; ++y) {
        // Follow board x.
        for (int x = 0; x < size_x; ++x) {
            Pixel p = this->pControllerBoard->get_pixel(this->pControllerBoard->get_height() * x + y);

            // Generate image.
            for (int py = 0; py < led_size; ++py) {
                for (int px = 0; px < led_size; ++px) {
                    if (!(px % led_size) || !(py % led_size)) {
                        // This is a function that is creating white border in the pixel board.
                        image.setPixel((x * led_size) + px, (y * led_size) + py, qRgb(255, 255, 255));
                    } else if ((p.get_r() == 0) && (p.get_g() == 0) && (p.get_b() == 0)) {
                        // This is a function that is changing the color in the pixel board to black, witch not show.
                    } else {
                        // This is a function that is changing the color in the pixel board.
                        image.setPixel((x * led_size) + px, (y * led_size) + py, qRgb(p.get_r(), p.get_g(), p.get_b()));
                    }
                }
            }
        }
    }

    // This is a function that is changing the activity in the combo box.
    ui.name_text_activity->setTitle(QString::fromStdString(pControllerBoard->get_current_activity_type()));

    // This is a function that is showing the image in the user interface.
    ui.label_pixel_board->setPixmap(QPixmap::fromImage(image));

    emit colorChanged(colorMax);
    emit colorChanged(colorMin);

}


void MainWindow::comboBoxActivityChanged(int index) {
    // This is a function that is checking if the index in the combo box is the same as the current index.
    if (index == ui.comboBoxActivityType->currentIndex()) {
        std::string type = ui.comboBoxActivityType->currentText().toStdString();
        std::pair <Pixel, Pixel> min_max_pixels = pControllerBoard->min_max_pixels_in_activityes_types[type];

        ui.horizontalSliderMaxRedBrightness->setValue(min_max_pixels.second.get_r());
        ui.horizontalSliderMaxBlueBrightness->setValue(min_max_pixels.second.get_b());
        ui.horizontalSliderMaxGreenBrightness->setValue(min_max_pixels.second.get_g());

        ui.horizontalSliderMinRedBrightness->setValue(min_max_pixels.first.get_r());
        ui.horizontalSliderMinBlueBrightness->setValue(min_max_pixels.first.get_b());
        ui.horizontalSliderMinGreenBrightness->setValue(min_max_pixels.first.get_g());

        pControllerBoard->set_mode_activity(ui.comboBoxActivityType->currentText().toStdString(), min_max_pixels.first,
                                            min_max_pixels.second);
        onColorChanged();
    } else {
        // This is a function that check if index in combo box exist, if not call the reset index to zero.
        if (index >= ui.comboBoxActivityType->count()) {
            index = 0;
        }
        ui.comboBoxActivityType->setCurrentIndex(index);
        comboBoxActivityChanged(index);
    }

}

void MainWindow::comboBoxTimeChanged(int index) {
    // This is a functions that is changing the time in the combo box.
    sec = ui.comboBoxTimer->currentText().toInt() % 60;
    min = ui.comboBoxTimer->currentText().toInt() / 60;
}

void MainWindow::timeChanged() {
    --sec;
    /*
     * This is a function that is checking if the seconds is less or equal to zero,
     * if it is, it is checking if the minutes is not zero, if it is not zero, it is
     * subtracting one from the minutes and setting the seconds to 60.
     * If the minutes is zero, it is setting the seconds to zero.
     */
    if (sec <= 0) {
        if (min) {
            --min;
            sec = 60;
        } else {
            sec = 0;
        }
    }
    /*
     * This is a function that is checking if the seconds and minutes is zero,
     * if it is, it is setting the seconds and minutes to the value in the combo box.
     */
    if (!sec && !min) {

        sec = ui.comboBoxTimer->currentText().toInt() % 60;
        min = ui.comboBoxTimer->currentText().toInt() / 60;
        comboBoxActivityChanged(ui.comboBoxActivityType->currentIndex() + 1);

    }
    ui.seconds_label->setText(QString::number(sec));
    ui.minutes_label->setText(QString::number(min) + "   :");
}
