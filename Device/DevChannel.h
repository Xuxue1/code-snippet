/*==============================================================================================================================================================================
【 文件名 】Dvr_Channel.cpp
【   ID   】Dvr_Channel.cpp 2010-04-14  Techie $ 
【 作 者  】Techie
【 说 明  】Hash_Map<key,value>中的value的对象
【 声 明  】
	Copyright (c) 2010
	SHENZHEN GOLDEN HIGHWAY CO.LTD

	ATTENTION: USE OF THIS SOFTWARE IS SUBJECT TO THE FOLLOWING TERMS.
	Permission to use, copy, modify, distribute and/or sell this software
	and/or its documentation is hereby granted without fee. User agrees
	to display the above copyright notice and this license notice in all
	copies of the software and any documentation of the software. User
	agrees to assume all liability for the use of the software; Hewlett-Packard
	makes no representations about the suitability of this software for any
	purpose. It is provided "AS-IS without warranty of any kind,either express
	or implied. User hereby grants a royalty-free license to any and all
	derivatives based upon this software code base.
【修改记录】  
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	序号    |    修改人    |  修改时间  |      Bug ID      |                                修改说明                                                                        |
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	01      |              |            |                  |                                                                                                                |
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

===============================================================================================================================================================================*/  

#include <iostream>
#include "Dvr_Include.h"
#include "Table_Rpu_Base_Device.h"
#include "Table_Rpu_Possess_Dvr_Device.h"
#include "Dvr_Exception.h"
#include "Dvr_User_Login.h"
#include "Dvr_CtlPtz.h"
#include "Dvr_Preview.h"
#include "Dvr_Alarm.h"
#include "Dvr_Channel.h"



//ACE_RCSID (RVS200LIB,Dvr_Channel,"$Id: Dvr_Channel.cpp 82B009 2010-04-14  Techie $")


#if 5
/*-----------------------------------------------------------------------------------*/
Dvr_Channel::Dvr_Channel(Dvr_Preview& dvrplay, Dvr_CtlPtz& dvrctlptz, Dvr_Alarm& dvralarm) :
play_( dvrplay ), ctlptz_( dvrctlptz ) , alarm_(dvralarm) ,
channel_id_(STATE_INVALID), channel_index_(STATE_INVALID)
{
	
}
/*-----------------------------------------------------------------------------------*/
Dvr_Channel::~Dvr_Channel(void)
{
	std::cout << "~Dvr_Channel: Preview" << std::endl;
	delete &play_;
	std::cout << "~Dvr_Channel: CtlPtz" << std::endl;
	delete &ctlptz_;
	std::cout << "~Dvr_Channel:  Alarm" << std::endl;
	delete &alarm_;
}

/*-----------------------------------------------------------------------------------*/
int   Dvr_Channel::get_channel(void)
{
	return channel_id_;
}	
/*-----------------------------------------------------------------------------------*/
void Dvr_Channel::set_channel(  int channel_id, int channel_idx )
{
	play_.channel_id	( channel_id );
	ctlptz_.channel_id	( channel_id );
	alarm_.channel_id	( channel_id );
	channel_id_ 	= channel_id;
	channel_index_ 	= channel_idx;
}

/*-----------------------------------------------------------------------------------*/
void Dvr_Channel::set_channel(int channelid)
{
	play_.channel_id	( channelid );
	ctlptz_.channel_id	( channelid );
	alarm_.channel_id	( channelid );
	channel_id_ = channelid;
}
/*-----------------------------------------------------------------------------------*/

int Dvr_Channel::get_channel_index(void)
{
	return channel_index_;
}
/*-----------------------------------------------------------------------------------*/
void Dvr_Channel::set_channel_index(int channel_idx)
{
	channel_index_ = channel_idx;
}

/*-----------------------------------------------------------------------------------*/
Dvr_Preview* Dvr_Channel::preview(void)
{
	return &play_;
}
/*-----------------------------------------------------------------------------------*/
Dvr_CtlPtz* Dvr_Channel::control_ptz(void)
{
	return &ctlptz_;
}
/*-----------------------------------------------------------------------------------*/
Dvr_Alarm* Dvr_Channel::alarm(void)
{
	return &alarm_;
}



#endif




