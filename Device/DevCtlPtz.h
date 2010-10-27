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
    /// �ƹ�
    virtual BOOL PtzcmdLight( void ) = 0;
    /// ��ˢ ����
    virtual BOOL PtzcmdWiper(void) = 0;
    /// ����
    virtual BOOL                    PtzcmdFan(void) = 0;
    /// ����
    virtual BOOL                    PtzcmdHeater(void) = 0;
    /// �����豸1��2
    virtual BOOL                    PtzcmdAux1(void) = 0;
    virtual BOOL                    PtzcmdAux2(void) = 0;
    /// ����
    virtual BOOL                    PtzcmdZoomIn( void ) = 0;
    virtual BOOL                    PtzcmdZoomOut( void ) = 0;
    /// ����
    virtual BOOL                    PtzcmdFocusNear( void ) = 0;
    virtual BOOL                    PtzcmdFocusFar( void ) = 0;
    /// ��Ȧ
    virtual BOOL                     PtzcmdIrisOpen( void ) = 0;
    virtual BOOL                     PtzcmdIrisClose( void ) = 0;
    /// ˮƽѲ��
    virtual BOOL                     Ptzcmdautopan( void) = 0;
    /// �Զ�Ѳ��
    virtual BOOL                     Ptzcmdrun_seq( void ) = 0;
    virtual BOOL                     Ptzcmdstop_seq (void ) = 0;
    /// �������
    virtual BOOL                    PtzcmdTiltUp( void ) = 0;
    virtual BOOL                    PtzcmdTiltDown( void ) = 0;
    virtual BOOL                    PtzcmdPanLeft( void ) = 0;
    virtual BOOL                    PtzcmdPanRight( void ) = 0;
    virtual BOOL                    PtzcmdUpRight( void ) = 0;
    virtual BOOL                    PtzcmdUpLeft( void ) = 0;
    virtual BOOL                    PtzcmdDownRight( void ) = 0;
    virtual BOOL                    PtzcmdDownLeft( void ) = 0;
    /// Ԥ�õ�
    virtual BOOL                    PtzcmdGotoPreset( void ) = 0;
    virtual BOOL                    PtzcmdSetPreset( void ) = 0;
    virtual BOOL                    PtzcmdClearPreset( void ) = 0;
};

