#include "Music/Music.h"

USING_NS_CC;

int mainMusicID = 0;
float musicVolume = 1.0f;
bool musicIfOpen = true;

bool ifBGMPlaying = false;

void beginMainMusic()
{
    AudioEngine::preload("Music/BackMusic.mp3");
    if (!ifBGMPlaying)           //只在第一回开始
    {
        mainMusicID = AudioEngine::play2d("Music/BackMusic.mp3", true);		//这个true是是否循环
        AudioEngine::setVolume(mainMusicID, musicVolume);
        musicIfOpen = true;
        CCLOG("open music");
    }
    ifBGMPlaying = true;
}

void stopMainMusic()
{
    AudioEngine::stop(mainMusicID);
    ifBGMPlaying = false;
}

void playShootMusic()
{
    AudioEngine::preload("music/BulletShot.mp3");
    int ID = AudioEngine::play2d("music/BulletShot.mp3");
    AudioEngine::setVolume(ID, musicVolume);
}

void playClickMusic()
{
    AudioEngine::preload("music/ButtonClick.mp3");
    int ID = AudioEngine::play2d("music/ButtonClick.mp3");
    AudioEngine::setVolume(ID, musicVolume);
}

void playLosekMusic()
{
    AudioEngine::preload("music/LoseBgm.mp3");
    int ID = AudioEngine::play2d("music/LoseBgm.mp3");
    AudioEngine::setVolume(ID, musicVolume);
}

void musicresumeOrpausePlaying()
{
    
    if (AudioEngine::getState(mainMusicID) == AudioEngine::AudioState::PAUSED)  //这里有个提取状态的用法，参数是ID
    {
        AudioEngine::resume(mainMusicID);   //如果暂停，就继续
    }
    else if (AudioEngine::getState(mainMusicID) == AudioEngine::AudioState::PLAYING)
    {
        AudioEngine::pause(mainMusicID);    //如果播放中，就暂停
    }
}

void setMusicVolume()
{
    AudioEngine::setVolume(mainMusicID, musicVolume);
}
