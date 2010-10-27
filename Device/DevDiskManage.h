/*==============================================================================================================================================================================
【 文件名 】Rpu_Disk_Manage.cpp
【   ID   】Rpu_Disk_Manage.cpp 2010-05-28 Techie $ 
【 作 者  】shugao
【 说 明  】客户端与服务端的通讯
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

#include "Dvr_Include.h"
#include "Rpu_Disk_Manage.h"


/*-----------------------------------------------------------------------------------*/
Rpu_RecordCfg::Rpu_RecordCfg()
{

}
/*-----------------------------------------------------------------------------------*/
Rpu_RecordCfg::Rpu_RecordCfg(const Rpu_RecordCfg & T)
{
    storage_path_		= T.storage_path_;
	pic_path_			= T.pic_path_;
	switch_size_		= T.switch_size_;
	cycle_enable_		= T.cycle_enable_;
	file_size_			= T.file_size_;
	disk_id_			= T.disk_id_;
	alarm_pre_rec_time_	= T.alarm_pre_rec_time_;
	alarm_rec_time_		= T.alarm_rec_time_;
}
/*-----------------------------------------------------------------------------------*/
Rpu_RecordCfg::~Rpu_RecordCfg()
{

}
/*-----------------------------------------------------------------------------------*/
void Rpu_RecordCfg::StoragePath( const char * szPath )
{
   storage_path_ = szPath;
}
/*-----------------------------------------------------------------------------------*/
const char * Rpu_RecordCfg::StoragePath( void )
{
	return storage_path_.c_str();
}
/*-----------------------------------------------------------------------------------*/
void Rpu_RecordCfg::PicPath( const char * szPath )
{
	pic_path_ = szPath;
}
/*-----------------------------------------------------------------------------------*/
const char * Rpu_RecordCfg::PicPath( void )
{
	return pic_path_.c_str();
}
/*-----------------------------------------------------------------------------------*/
void Rpu_RecordCfg::SwitchSize( int iSize)
{
	switch_size_ = iSize;
}
/*-----------------------------------------------------------------------------------*/
int	Rpu_RecordCfg::SwitchSize( void )
{
	return switch_size_;
}
/*-----------------------------------------------------------------------------------*/
void Rpu_RecordCfg::CycleEnable( int Enable )
{
	cycle_enable_ = Enable;
}
/*-----------------------------------------------------------------------------------*/
int	Rpu_RecordCfg::CycleEnable( void )
{
	return cycle_enable_;
}
/*-----------------------------------------------------------------------------------*/
void Rpu_RecordCfg::FileSize( int iSize )
{
	file_size_ = iSize;
}
/*-----------------------------------------------------------------------------------*/
int	Rpu_RecordCfg::FileSize( void )
{
	return file_size_;
}
/*-----------------------------------------------------------------------------------*/
void Rpu_RecordCfg::FileTime( int iTime )
{
	file_time_ = iTime;
}
/*-----------------------------------------------------------------------------------*/
int	Rpu_RecordCfg::FileTime( void )
{
	return file_time_;
}
/*-----------------------------------------------------------------------------------*/
void Rpu_RecordCfg::DiskId( int id )
{
	disk_id_ = id;
}
/*-----------------------------------------------------------------------------------*/
int Rpu_RecordCfg::DiskId( void )
{
	return disk_id_;
}
/*-----------------------------------------------------------------------------------*/
void Rpu_RecordCfg::AlarmPreRecTime( int iSec )
{
	alarm_pre_rec_time_ = iSec;
}
/*-----------------------------------------------------------------------------------*/
int	Rpu_RecordCfg::AlarmPreRecTime( void )
{
	return alarm_pre_rec_time_;
}
/*-----------------------------------------------------------------------------------*/
void Rpu_RecordCfg::AlarmRecTime( int iSec )
{
	alarm_rec_time_	= iSec;
}
/*-----------------------------------------------------------------------------------*/
int	Rpu_RecordCfg::AlarmRecTime( void )
{
	return alarm_rec_time_;
}
/*-----------------------------------------------------------------------------------*/
void Rpu_RecordCfg::Disk_Type( int disktype)
{
	disk_type_ = disktype;
}
/*-----------------------------------------------------------------------------------*/
int	 Rpu_RecordCfg::Disk_Type( void )
{
	return disk_type_;
}
/*-----------------------------------------------------------------------------------*/
void Rpu_RecordCfg::StartDiskId( int diskid)
{
	start_disk_id_ = diskid;
}
/*-----------------------------------------------------------------------------------*/
int	 Rpu_RecordCfg::StartDiskId( void )
{
	return start_disk_id_;
}
/*-----------------------------------------------------------------------------------*/
void Rpu_RecordCfg::StopDiskId( int diskid)
{
	stop_disk_id_ = diskid;
}
/*-----------------------------------------------------------------------------------*/
int	 Rpu_RecordCfg::StopDiskId( void )
{
	return stop_disk_id_;
}
/*-----------------------------------------------------------------------------------*/
void Rpu_RecordCfg::DeleteSize( int disksize)
{
	delte_size_ = disksize;
}
/*-----------------------------------------------------------------------------------*/
int	 Rpu_RecordCfg::DeleteSize( void )
{
	return delte_size_;
}
/*-----------------------------------------------------------------------------------*/
Rpu_Disk_Manage::Rpu_Disk_Manage()
{

}
/*-----------------------------------------------------------------------------------*/
Rpu_Disk_Manage::~Rpu_Disk_Manage()
{

}
/*-----------------------------------------------------------------------------------*/
void Rpu_Disk_Manage::LoadRecordCfg( void )
{
	record_cfg_.AlarmPreRecTime( 10 );
	record_cfg_.AlarmRecTime( 20 );
	record_cfg_.CycleEnable( 1 );
	record_cfg_.Disk_Type( 1 );
	record_cfg_.DiskId( 1 );
	record_cfg_.FileTime( 30 );
	record_cfg_.FileSize( 10 );
	record_cfg_.PicPath( "Pic" );
	record_cfg_.StoragePath( "mp4" );
	record_cfg_.SwitchSize( 1000 );
	 return ;
}
/*-----------------------------------------------------------------------------------*/
int	Rpu_Disk_Manage::Init_Disk_Info( void )
{
	U32		idisk = 0;
	disks_.m_iDiskNum = 0;
	disks_.m_Disk[0].iDiskId =1;
	disks_.m_Disk[0].iDriverType = DISK_SCIS;
#if defined(WIN32)
	sprintf(disks_.m_Disk[0].szDiskName,"%s","g:");	
#else
	sprintf(disks_.m_Disk[0].szDiskName,"%s","/mnt/dir_1");
#endif
	disks_.m_iDiskNum++;

	disks_.m_Disk[1].iDiskId =2;
	disks_.m_Disk[1].iDriverType = DISK_SCIS;
#if defined(WIN32)
	sprintf(disks_.m_Disk[1].szDiskName,"%s","g:");
#else
	sprintf(disks_.m_Disk[1].szDiskName,"%s","/mnt/dir_2");
#endif
	disks_.m_iDiskNum++;

	return idisk;
}
/*-----------------------------------------------------------------------------------*/
int	Rpu_Disk_Manage::Get_Disk_Info( std::vector<HASH_STRING_MAP>& resultdata )			//获取所有硬盘信息
{

	return 0;
}
/*-----------------------------------------------------------------------------------*/
int	Rpu_Disk_Manage::Get_Disk_Info( std::vector<HASH_STRING_MAP>& resultdata ,int diskid)	//获取指定硬盘信息
{
	return 0;
}

