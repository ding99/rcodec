// rcodec.h : rcodec.DLL

#pragma once

#ifndef __AFXWIN_H__
  #error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"    // メイン シンボル

#include "ccodec.h"

class CrcodecApp : public CWinApp
{
public:
  CrcodecApp();

  int what_codec (char *, ecodec *);
  int list_codec (ecodec **);

private:
  void set_codec (int, ecodec *);
  double lpcm_from_extended (unsigned char *);
  int rescan (HANDLE);
  int asf_detail (HANDLE);

public:
  virtual BOOL InitInstance();

  DECLARE_MESSAGE_MAP()
};
