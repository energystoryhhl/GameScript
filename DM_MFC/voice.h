#pragma once
#include "windows.h"
#include "mmsystem.h"
#pragma comment(lib,"winmm.lib")//Œ§ÈëÂ•Òôî^ÎÄ¼þŽì

#define NOTARGETVOICE "..\\source\\voice\\NoTarget.wav"
#define NOTARGETVOICEFLAG 1

void PlayVoice(char * voicePath);

void PlayVoiceMultiTimes(char * voicePath, int times = 5);