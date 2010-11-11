#ifndef _DISKMGR_H_
#define _DISKMGR_H_

#define MAX_DISK_NUM    100 //最大可接硬盘数

typedef struct tagDiskInfo
{
    char            szDiskName[256];        //盘符名
    int             iDiskId;                //硬盘号
    unsigned int    uTotalSpace;            //磁盘总容量  单位G
    unsigned int    uRemaSpace;             //剩余磁盘容量大小 单位G
    int             iDriverType;            //磁盘类型。--1  scis，2  ide
    int             iDiskGroup;             //所属分组号
} DISKINFO; //磁盘信息

typedef struct tagDISKGROUP
{
    int             iGroupIndex;            //分组号
    unsigned int    uGroupSpace;            //组总磁盘大小
    unsigned int    uGroupSpaceRema;        //组磁盘总可用空间
    int             iFileSize;              //打包文件大小
    int             iDriverNum;             //组内逻辑盘个数
    DISKINFO        m_Driver[MAX_DISK_NUM]; //分组下的所有盘符
}DISKGROUP; //磁盘分组

typedef struct tagDEVICEDISKS
{
    int       m_iDiskNum;                  //磁盘数目
    DISKINFO  m_Disk[MAX_DISK_NUM];    //磁盘数组
} DEVICEDISKS;

class CRecorderCfg
{
private:
    std::string     m_strStoragePath;                //当前录像文件保存路径
    std::string     m_strPicPath;                    //当前抓图保存路径
    int             m_nSwitchSize;                   //当前硬盘容量达到某个值时进行磁盘切换
    bool            m_bEnableCycle;                  //是否循环录像
    int             m_nFileSize;                     //录像文件打包大小
    int             m_nFileTime;                     //录像文件打包时长
    int             m_nAlarmPrerecordTime;           //告警预录时间
    int             m_nAlarmRecordTime;              //录像时长
    int             m_nDiskType;                     //硬盘类型1--scis,2--IDE,
    int             m_nStartDiskId;                  //起始硬盘ID
    int             m_nStopDiskId;                   //结束硬盘ID
    int             m_nDeleteSize;                   //当前硬盘容量达到某个值时进行磁盘清除处理
};

class CDiskMgr
{
public:
    bool LoadRecordCfg(void);
    bool SaveRecordCfg(void);
    bool InitDiskInfo();
    int  FormatDisk(int diskid);
private:
    DEVICEDISKS disks;
};


#endif