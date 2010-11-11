#include "DevCtlPtz.h"
#include "includeHK/HCNetSDK.h"

class CDevHKCtlPtz
{
public:
    /// Ctor
    CDevHKCtlPtz(LONG lRealHandle);  
    CDevHKCtlPtz(LONG lUserID, LONG lChannel);
    /// Dtor
    virtual ~CDevHKCtlPtz(void);
    virtual bool Reset();
    virtual int  GetSpeed(void);
    ///
    virtual bool PtzcmdSetSpeed(int iSpeed);
    /// 灯光
    virtual bool PtzcmdLight(void);
    /// 雨刷 擦试
    virtual bool PtzcmdWiper(void);
    /// 风扇
    virtual bool PtzcmdFan(void);
    /// 加热
    virtual bool PtzcmdHeater(void);
    /// 辅助设备1和2
    virtual bool PtzcmdAux1(void);
    virtual bool PtzcmdAux2(void);
    /// 焦距
    virtual bool PtzcmdZoomIn(void);
    virtual bool PtzcmdZoomOut(void);
    /// 焦点
    virtual bool PtzcmdFocusNear(void);
    virtual bool PtzcmdFocusFar(void);
    /// 光圈
    virtual bool PtzcmdIrisOpen(void);
    virtual bool PtzcmdIrisClose(void);
    /// 水平巡航
    virtual bool Ptzcmdautopan(void);
    /// 自动巡航
    virtual bool PtzcmdRunSeq(void);
    virtual bool PtzcmdStopSeq(void);
    /// 方向控制
    virtual bool PtzcmdTiltUp(void);
    virtual bool PtzcmdTiltDown(void);
    virtual bool PtzcmdPanLeft(void);
    virtual bool PtzcmdPanRight(void);
    virtual bool PtzcmdUpRight(void);
    virtual bool PtzcmdUpLeft(void);
    virtual bool PtzcmdDownRight(void);
    virtual bool PtzcmdDownLeft(void);
    /// 预置点
    virtual bool PtzcmdGotoPreset(void);
    virtual bool PtzcmdSetPreset(void);
    virtual bool PtzcmdClearPreset(void);
private:
    virtual bool Control(DWORD iControlType);
    virtual bool GetNewCmd(DWORD dwPTZCommand);
    virtual bool IsValidCmd(DWORD iControlType);
    LONG m_lRealHandle;
    LONG m_lUserID;
    LONG m_lChannel;
    DWORD m_CurrCmd;
    DWORD m_LastCmd;
    DWORD m_dwSpeed;
    DWORD m_CmdFlag[DVR_CONTROL_CMD_MAX];
};