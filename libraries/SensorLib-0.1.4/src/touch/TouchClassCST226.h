/**
 *
 * @license MIT License
 *
 * Copyright (c) 2023 lewis he
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file      TouchClassCST226.h
 * @author    Lewis He (lewishe@outlook.com)
 * @date      2023-10-06
 */

#include "../TouchDrvInterface.hpp"
#include "../SensorCommon.tpp"

class TouchClassCST226 : public TouchDrvInterface,
    public SensorCommon<TouchClassCST226>
{
    friend class SensorCommon<TouchClassCST226>;

public:
    TouchClassCST226(PLATFORM_WIRE_TYPE &wire, int sda, int scl, uint8_t address);

    bool init();

    void reset();

    uint8_t getPoint(int16_t *x_array, int16_t *y_array, uint8_t get_point);

    bool isPressed();

    const char *getModelName();

    void sleep();

    void wakeup();

    void idle();

    uint8_t getSupportTouchPoint();

    bool getResolution(int16_t *x, int16_t *y);

    void setHomeButtonCallback(home_button_callback_t cb, void *user_data);


private:

    TouchClassCST226() {};

    bool initImpl();
    int getReadMaskImpl();
protected:
    TouchData report;

};










