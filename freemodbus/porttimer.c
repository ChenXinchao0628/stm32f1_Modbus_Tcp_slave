/*
 * FreeModbus Libary: BARE Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id$
 */

/* ----------------------- Platform includes --------------------------------*/
#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"
#include "main.h"

/* ----------------------- static functions ---------------------------------*/
static void prvvTIMERExpiredISR( void );
extern TIM_HandleTypeDef htim6;

/* ----------------------- Start implementation -----------------------------*/
BOOL
xMBPortTimersInit( USHORT usTim1Timerout50us )
{
    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};

    htim6.Instance = TIM6;
    htim6.Init.Prescaler = 3199;								// 50us记一次数
    htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim6.Init.Period = usTim1Timerout50us - 1;					// usTim1Timerout50us * 50即为定时器溢出时间
    htim6.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
    {
        return FALSE;
    }
    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    if (HAL_TIM_ConfigClockSource(&htim6, &sClockSourceConfig) != HAL_OK)
    {
        return FALSE;
    }
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
    {
        return FALSE;
    }

    __HAL_TIM_ENABLE_IT(&htim6, TIM_IT_UPDATE);					// 使能定时器更新中断
    return TRUE;

}


inline void
vMBPortTimersEnable(  )
{
	    __HAL_TIM_SET_COUNTER(&htim6, 0);		// 清空计数器
    __HAL_TIM_ENABLE(&htim6);	
    /* Enable the timer with the timeout passed to xMBPortTimersInit( ) */
}

inline void
vMBPortTimersDisable(  )
{
	 __HAL_TIM_DISABLE(&htim6);				// 禁能定时器
    /* Disable any pending timers. */
}

/* Create an ISR which is called whenever the timer has expired. This function
 * must then call pxMBPortCBTimerExpired( ) to notify the protocol stack that
 * the timer has expired.
 */
static void prvvTIMERExpiredISR( void )
{
    ( void )pxMBPortCBTimerExpired(  );
}

void TIM6_IRQHandler(void)
{
    if(__HAL_TIM_GET_FLAG(&htim6, TIM_FLAG_UPDATE))			// 更新中断标记被置位
    {
        __HAL_TIM_CLEAR_FLAG(&htim6, TIM_FLAG_UPDATE);		// 清除中断标记
        prvvTIMERExpiredISR();								// 通知modbus3.5个字符等待时间到
    }
}

