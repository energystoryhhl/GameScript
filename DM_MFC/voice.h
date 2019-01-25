#pragma once
#include "windows.h"
#include "mmsystem.h"
#pragma comment(lib,"winmm.lib")//Œ§ÈëÂ•Òôî^ÎÄ¼þŽì

#define NOTARGETVOICE			"..\\source\\voice\\NoTarget.wav"
#define NOTARGETVOICEFLAG 1

#define SCRIPTSTARTVOICE		"..\\source\\voice\\ScriptStart.wav"
#define SCRIPTSTARTFLAG 2

#define NO_KILL_TIME_OUT_VOICE	"..\\source\\voice\\NoKillOut.wav"
#define NO_KILL_TIME_OUT_FLAG 3

#define WRAP_STOP_VOICE			"..\\source\\voice\\WrapStop.wav"
#define WRAP_STOP_VOICE_FLAG 4

void PlayVoice(char * voicePath);

void PlayVoiceMultiTimes(char * voicePath, int times = 5);