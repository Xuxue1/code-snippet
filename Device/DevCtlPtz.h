#include <iostream>
#include "DevUserLogin.h"
class IDevCtlPtz
{
public:
    // Ctor
    IDevCtlPtz(IDevUserLogin *);
    // Dtor
    virtual ~IDevCtlPtz(void);
    void reset(void);
    /// 灯光
    virtual BOOL PtzcmdLight( void ) = 0;
    /// 雨刷 擦试
    virtual BOOL PtzcmdWiper(void) = 0;
    /// 风扇
    virtual BOOL                    PtzcmdFan(void) = 0;
    /// 加热
    virtual BOOL                    PtzcmdHeater(void) = 0;
    /// 辅助设备1和2
    virtual BOOL                    PtzcmdAux1(void) = 0;
    virtual BOOL                    PtzcmdAux2(void) = 0;
    /// 焦距
    virtual BOOL                    PtzcmdZoomIn( void ) = 0;
    virtual BOOL                    PtzcmdZoomOut( void ) = 0;
    /// 焦点
    virtual BOOL                    PtzcmdFocusNear( void ) = 0;
    virtual BOOL                    PtzcmdFocusFar( void ) = 0;
    /// 光圈
    virtual BOOL                     PtzcmdIrisOpen( void ) = 0;
    virtual BOOL                     PtzcmdIrisClose( void ) = 0;
    /// 水平巡航
    virtual BOOL                     Ptzcmdautopan( void) = 0;
    /// 自动巡航
    virtual BOOL                     Ptzcmdrun_seq( void ) = 0;
    virtual BOOL                     Ptzcmdstop_seq (void ) = 0;
    /// 方向控制
    virtual BOOL                    PtzcmdTiltUp( void ) = 0;
    virtual BOOL                    PtzcmdTiltDown( void ) = 0;
    virtual BOOL                    PtzcmdPanLeft( void ) = 0;
    virtual BOOL                    PtzcmdPanRight( void ) = 0;
    virtual BOOL                    PtzcmdUpRight( void ) = 0;
    virtual BOOL                    PtzcmdUpLeft( void ) = 0;
    virtual BOOL                    PtzcmdDownRight( void ) = 0;
    virtual BOOL                    PtzcmdDownLeft( void ) = 0;
    /// 预置点
    virtual BOOL                    PtzcmdGotoPreset( void ) = 0;
    virtual BOOL                    PtzcmdSetPreset( void ) = 0;
    virtual BOOL                    PtzcmdClearPreset( void ) = 0;
};

