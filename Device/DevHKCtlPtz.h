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
    /// �ƹ�
    virtual bool PtzcmdLight(void);
    /// ��ˢ ����
    virtual bool PtzcmdWiper(void);
    /// ����
    virtual bool PtzcmdFan(void);
    /// ����
    virtual bool PtzcmdHeater(void);
    /// �����豸1��2
    virtual bool PtzcmdAux1(void);
    virtual bool PtzcmdAux2(void);
    /// ����
    virtual bool PtzcmdZoomIn(void);
    virtual bool PtzcmdZoomOut(void);
    /// ����
    virtual bool PtzcmdFocusNear(void);
    virtual bool PtzcmdFocusFar(void);
    /// ��Ȧ
    virtual bool PtzcmdIrisOpen(void);
    virtual bool PtzcmdIrisClose(void);
    /// ˮƽѲ��
    virtual bool Ptzcmdautopan(void);
    /// �Զ�Ѳ��
    virtual bool PtzcmdRunSeq(void);
    virtual bool PtzcmdStopSeq(void);
    /// �������
    virtual bool PtzcmdTiltUp(void);
    virtual bool PtzcmdTiltDown(void);
    virtual bool PtzcmdPanLeft(void);
    virtual bool PtzcmdPanRight(void);
    virtual bool PtzcmdUpRight(void);
    virtual bool PtzcmdUpLeft(void);
    virtual bool PtzcmdDownRight(void);
    virtual bool PtzcmdDownLeft(void);
    /// Ԥ�õ�
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