/*-----------------------------------------------------------------------------------*/
int	Rpu_Disk_Manage::FormatDisk( int	diskid )
{
	return 0;
}
/*-----------------------------------------------------------------------------------*/
int	Rpu_Disk_Manage::CalcuFileSize(const char * filename)
{
#if defined(WIN32)
	FILE  *fp;
	
	fp = fopen("G:/mp4/2010_6_4/camera_2/camera_2_2010_6_4_14_11_19.mp4","rb+");
	if( fp == NULL )
		return 0;
	else
	{
		fseek( fp, 0, SEEK_END );
		long filesize = ftell(fp);
		filesize/=(1024*1024);
		if(filesize >=  record_cfg_.FileSize())
			return  1;
		else 
			return	0;
	}
#else
		struct stat buf;
		int	  filesize = 0;
		stat(filename, &buf);
		filesize = buf.st_size/(1024*1024);
		if(filesize >=  record_cfg_.FileSize())
			return  0;
		else 
			return	1;

#endif
}
/*-----------------------------------------------------------------------------------*/
int	Rpu_Disk_Manage::CalcuFileTime( INT64 ustime, INT64 uetime )
{
    U32  tspan;

	tspan = uetime - ustime;

	if(tspan >= record_cfg_.FileTime())
		return 1;
	else
		return 0;
}
/*-----------------------------------------------------------------------------------*/