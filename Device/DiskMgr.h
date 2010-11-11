#ifndef _DISKMGR_H_
#define _DISKMGR_H_

#define MAX_DISK_NUM    100 //���ɽ�Ӳ����

typedef struct tagDiskInfo
{
    char            szDiskName[256];        //�̷���
    int             iDiskId;                //Ӳ�̺�
    unsigned int    uTotalSpace;            //����������  ��λG
    unsigned int    uRemaSpace;             //ʣ�����������С ��λG
    int             iDriverType;            //�������͡�--1  scis��2  ide
    int             iDiskGroup;             //���������
} DISKINFO; //������Ϣ

typedef struct tagDISKGROUP
{
    int             iGroupIndex;            //�����
    unsigned int    uGroupSpace;            //���ܴ��̴�С
    unsigned int    uGroupSpaceRema;        //������ܿ��ÿռ�
    int             iFileSize;              //����ļ���С
    int             iDriverNum;             //�����߼��̸���
    DISKINFO        m_Driver[MAX_DISK_NUM]; //�����µ������̷�
}DISKGROUP; //���̷���

typedef struct tagDEVICEDISKS
{
    int       m_iDiskNum;                  //������Ŀ
    DISKINFO  m_Disk[MAX_DISK_NUM];    //��������
} DEVICEDISKS;

class CRecorderCfg
{
private:
    std::string     m_strStoragePath;                //��ǰ¼���ļ�����·��
    std::string     m_strPicPath;                    //��ǰץͼ����·��
    int             m_nSwitchSize;                   //��ǰӲ�������ﵽĳ��ֵʱ���д����л�
    bool            m_bEnableCycle;                  //�Ƿ�ѭ��¼��
    int             m_nFileSize;                     //¼���ļ������С
    int             m_nFileTime;                     //¼���ļ����ʱ��
    int             m_nAlarmPrerecordTime;           //�澯Ԥ¼ʱ��
    int             m_nAlarmRecordTime;              //¼��ʱ��
    int             m_nDiskType;                     //Ӳ������1--scis,2--IDE,
    int             m_nStartDiskId;                  //��ʼӲ��ID
    int             m_nStopDiskId;                   //����Ӳ��ID
    int             m_nDeleteSize;                   //��ǰӲ�������ﵽĳ��ֵʱ���д����������
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