
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
* 如果音乐状态为暂停，就继续播放
* 如果音乐状态为播放中，就暂停
*/
void musicresumeOrpausePlaying();

void setMusicVolume();


#endif // !__MUSIC_H__