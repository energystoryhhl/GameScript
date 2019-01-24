#include "stdafx.h"
#include "voice.h"


void PlayVoice(char * voicePath)
{
	PlaySound(voicePath, NULL, SND_FILENAME);
}

void PlayVoiceMultiTimes(char * voicePath,int times)
{
	for (int i = 0; i < times; i++)
	{
		PlaySound(voicePath, NULL, SND_FILENAME);
	}
}