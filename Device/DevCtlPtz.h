#ifndef _DEVCTLPTZ_H_
#define _DEVCTLPTZ_H_

class IDevUserLogin;
enum tagEnuDvrControlCmdType
{
    DVR_CONTROL_CMD_LIGHT_PWRON		= 0,		/* ��ͨ�ƹ��Դ */
    DVR_CONTROL_CMD_WIPER_PWRON		,			/* ��ͨ��ˢ���� */
    DVR_CONTROL_CMD_FAN_PWRON 		,			/* ��ͨ���ȿ��� */
    DVR_CONTROL_CMD_HEATER_PWRON 	,			/* ��ͨ���������� */
    DVR_CONTROL_CMD_AUX_PWRON1		,			/* ��ͨ�����豸���� */	
    DVR_CONTROL_CMD_AUX_PWRON2 		,			/* ��ͨ�����豸���� */
    DVR_CONTROL_CMD_SET_PRESET		,			/* ����Ԥ�õ� */
    DVR_CONTROL_CMD_CLE_PRESET 		,			/* ���Ԥ�õ� */
    DVR_CONTROL_CMD_ZOOM_IN 		, 			// ������
    DVR_CONTROL_CMD_ZOOM_OUT		,			// �����С
    DVR_CONTROL_CMD_FOCUS_NEAR		,			// ����ǰ��
    DVR_CONTROL_CMD_FOCUS_FAR		,			// ������
    DVR_CONTROL_CMD_IRIS_OPEN		,			// ��Ȧ���� 
    DVR_CONTROL_CMD_IRIS_CLOSE		,			// ��Ȧ���� 
    DVR_CONTROL_CMD_TILT_UP			,			/* ��̨��SS���ٶ����� */
    DVR_CONTROL_CMD_TILT_DOWN 		,			/* ��̨��SS���ٶ��¸� */
    DVR_CONTROL_CMD_PAN_LEFT 		,			/* ��̨��SS���ٶ���ת */
    DVR_CONTROL_CMD_PAN_RIGHT 		,			/* ��̨��SS���ٶ���ת */
    DVR_CONTROL_CMD_UP_LEFT 		,			/* ��̨��SS���ٶ���������ת */
    DVR_CONTROL_CMD_UP_RIGHT 		,			/* ��̨��SS���ٶ���������ת */
    DVR_CONTROL_CMD_DOWN_LEFT 		,			/* ��̨��SS���ٶ��¸�����ת */
    DVR_CONTROL_CMD_DOWN_RIGHT 		,			/* ��̨��SS���ٶ��¸�����ת */
    DVR_CONTROL_CMD_PAN_AUTO 		,			/* ��̨��SS���ٶ������Զ�ɨ�� */
    DVR_CONTROL_CMD_RUN_SEQ			,			/* ��ʼѲ�� */
    DVR_CONTROL_CMD_STOP_SEQ 		,			/* ֹͣѲ�� */
    DVR_CONTROL_CMD_MAX
};

class IDevCtlPtz
{
public:
    // Dtor
    virtual ~IDevCtlPtz(void);
    virtual int  GetSpeed(void) = 0;
    ///
    virtual bool PtzcmdSetSpeed(int iSpeed) = 0;
    /// �ƹ�
    virtual bool PtzcmdLight(void) = 0;
    /// ��ˢ ����
    virtual bool PtzcmdWiper(void) = 0;
    /// ����
    virtual bool PtzcmdFan(void) = 0;
    /// ����
    virtual bool PtzcmdHeater(void) = 0;
    /// �����豸1��2
    virtual bool PtzcmdAux1(void) = 0;
    virtual bool PtzcmdAux2(void) = 0;
    /// ����
    virtual bool PtzcmdZoomIn(void) = 0;
    virtual bool PtzcmdZoomOut(void) = 0;
    /// ����
    virtual bool PtzcmdFocusNear(void) = 0;
    virtual bool PtzcmdFocusFar(void) = 0;
    /// ��Ȧ
    virtual bool PtzcmdIrisOpen(void) = 0;
    virtual bool PtzcmdIrisClose(void) = 0;
    /// ˮƽѲ��
    virtual bool Ptzcmdautopan(void) = 0;
    /// �Զ�Ѳ��
    virtual bool PtzcmdRunSeq(void) = 0;
    virtual bool PtzcmdStopSeq(void) = 0;
    /// �������
    virtual bool PtzcmdTiltUp(void) = 0;
    virtual bool PtzcmdTiltDown(void) = 0;
    virtual bool PtzcmdPanLeft(void) = 0;
    virtual bool PtzcmdPanRight(void) = 0;
    virtual bool PtzcmdUpRight(void) = 0;
    virtual bool PtzcmdUpLeft(void) = 0;
    virtual bool PtzcmdDownRight(void) = 0;
    virtual bool PtzcmdDownLeft(void) = 0;
    /// Ԥ�õ�
    virtual bool PtzcmdGotoPreset(void) = 0;
    virtual bool PtzcmdSetPreset(void) = 0;
    virtual bool PtzcmdClearPreset(void) = 0;
};

#endif