#include "Music/Music.h"

USING_NS_CC;

int mainMusicID = 0;
float musicVolume = 1.0f;
bool musicIfOpen = true;

bool ifBGMPlaying = false;

void beginMainMusic()
{
    AudioEngine::preload("Music/BackMusic.mp3");
    if (!ifBGMPlaying)           //ֻ�ڵ�һ�ؿ�ʼ
    {
        mainMusicID = AudioEngine::play2d("Music/BackMusic.mp3", true);		//���true���Ƿ�ѭ��
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
    
    if (AudioEngine::getState(mainMusicID) == AudioEngine::AudioState::PAUSED)  //�����и���ȡ״̬���÷���������ID
    {
        AudioEngine::resume(mainMusicID);   //�����ͣ���ͼ���
    }
    else if (AudioEngine::getState(mainMusicID) == AudioEngine::AudioState::PLAYING)
    {
        AudioEngine::pause(mainMusicID);    //��������У�����ͣ
    }
}

void setMusicVolume()
{
    AudioEngine::setVolume(mainMusicID, musicVolume);
}
