/*
 * software_timer.c
 *
 *  Created on: Sep 16, 2025
 *      Author: tanvietvo
 */

#include "software_timer.h"

#define MAX_COUNTER 10
#define TIMER_TICK 10

int timer_counter[10];
int timer_flag[10];

//Set the counter for software timer
void setTimer(int index, int duration)
{
	timer_counter[index] = duration / TIMER_TICK;
	timer_flag[index] = 0;
}

//Check if the timer is expired
int isTimerExpired(int index)
{
	if (timer_flag[index] == 1)
	{
		timer_flag[index] = 0;
		return 1;
	}
	return 0;
}

//Function to be invoked in Timer_ISR
void timerRun()
{
	for (int i = 0; i < MAX_COUNTER; i++)
	{
		if (timer_counter[i] > 0)
		{
			timer_counter[i]--;
			if (timer_counter[i] == 0)
				timer_flag[i] = 1;
		}

	}
}
