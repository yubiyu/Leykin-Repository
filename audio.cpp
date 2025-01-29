#include "audio.h"

ALLEGRO_SAMPLE_INSTANCE* Audio::activeBgmInstance;
std::vector<ALLEGRO_SAMPLE_INSTANCE*> Audio::activeSfxInstances;

ALLEGRO_SAMPLE* Audio::cottagesMacLeodMp3;
ALLEGRO_SAMPLE* Audio::manorMacLeodMp3;

ALLEGRO_SAMPLE_INSTANCE* Audio::cottagesParallelSampleInstance;
ALLEGRO_SAMPLE_INSTANCE* Audio::manorParallelSampleInstance;

int Audio::worldviewParallelSampleInstanceCurrentPart;

float Audio::bgmGain;
float Audio::sfxGain;

void Audio::Initialize()
{
    al_install_audio();
    al_init_acodec_addon();

    LoadResources();

    SetBgmGain(0.0);
    SetSfxGain(0.0);

    activeBgmInstance = nullptr;
}

void Audio::Uninitialize()
{
    for(std::vector<ALLEGRO_SAMPLE_INSTANCE*>::iterator it = activeSfxInstances.begin(); it!= activeSfxInstances.end(); ++it)
    {
        al_destroy_sample_instance(*it);
    }
    activeSfxInstances.clear();

    al_destroy_sample_instance(activeBgmInstance);

    UnloadResources();
    al_uninstall_audio();
}

void Audio::LoadResources()
{
    al_reserve_samples(16);

    cottagesMacLeodMp3 = al_load_sample("Magic Scout - Cottages.mp3");
    manorMacLeodMp3    = al_load_sample("Magic Scout - Manor.mp3");

    cottagesParallelSampleInstance = al_create_sample_instance(cottagesMacLeodMp3);
    manorParallelSampleInstance    = al_create_sample_instance(manorMacLeodMp3);
    al_attach_sample_instance_to_mixer(cottagesParallelSampleInstance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(manorParallelSampleInstance,    al_get_default_mixer());
}

void Audio::UnloadResources()
{
    al_destroy_sample_instance(cottagesParallelSampleInstance);
    al_destroy_sample_instance(manorParallelSampleInstance);

    al_destroy_sample(cottagesMacLeodMp3);
    al_destroy_sample(manorMacLeodMp3);
}

void Audio::SetBgmGain(float gain)
{
    bgmGain = gain;
}

void Audio::SetSfxGain(float gain)
{
    sfxGain = gain;
}

void Audio::AddSfx(ALLEGRO_SAMPLE*  whichSfx)
{
    ALLEGRO_SAMPLE_INSTANCE*sfx;
    sfx = al_create_sample_instance(whichSfx);

    al_set_sample_instance_gain(sfx, Audio::sfxGain);
    al_attach_sample_instance_to_mixer(sfx, al_get_default_mixer());
    Audio::activeSfxInstances.push_back(sfx);
    al_play_sample_instance(sfx);
}

void Audio::SetActiveBgm(ALLEGRO_SAMPLE* whichBgm)
{
    if(activeBgmInstance != nullptr)
    {
        al_detach_sample_instance(activeBgmInstance);
        al_destroy_sample_instance(activeBgmInstance);
    }

    activeBgmInstance = al_create_sample_instance(whichBgm);
    al_set_sample_instance_gain(activeBgmInstance, Audio::bgmGain);
    al_attach_sample_instance_to_mixer(activeBgmInstance, al_get_default_mixer());
    al_play_sample_instance(activeBgmInstance);
}

void Audio::WorldviewParallelAudioUpdate()
{

    if(worldviewParallelSampleInstanceCurrentPart == AUDIO_OPS_COTTAGES)
    {
        if(al_get_sample_instance_gain(Audio::cottagesParallelSampleInstance) < 1.0)
            al_set_sample_instance_gain(Audio::cottagesParallelSampleInstance, al_get_sample_instance_gain(Audio::cottagesParallelSampleInstance) + 0.05);

        if(al_get_sample_instance_gain(Audio::manorParallelSampleInstance) > 0.0)
            al_set_sample_instance_gain(Audio::manorParallelSampleInstance, al_get_sample_instance_gain(Audio::manorParallelSampleInstance) - 0.05);
    }

    if(worldviewParallelSampleInstanceCurrentPart == AUDIO_OPS_MANOR) // Don't else if
    {
        if(al_get_sample_instance_gain(Audio::manorParallelSampleInstance) < 1.0)
            al_set_sample_instance_gain(Audio::manorParallelSampleInstance, al_get_sample_instance_gain(Audio::manorParallelSampleInstance) + 0.05);

        if(al_get_sample_instance_gain(Audio::cottagesParallelSampleInstance) > 0.0)
            al_set_sample_instance_gain(Audio::cottagesParallelSampleInstance, al_get_sample_instance_gain(Audio::cottagesParallelSampleInstance) - 0.05);
    }

}

void Audio::WorldviewBeginParallelBackgroundAudio()
{
    al_set_sample_instance_playmode(Audio::cottagesParallelSampleInstance, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_playmode(Audio::manorParallelSampleInstance, ALLEGRO_PLAYMODE_LOOP);

    al_set_sample_instance_gain(Audio::cottagesParallelSampleInstance, 0.0);
    al_set_sample_instance_gain(Audio::manorParallelSampleInstance, 0.0);

    al_play_sample_instance(Audio::cottagesParallelSampleInstance);
    al_play_sample_instance(Audio::manorParallelSampleInstance);

    worldviewParallelSampleInstanceCurrentPart = AUDIO_OPS_COTTAGES;
}

void Audio::WorldviewEndParallelBackgroundAudio()
{
    al_stop_sample_instance(Audio::cottagesParallelSampleInstance);
    al_stop_sample_instance(Audio::manorParallelSampleInstance);
}

void Audio::WorldviewSwapParallelBackgroundAudioToPlace()
{
    worldviewParallelSampleInstanceCurrentPart = AUDIO_OPS_MANOR;
}

void Audio::WorldviewSwapParallelBackgroundAudioToField()
{
    worldviewParallelSampleInstanceCurrentPart = AUDIO_OPS_COTTAGES;
}


void Audio::Logic()
{
    for(std::vector<ALLEGRO_SAMPLE_INSTANCE*>::iterator it = activeSfxInstances.begin(); it != activeSfxInstances.end();)
    {
        if(!al_get_sample_instance_playing(*it))
        {
            al_detach_sample_instance(*it);
            al_destroy_sample_instance(*it);
            it = activeSfxInstances.erase(it);
        }
        else
        {
            ++it;
        }
    }

}
