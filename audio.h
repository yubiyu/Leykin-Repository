#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <vector>

struct Audio
{
    static ALLEGRO_SAMPLE_INSTANCE*activeBgmInstance;
    static std::vector<ALLEGRO_SAMPLE_INSTANCE*>activeSfxInstances;

    enum enumWorldviewParallelSampleParts
    {
        AUDIO_OPS_COTTAGES = 0,
        AUDIO_OPS_MANOR = 1
    };

    static ALLEGRO_SAMPLE *cottagesMacLeodMp3;
    static ALLEGRO_SAMPLE *manorMacLeodMp3;

    static int worldviewParallelSampleInstanceCurrentPart;

    static ALLEGRO_SAMPLE_INSTANCE *cottagesParallelSampleInstance;
    static ALLEGRO_SAMPLE_INSTANCE *manorParallelSampleInstance;

    static float bgmGain;
    static float sfxGain;

    static void Initialize();
    static void Uninitialize();

    static void LoadResources();
    static void UnloadResources();

    static void SetBgmGain(float gain);
    static void SetSfxGain(float gain);

    static void AddSfx(ALLEGRO_SAMPLE* whichSfx);
    static void SetActiveBgm(ALLEGRO_SAMPLE* whichBgm);

    static void WorldviewParallelAudioUpdate();
    static void WorldviewBeginParallelBackgroundAudio();
    static void WorldviewEndParallelBackgroundAudio();
    static void WorldviewSwapParallelBackgroundAudioToPlace();
    static void WorldviewSwapParallelBackgroundAudioToField();

    static void Logic();
};

#endif // AUDIO_H_INCLUDED
