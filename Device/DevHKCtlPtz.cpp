#include <Windows.h>
#include "DevHKCtlPtz.h"

CDevHKCtlPtz::~CDevHKCtlPtz( void )
{
    Reset();
}

bool CDevHKCtlPtz::Control(DWORD iControlType)
{
    /// 预览模式
    if (-1 != m_lRealHandle)
    {	
        return NET_DVR_PTZControlWithSpeed_EX(m_lRealHandle, m_CurrCmd, m_CmdFlag[iControlType], m_dwSpeed);
    }
    else if (-1 != m_lUserID)
    {    
        /// 无预览模式
        return NET_DVR_PTZControlWithSpeed_Other(m_lUserID, m_lChannel, m_CurrCmd, m_CmdFlag[iControlType], m_dwSpeed);
    }
    return false;
}

int CDevHKCtlPtz::GetSpeed(void)
{
    return m_dwSpeed;
}

bool CDevHKCtlPtz::Reset()
{
    m_dwSpeed     = 1;
    m_lChannel    = 0;
    m_lRealHandle = -1;
    m_lUserID     = -1;
    m_LastCmd     = DVR_CONTROL_CMD_MAX;
    m_CurrCmd     = DVR_CONTROL_CMD_MAX;
    ZeroMemory(m_CmdFlag, sizeof(m_CmdFlag));
    return true;
}



bool CDevHKCtlPtz::PtzcmdSetSpeed(int iSpeed)
{
    m_dwSpeed = iSpeed;
    return true;
}



bool CDevHKCtlPtz::GetNewCmd(DWORD dwPTZCommand)
{
    if (IsValidCmd(dwPTZCommand) == false)
    {
        return false;
    }

    if (m_LastCmd == m_CurrCmd)  /* 上一次的操作还是与当前的操作一致的话 */
    {
        if (0 == m_CmdFlag[dwPTZCommand])
        {
            m_CmdFlag[dwPTZCommand] = 1;
        }
        else
        {
            m_CmdFlag[dwPTZCommand] = 0;
        }
    }
    else   /* 上一次的操作与当前的操作不一致, 则一定是另一命令的开始 */
    {
        m_CmdFlag[dwPTZCommand] = 0;
    }
    m_LastCmd = m_CurrCmd;
    m_CurrCmd = dwPTZCommand;
}

bool CDevHKCtlPtz::IsValidCmd( DWORD iControlType )
{
    return true;
}

bool CDevHKCtlPtz::PtzcmdLight(void)
{
    GetNewCmd(LIGHT_PWRON);
    return Control(LIGHT_PWRON);
}

bool CDevHKCtlPtz::PtzcmdWiper( void )
{
    GetNewCmd(WIPER_PWRON);
    return Control(WIPER_PWRON);  
}

bool CDevHKCtlPtz::PtzcmdFan( void )
{
    GetNewCmd(FAN_PWRON);
    return Control(FAN_PWRON);  
}

bool CDevHKCtlPtz::PtzcmdHeater(void)
{
    GetNewCmd(HEATER_PWRON);
    return Control(HEATER_PWRON);  
}







bool CDevHKCtlPtz::PtzcmdAux1( void )
{
    GetNewCmd(AUX_PWRON1);
    return Control(AUX_PWRON1); 
}

bool CDevHKCtlPtz::PtzcmdAux2( void )
{
    GetNewCmd(AUX_PWRON2);
    return Control(AUX_PWRON2); 
}

bool CDevHKCtlPtz::PtzcmdZoomIn( void )
{
    GetNewCmd(ZOOM_IN);
    return Control(ZOOM_IN);
}

bool CDevHKCtlPtz::PtzcmdZoomOut( void )
{
    GetNewCmd(ZOOM_OUT);
    return Control(ZOOM_OUT);  
}




bool CDevHKCtlPtz::PtzcmdFocusNear( void )
{
    GetNewCmd(FOCUS_NEAR);
    return Control(FOCUS_NEAR);  
}

bool CDevHKCtlPtz::PtzcmdFocusFar( void )
{
    GetNewCmd(FOCUS_FAR);
    return Control(FOCUS_FAR);  
}

bool CDevHKCtlPtz::PtzcmdIrisOpen( void )
{
    GetNewCmd(IRIS_OPEN);
    return Control(IRIS_OPEN);  
}

bool CDevHKCtlPtz::PtzcmdIrisClose( void )
{
    GetNewCmd(IRIS_CLOSE);
    return Control(IRIS_CLOSE); 
}

bool CDevHKCtlPtz::Ptzcmdautopan( void )
{
    GetNewCmd(PAN_AUTO);
    return Control(PAN_AUTO); 
}




bool CDevHKCtlPtz::PtzcmdRunSeq( void )
{
    GetNewCmd(RUN_SEQ);
    return Control(RUN_SEQ); 
}

bool CDevHKCtlPtz::PtzcmdStopSeq( void )
{
    GetNewCmd(STOP_SEQ);
    return Control(STOP_SEQ); 
}

bool CDevHKCtlPtz::PtzcmdTiltUp( void )
{
    GetNewCmd(TILT_UP);
    return Control(TILT_UP); 
}

bool CDevHKCtlPtz::PtzcmdTiltDown( void )
{
    GetNewCmd(TILT_DOWN);
    return Control(TILT_DOWN); 
}

bool CDevHKCtlPtz::PtzcmdPanLeft( void )
{
    GetNewCmd(PAN_LEFT);
    return Control(PAN_LEFT); 
}

bool CDevHKCtlPtz::PtzcmdPanRight( void )
{
    GetNewCmd(PAN_RIGHT);
    return Control(PAN_RIGHT); 
}

bool CDevHKCtlPtz::PtzcmdUpRight( void )
{
    GetNewCmd(UP_RIGHT);
    return Control(UP_RIGHT); 
}

bool CDevHKCtlPtz::PtzcmdUpLeft( void )
{
    GetNewCmd(UP_LEFT);
    return Control(UP_LEFT); 
}

bool CDevHKCtlPtz::PtzcmdDownRight( void )
{
    GetNewCmd(DOWN_RIGHT);
    return Control(DOWN_RIGHT); 
}

bool CDevHKCtlPtz::PtzcmdDownLeft( void )
{
    GetNewCmd(DOWN_LEFT);
    return Control(DOWN_LEFT);
}

bool CDevHKCtlPtz::PtzcmdGotoPreset( void )
{
    return true;
}

bool CDevHKCtlPtz::PtzcmdSetPreset( void )
{
    return true;
}

bool CDevHKCtlPtz::PtzcmdClearPreset( void )
{
    return true;
}

