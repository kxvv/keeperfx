/******************************************************************************/
// Bullfrog Engine Emulation Library - for use to remake classic games like
// Syndicate Wars, Magic Carpet or Dungeon Keeper.
/******************************************************************************/
/** @file bflib_sndlib.c
 *     Low-level sound and music related routines.
 * @par Purpose:
 *     Hardware wrapper to play music and sound in games.
 * @par Comment:
 *     Windows version os Bullfrog Engine uses Miles Sound System, wrapped
 *     with WSND7R.DLL. This library contains definitions of the exported functions.
 * @author   Tomasz Lis
 * @date     16 Nov 2008 - 30 Dec 2008
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#include "bflib_sndlib.h"

#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <winbase.h>

#include "bflib_basics.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************/
// Global variables

typedef int (WINAPI *FARPROCI)(int);
typedef int (WINAPI *FARPROCII)(int,int);
typedef int (WINAPI *FARPROCS)(const char *);
typedef int (WINAPI *FARPROCP)(const void *);
typedef int (WINAPI *FARPROCSIII)(const char *,int,int,int);

/******************************************************************************/
// Functions

// GetModuleHandleExA(0,"WSND7R",&hModule); seems not to work

int __stdcall FreeAudio(void)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_FreeAudio@0");
    if (proc==NULL)
    { LbErrorLog("Can't get address of FreeAudio function; skipped.\n"); return 0; }
    return proc();
}

int __stdcall SetRedbookVolume(int volume)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_SetRedbookVolume@4");
    if (proc==NULL)
    { LbErrorLog("Can't get address of SetRedbookVolume function; skipped.\n"); return 0; }
    return ((FARPROCI)proc)(volume);
}

int __stdcall SetSoundMasterVolume(int volume)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_SetSoundMasterVolume@4");
    if (proc==NULL)
    { LbErrorLog("Can't get address of SetSoundMasterVolume function; skipped.\n"); return 0; }
    return ((FARPROCI)proc)(volume);
}

int __stdcall SetMusicMasterVolume(int volume)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_SetMusicMasterVolume@4");
    if (proc==NULL)
    { LbErrorLog("Can't get address of SetMusicMasterVolume function; skipped.\n"); return 0; }
    return ((FARPROCI)proc)(volume);
}

int __stdcall GetSoundInstalled(void)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_GetSoundInstalled@0");
    if (proc==NULL)
    { LbErrorLog("Can't get address of GetSoundInstalled function; skipped.\n"); return 0; }
    return proc();
}

int __stdcall PlayRedbookTrack(int track)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_PlayRedbookTrack@4");
    if (proc==NULL)
    { LbErrorLog("Can't get address of PlayRedbookTrack function; skipped.\n"); return 0; }
    return ((FARPROCI)proc)(track);
}

int __stdcall MonitorStreamedSoundTrack(void)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_MonitorStreamedSoundTrack@0");
    if (proc==NULL)
    { LbErrorLog("Can't get address of MonitorStreamedSoundTrack function; skipped.\n"); return 0; }
    return proc();
}

int __stdcall StopRedbookTrack(void)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_StopRedbookTrack@0");
    if (proc==NULL)
    { LbErrorLog("Can't get address of StopRedbookTrack function; skipped.\n"); return 0; }
    return proc();
}

void * __stdcall GetSoundDriver(void)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_GetSoundDriver@0");
    if (proc==NULL)
    { LbErrorLog("Can't get address of GetSoundDriver function; skipped.\n"); return 0; }
    return (void *)proc();
}

int __stdcall StopAllSamples(void)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_StopAllSamples@0");
    if (proc==NULL)
    { LbErrorLog("Can't get address of StopAllSamples function; skipped.\n"); return 0; }
    return proc();
}

int __stdcall GetFirstSampleInfoStructure(void)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_GetFirstSampleInfoStructure@0");
    if (proc==NULL)
    { LbErrorLog("Can't get address of GetFirstSampleInfoStructure function; skipped.\n"); return 0; }
    return proc();
}

int __stdcall LoadMusic(int i)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_LoadMusic@4");
    if (proc==NULL)
    { LbErrorLog("Can't get address of LoadMusic function; skipped.\n"); return 0; }
    return ((FARPROCI)proc)(i);
}

int __stdcall InitAudio(void *i)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_InitAudio@4");
    if (proc==NULL)
    { LbErrorLog("Can't get address of InitAudio function; skipped.\n"); return 0; }
    return ((FARPROCP)proc)(i);
}

int __stdcall SetupAudioOptionDefaults(void *i)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_SetupAudioOptionDefaults@4");
    if (proc==NULL)
    { LbErrorLog("Can't get address of SetupAudioOptionDefaults function; skipped.\n"); return 0; }
    return ((FARPROCP)proc)(i);
}

int __stdcall PlayStreamedSample(char *fname, int a2, int a3, int a4)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_PlayStreamedSample@16");
    if (proc==NULL)
    { LbErrorLog("Can't get address of PlayStreamedSample function; skipped.\n"); return 0; }
    return ((FARPROCSIII)proc)(fname, a2, a3, a4);
}

int __stdcall StopStreamedSample(void)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_StopStreamedSample@0");
    if (proc==NULL)
    { LbErrorLog("Can't get address of StopStreamedSample function; skipped.\n"); return 0; }
    return proc();
}

int __stdcall StreamedSampleFinished(void)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_StreamedSampleFinished@0");
    if (proc==NULL)
    { LbErrorLog("Can't get address of StreamedSampleFinished function; skipped.\n"); return 0; }
    return proc();
}

int __stdcall SetStreamedSampleVolume(int volume)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_SetStreamedSampleVolume@4");
    if (proc==NULL)
    { LbErrorLog("Can't get address of SetStreamedSampleVolume function; skipped.\n"); return 0; }
    return ((FARPROCI)proc)(volume);
}

int __stdcall GetLastSampleInfoStructure(void)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_GetLastSampleInfoStructure@0");
    if (proc==NULL)
    { LbErrorLog("Can't get address of GetLastSampleInfoStructure function; skipped.\n"); return 0; }
    return proc();
}

int __stdcall GetCurrentSoundMasterVolume(void)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_GetCurrentSoundMasterVolume@0");
    if (proc==NULL)
    { LbErrorLog("Can't get address of GetCurrentSoundMasterVolume function; skipped.\n"); return 0; }
    return proc();
}

int __stdcall StopMusic(void)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_StopMusic@0");
    if (proc==NULL)
    { LbErrorLog("Can't get address of StopMusic function; skipped.\n"); return 0; }
    return proc();
}

int __stdcall LoadAwe32Soundfont(const char *fname)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_LoadAwe32Soundfont@4");
    if (proc==NULL)
    { LbErrorLog("Can't get address of LoadAwe32Soundfont function; skipped.\n"); return 0; }
    return ((FARPROCS)proc)(fname);
}

int __stdcall StartMusic(int i,int v)
{
    HMODULE hModule;
    hModule=GetModuleHandle("WSND7R");
    FARPROC proc;
    proc=GetProcAddress(hModule,"_StartMusic@8");
    if (proc==NULL)
    { LbErrorLog("Can't get address of StartMusic function; skipped.\n"); return 0; }
    return ((FARPROCII)proc)(i,v);
}

/******************************************************************************/
#ifdef __cplusplus
}
#endif
