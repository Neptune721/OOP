
#ifndef __MUSIC_H__
#define __MUSIC_H__

#include "cocos2d.h"
#include "AudioEngine.h"

extern int mainMusicID;
extern float musicVolume;
extern bool musicIfOpen;
extern bool ifBGMPlaying;


void beginMainMusic();
void stopMainMusic();

void playShootMusic();
void playClickMusic();
void playLosekMusic();

/*
* �������״̬Ϊ��ͣ���ͼ�������
* �������״̬Ϊ�����У�����ͣ
*/
void musicresumeOrpausePlaying();

void setMusicVolume();


#endif // !__MUSIC_H__