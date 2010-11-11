#ifndef _DEVCTLPTZ_H_
#define _DEVCTLPTZ_H_

class IDevUserLogin;
enum tagEnuDvrControlCmdType
{
    DVR_CONTROL_CMD_LIGHT_PWRON		= 0,		/* 接通灯光电源 */
    DVR_CONTROL_CMD_WIPER_PWRON		,			/* 接通雨刷开关 */
    DVR_CONTROL_CMD_FAN_PWRON 		,			/* 接通风扇开关 */
    DVR_CONTROL_CMD_HEATER_PWRON 	,			/* 接通加热器开关 */
    DVR_CONTROL_CMD_AUX_PWRON1		,			/* 接通辅助设备开关 */	
    DVR_CONTROL_CMD_AUX_PWRON2 		,			/* 接通辅助设备开关 */
    DVR_CONTROL_CMD_SET_PRESET		,			/* 设置预置点 */
    DVR_CONTROL_CMD_CLE_PRESET 		,			/* 清除预置点 */
    DVR_CONTROL_CMD_ZOOM_IN 		, 			// 焦距变大
    DVR_CONTROL_CMD_ZOOM_OUT		,			// 焦距变小
    DVR_CONTROL_CMD_FOCUS_NEAR		,			// 焦点前调
    DVR_CONTROL_CMD_FOCUS_FAR		,			// 焦点后调
    DVR_CONTROL_CMD_IRIS_OPEN		,			// 光圈扩大 
    DVR_CONTROL_CMD_IRIS_CLOSE		,			// 光圈扩大 
    DVR_CONTROL_CMD_TILT_UP			,			/* 云台以SS的速度上仰 */
    DVR_CONTROL_CMD_TILT_DOWN 		,			/* 云台以SS的速度下俯 */
    DVR_CONTROL_CMD_PAN_LEFT 		,			/* 云台以SS的速度左转 */
    DVR_CONTROL_CMD_PAN_RIGHT 		,			/* 云台以SS的速度右转 */
    DVR_CONTROL_CMD_UP_LEFT 		,			/* 云台以SS的速度上仰和左转 */
    DVR_CONTROL_CMD_UP_RIGHT 		,			/* 云台以SS的速度上仰和右转 */
    DVR_CONTROL_CMD_DOWN_LEFT 		,			/* 云台以SS的速度下俯和左转 */
    DVR_CONTROL_CMD_DOWN_RIGHT 		,			/* 云台以SS的速度下俯和右转 */
    DVR_CONTROL_CMD_PAN_AUTO 		,			/* 云台以SS的速度左右自动扫描 */
    DVR_CONTROL_CMD_RUN_SEQ			,			/* 开始巡航 */
    DVR_CONTROL_CMD_STOP_SEQ 		,			/* 停止巡航 */
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
    /// 灯光
    virtual bool PtzcmdLight(void) = 0;
    /// 雨刷 擦试
    virtual bool PtzcmdWiper(void) = 0;
    /// 风扇
    virtual bool PtzcmdFan(void) = 0;
    /// 加热
    virtual bool PtzcmdHeater(void) = 0;
    /// 辅助设备1和2
    virtual bool PtzcmdAux1(void) = 0;
    virtual bool PtzcmdAux2(void) = 0;
    /// 焦距
    virtual bool PtzcmdZoomIn(void) = 0;
    virtual bool PtzcmdZoomOut(void) = 0;
    /// 焦点
    virtual bool PtzcmdFocusNear(void) = 0;
    virtual bool PtzcmdFocusFar(void) = 0;
    /// 光圈
    virtual bool PtzcmdIrisOpen(void) = 0;
    virtual bool PtzcmdIrisClose(void) = 0;
    /// 水平巡航
    virtual bool Ptzcmdautopan(void) = 0;
    /// 自动巡航
    virtual bool PtzcmdRunSeq(void) = 0;
    virtual bool PtzcmdStopSeq(void) = 0;
    /// 方向控制
    virtual bool PtzcmdTiltUp(void) = 0;
    virtual bool PtzcmdTiltDown(void) = 0;
    virtual bool PtzcmdPanLeft(void) = 0;
    virtual bool PtzcmdPanRight(void) = 0;
    virtual bool PtzcmdUpRight(void) = 0;
    virtual bool PtzcmdUpLeft(void) = 0;
    virtual bool PtzcmdDownRight(void) = 0;
    virtual bool PtzcmdDownLeft(void) = 0;
    /// 预置点
    virtual bool PtzcmdGotoPreset(void) = 0;
    virtual bool PtzcmdSetPreset(void) = 0;
    virtual bool PtzcmdClearPreset(void) = 0;
};

#endif