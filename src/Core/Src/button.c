#include "button.h"
int button0_flag = 0; // Define button0_flag as a global variable
int button1_flag = 0; // Define button1_flag as a global variable
int button2_flag = 0; // Define button2_flag as a global variable
int button0_hold_flag = 0; // Define button0_hold_flag as a global variable
int button1_hold_flag = 0; // Define button1_hold_flag as a global variable
int button2_hold_flag = 0; // Define button2_hold_flag as a global variable
int Key0Reg0 = NORMAL_STATE;
int Key0Reg1 = NORMAL_STATE;
int Key0Reg2 = NORMAL_STATE;
int Key0Reg3 = NORMAL_STATE;
int Key1Reg0 = NORMAL_STATE;
int Key1Reg1 = NORMAL_STATE;
int Key1Reg2 = NORMAL_STATE;
int Key1Reg3 = NORMAL_STATE;
int Key2Reg0 = NORMAL_STATE;
int Key2Reg1 = NORMAL_STATE;
int Key2Reg2 = NORMAL_STATE;
int Key2Reg3 = NORMAL_STATE;
int TimerForKey0Reg = 200; // Initialize TimerForKeyReg
int TimerForKey1Reg = 200; // Initialize TimerForKeyReg
int TimerForKey2Reg = 200; // Initialize TimerForKeyReg

// Button 0
int isButton0Press()
{
    if (button0_flag == 1)
    {
        button0_flag = 0;
        return 1;
    }
    return 0;
}
int isButton0Hold()
{
    if (button0_hold_flag == 1)
    {
        button0_hold_flag = 0;
        return 1;
    }
    return 0;
}

void handleButton0Press()
{
    // Code to handle button 0 press event
    button0_flag = 1;
}

void handleButton0Hold()
{
    // Code to handle button 0 hold event
    button0_hold_flag = 1;
}

// Button 1
int isButton1Press()
{
    if (button1_flag == 1)
    {
        button1_flag = 0;
        return 1;
    }
    return 0;
}

int isButton1Hold()
{
    if (button1_hold_flag == 1)
    {
        button1_hold_flag = 0;
        return 1;
    }
    return 0;
}

void handleButton1Press()
{
    // Code to handle button 1 press event
    button1_flag = 1;
}

void handleButton1Hold()
{
    // Code to handle button 1 hold event
    button1_hold_flag = 1;
}

// Button 2
int isButton2Press()
{
    if (button2_flag == 1)
    {
        button2_flag = 0;
        return 1;
    }
    return 0;
}

int isButton2Hold()
{
    if (button2_hold_flag == 1)
    {
        button2_hold_flag = 0;
        return 1;
    }
    return 0;
}
void handleButton2Press()
{
    // Code to handle button 2 press event
    button2_flag = 1;
}

void handleButton2Hold()
{
    // Code to handle button 2 hold event
    button2_hold_flag = 1;
}

void getKeyInputs()
{
    // Button 0
    Key0Reg0 = Key0Reg1;
    Key0Reg1 = Key0Reg2;
    Key0Reg2 = HAL_GPIO_ReadPin(BUTTON0_GPIO_Port, BUTTON0_Pin);

    if ((Key0Reg0 == Key0Reg1) && (Key0Reg1 == Key0Reg2))
    {
        if (Key0Reg3 != Key0Reg2)
        {
            Key0Reg3 = Key0Reg2;
            if (Key0Reg2 == PRESSED_STATE)
            {
                // Button pressed event
                handleButton0Press();
                TimerForKey0Reg = 200; // Reset TimerForKeyReg for hold event
            }
        }
        else
        {
            TimerForKey0Reg--;
            if (TimerForKey0Reg == 0)
            {
                // Button hold event
                if (Key0Reg2 == PRESSED_STATE)
                {
                    handleButton0Hold();
                }
                TimerForKey0Reg = 200; // Reset TimerForKeyReg for next hold event
            }
        }
    }

    // Button 1
    Key1Reg0 = Key1Reg1;
    Key1Reg1 = Key1Reg2;
    Key1Reg2 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);

    if ((Key1Reg0 == Key1Reg1) && (Key1Reg1 == Key1Reg2))
    {
        if (Key1Reg3 != Key1Reg2)
        {
            Key1Reg3 = Key1Reg2;
            if (Key1Reg2 == PRESSED_STATE)
            {
                // Button pressed event
                handleButton1Press();
                TimerForKey1Reg = 200; // Reset TimerForKeyReg for hold event
            }
        }
        else
        {
            TimerForKey1Reg--;
            if (TimerForKey1Reg == 0)
            {
                // Button hold event
                if (Key1Reg2 == PRESSED_STATE)
                {
                    handleButton1Hold();
                }
                TimerForKey1Reg = 200; // Reset TimerForKeyReg for next hold event
            }
        }
    }

    // Button 2
    Key2Reg0 = Key2Reg1;
    Key2Reg1 = Key2Reg2;
    Key2Reg2 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);

    if ((Key2Reg0 == Key2Reg1) && (Key2Reg1 == Key2Reg2))
    {
        if (Key2Reg3 != Key2Reg2)
        {
            Key2Reg3 = Key2Reg2;
            if (Key2Reg2 == PRESSED_STATE)
            {
                // Button pressed event
                handleButton2Press();
                TimerForKey2Reg = 200; // Reset TimerForKeyReg for hold event
            }
        }
        else
        {
            TimerForKey2Reg--;
            if (TimerForKey2Reg == 0)
            {
                // Button hold event
                if (Key2Reg2 == PRESSED_STATE)
                {
                    handleButton2Hold();
                }
                TimerForKey2Reg = 200; // Reset TimerForKeyReg for next hold event
            }
        }
    }
}
