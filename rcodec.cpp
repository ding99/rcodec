// rcodec.cpp : DLL initialization

#include "stdafx.h"
#include "rcodec.h"
#include <tchar.h>
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CrcodecApp

BEGIN_MESSAGE_MAP(CrcodecApp, CWinApp)
END_MESSAGE_MAP()

#define C2I(X)  ((buff[X]<<24)|(buff[X+1]<<16)|(buff[X+2]<<8)|(buff[X+3]))
#define C2IS(X) ((buff[X+3]<<24)|(buff[X+2]<<16)|(buff[X+1]<<8)|(buff[X]))

// CrcodecApp コンストラクション

CrcodecApp::CrcodecApp()
{
}

CrcodecApp theApp;


BOOL CrcodecApp::InitInstance()
{
  CWinApp::InitInstance();

  return TRUE;
}

void CrcodecApp::set_codec (int code, ecodec * one) {
  if (! one) return;
  memset (one->code_name, 0, 16);
  memset (one->type_name, 0, 16);
  one->codec_code = code;
  switch (code) {
  case 0:
    one->codec_type = 0;
    memcpy (one->code_name, "Unknown", 7);
    memcpy (one->type_name, "Unknown", 7);
    break;
  case 1:
    one->codec_type = 1;
    memcpy (one->code_name, "MPEG1_video", 11);
    memcpy (one->type_name, "Video", 5);
    break;
  case 2:
    one->codec_type = 1;
    memcpy (one->code_name, "MPEG2_video", 11);
    memcpy (one->type_name, "Video", 5);
    break;
  case 3:
    one->codec_type = 1;
    memcpy (one->code_name, "MPEG4_video", 11);
    memcpy (one->type_name, "Video", 5);
    break;
  case 4:
    one->codec_type = 1;
    memcpy (one->code_name, "MPEG4_AVC", 9);
    memcpy (one->type_name, "Video", 5);
    break;
  case 5:
    one->codec_type = 1;
    memcpy (one->code_name, "VC1", 3);
    memcpy (one->type_name, "Video", 5);
    break;
  case 6:
    one->codec_type = 1;
    memcpy (one->code_name, "AVS_video", 9);
    memcpy (one->type_name, "Video", 5);
    break;
  case 10:
    one->codec_type = 2;
    memcpy (one->code_name, "LPCM_wav", 8);
    memcpy (one->type_name, "Audio", 5);
    break;
  case 11:
    one->codec_type = 2;
    memcpy (one->code_name, "MPEG1_audio", 11);
    memcpy (one->type_name, "Audio", 5);
    break;
  case  12:
    one->codec_type = 2;
    memcpy (one->code_name, "MPEG2_audio", 11);
    memcpy (one->type_name, "Audio", 5);
    break;
  case  13:
    one->codec_type = 2;
    memcpy (one->code_name, "MPEG4_audio", 11);
    memcpy (one->type_name, "Audio", 5);
    break;
  case 14:
    one->codec_type = 2;
    memcpy (one->code_name, "MPEG4HE_AAC", 11);
    memcpy (one->type_name, "Audio", 5);
    break;
  case 15:
    one->codec_type = 2;
    memcpy (one->code_name, "mp3", 3);
    memcpy (one->type_name, "Audio", 5);
    break;
  case 16:
    one->codec_type = 2;
    memcpy (one->code_name, "AVS_AASF", 8);
    memcpy (one->type_name, "Audio", 5);
    break;
  case 17:
    one->codec_type = 2;
    memcpy (one->code_name, "AVS_AATF", 8);
    memcpy (one->type_name, "Audio", 5);
    break;
  case 19:
    one->codec_type = 2;
    memcpy (one->code_name, "LPCM_aiff", 9);
    memcpy (one->type_name, "Audio", 5);
    break;
  case 20:
    one->codec_type = 2;
    memcpy (one->code_name, "MLP", 3);
    memcpy (one->type_name, "Audio", 5);
    break;
  case 21:
    one->codec_type = 2;
    memcpy (one->code_name, "AC3", 3);
    memcpy (one->type_name, "Audio", 5);
    break;
  case 22:
    one->codec_type = 2;
    memcpy (one->code_name, "DDPlus", 6);
    memcpy (one->type_name, "Audio", 5);
    break;
  case 23:
    one->codec_type = 2;
    memcpy (one->code_name, "DTS", 3);
    memcpy (one->type_name, "Audio", 5);
    break;
  case 24:
    one->codec_type = 2;
    memcpy (one->code_name, "WMAPro", 6);
    memcpy (one->type_name, "Audio", 5);
    break;
  case 25:
    one->codec_type = 2;
    memcpy (one->code_name, "DRA", 3);
    memcpy (one->type_name, "Audio", 5);
    break;
  case 30:
    one->codec_type = 6;
    memcpy (one->code_name, "ASF", 3);
    memcpy (one->type_name, "Mux", 3);
    break;
  case 31:
    one->codec_type = 6;
    memcpy (one->code_name, "AVI", 3);
    memcpy (one->type_name, "Mux", 3);
    break;
  case 32:
    one->codec_type = 6;
    memcpy (one->code_name, "ASF_wmv", 7);
    memcpy (one->type_name, "Mux", 3);
    break;
  case 33:
    one->codec_type = 6;
    memcpy (one->code_name, "ASF_wma", 7);
    memcpy (one->type_name, "Mux", 3);
    break;
  case 34:
    one->codec_type = 6;
    memcpy (one->code_name, "MKV", 3);
    memcpy (one->type_name, "Mux", 3);
    break;
  case 35:
    one->codec_type = 6;
    memcpy (one->code_name, "MOV", 3);
    memcpy (one->type_name, "Mux", 3);
    break;
  case 36:
    one->codec_type = 6;
    memcpy (one->code_name, "RM", 2);
    memcpy (one->type_name, "Mux", 3);
    break;
  case 37:
    one->codec_type = 6;
    memcpy (one->code_name, "FLV", 3);
    memcpy (one->type_name, "Mux", 3);
    break;
  case 38:
    one->codec_type = 6;
    memcpy (one->code_name, "CDXA", 4);
    memcpy (one->type_name, "Mux", 3);
    break;
  case 40:
    one->codec_type = 4;
    memcpy (one->code_name, "MPEG2_ts", 8);
    memcpy (one->type_name, "TS", 2);
    break;
  case 41:
    one->codec_type = 5;
    memcpy (one->code_name, "MPEG1_ps", 8);
    memcpy (one->type_name, "PS", 2);
    break;
  case 42:
    one->codec_type = 5;
    memcpy (one->code_name, "MPEG2_ps", 8);
    memcpy (one->type_name, "PS", 2);
    break;
  case 43:
    one->codec_type = 5;
    memcpy (one->code_name, "EVD_ps", 6);
    memcpy (one->type_name, "PS", 2);
    break;
  case 44:
    one->codec_type = 6;
    memcpy (one->code_name, "MXF", 3);
    memcpy (one->type_name, "Mux", 3);
    break;
  default:
    one->codec_type = 99;
    memcpy (one->code_name, "Unknown", 7);
    memcpy (one->type_name, "Unknown", 7);
    break;
  }
}

double CrcodecApp::lpcm_from_extended (unsigned char * lbuf) {
  double fi;
  long bs;
  unsigned long hm, lm;

  bs = ((lbuf [0] & 0x7f) << 8) | (lbuf [1] & 0xff);
  hm = ((unsigned long) (lbuf [2] & 0xff) << 24)
     | ((unsigned long) (lbuf [3] & 0xff) << 16)
     | ((unsigned long) (lbuf [4] & 0xff) <<  8)
     | ((unsigned long) (lbuf [5] & 0xff));
  lm = ((unsigned long) (lbuf [6] & 0xff) << 24)
     | ((unsigned long) (lbuf [7] & 0xff) << 16)
     | ((unsigned long) (lbuf [8] & 0xff) <<  8)
     | ((unsigned long) (lbuf [9] & 0xff));

  if (bs == 0x7fff) fi = HUGE_VAL;
  else if (bs == 0 && hm == 0 && lm == 0) fi = 0;
  else {
    bs -= 0x3fff;
    fi = ldexp (hm * 1.0, bs -= 31);
    fi += ldexp (lm * 1.0, bs -= 32);
  }

  return ((lbuf [0] & 0x80) ? -1 : 1) * fi;
}

int CrcodecApp::asf_detail (HANDLE fin) {
  long ip_h = 0;
  unsigned long done;
  unsigned char * dbuf, hbuf [24];
  int ipc, hsize, gsize = 24, cod = 30;

  SetFilePointer (fin, 0, & ip_h, FILE_BEGIN);
  ReadFile (fin, hbuf, 24, & done, NULL);
  if ((int) done < 24) return cod;

  hsize = hbuf [19] << 24 | hbuf [18] << 16 | hbuf [17] << 8 | hbuf [16];

  if ((dbuf = (unsigned char *) malloc (hsize)) == NULL) return cod;

  SetFilePointer (fin, 0, & ip_h, FILE_BEGIN);
  ReadFile (fin, dbuf, hsize, & done, NULL);
  if ((int) done < hsize) return cod;

  for (ipc = 30; ipc < hsize; ipc += gsize) {

    gsize = dbuf [ipc + 19] << 24 | dbuf [ipc + 18] << 16 | dbuf [ipc + 17] << 8 | dbuf [ipc + 16];
    switch (dbuf [ipc + 24] << 24 | dbuf [ipc + 25] << 16 | dbuf [ipc + 26] << 8 | dbuf [ipc + 27]) {
    case 0x409E69F8: /* Audio Media */
      if (cod != 32) cod = 33;
      break;
    case 0xC0EF19BC: /* Video Media */
      cod = 32;
      break;
    default: break;
    }
  }
  free (dbuf);
  return cod;
}

int CrcodecApp::rescan (HANDLE fin) {
  DWORD slow, shigh;
  long ip_h = 0;
  unsigned long done;
  unsigned char * buff;
  int ipc, t_num, dsize, layer = 0, nc = 0, id, br, stt = 1, sw, l0, n0, p0;
  double fr;

  /* 11172-3 2.4.2.3 */
  unsigned int br_idx [60] = { /* 60 = 15 * 3 + 15 (LSF) */
    0, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448,
    0, 32, 48, 56, 64,  80,  96,  112, 128, 160, 192, 224, 256, 320, 384,
    0, 32, 40, 48, 56,  64,  80,  96,  112, 128, 160, 192, 224, 256, 320,
    0, 8,  16, 24, 32,  40,  48,  56,  64,  80,  96,  112, 128, 144, 160
  };
  
  double fr_tbl [8] = {22.05, 24, 16, 0, 44.1, 48, 32, 0}; /* LSF-4, HSF-4 */

  /* get size (max:64k). */
  slow = GetFileSize (fin, & shigh);
  t_num = (((__int64) shigh << 32) | slow) > 65552 ?
    65552 : (int) (((__int64) shigh << 32) | slow);
  buff = (unsigned char *) malloc (t_num);
  if (! buff) return 0;
  t_num -= 16;

  SetFilePointer (fin, 0, & ip_h, FILE_BEGIN);
  ReadFile (fin, buff, t_num, & done, NULL);
  if ((int) done < t_num) {
    free (buff);
    return 0;
  }

  if (C2I(0) == 0x494433) { /* ID3 v2.x */
    dsize = (buff [6] & 0x7f) << 21 | (buff [7] & 0x7f) << 14 |
      (buff [8] & 0x7f) << 7 | (buff [9] & 0x7f);
    dsize += 10;
  } else dsize = 0;

  if (t_num > 188 && buff [0] == 0x47 && buff [188] == 0x47) {
    free (buff);
    return 4;
  }

  if (t_num > 196 && buff [4] == 0x47 && buff [196] == 0x47) {
    free (buff);
    return 5;
  }

  for (ipc = dsize; ipc < t_num; ipc += dsize) {

    dsize = 1;
    /* frame_header */
    if (((buff [ipc] << 8 | buff [ipc + 1]) & 0xfff0) == 0xfff0) {

      layer = 4 - (buff [ipc + 1] >> 1) & 3;
      if (layer == 0) continue;

      id = (buff [ipc + 1] >> 3) & 1;
      fr = fr_tbl [id * 4 + ((buff [ipc + 2] >> 2) & 3)];
      br = (buff [ipc + 2] >> 4) & 15;

      if (fr != 0) {
        nc = (int) ((layer == 1 ? 12 : 144) *
        br_idx [(id ? ((layer - 1) * 15) : 45) + br] / fr);
        if (! id) nc /= 2; /* to investigate. Apr. 26, 2007 */
      } else continue;

      if (stt) { 
        stt = 0;
        sw = ipc;
        l0 = layer;
        n0 = nc;
        p0 = (buff [ipc + 2] >> 1) & 1;
        dsize = 3;
      } else {
        if (ipc == sw + n0 + p0 && layer == l0) {
          free (buff);
          return layer;
        }
      }
    }
  }

  /* to search mxf */
  stt = 0;
  for (ipc = 0; ipc < t_num - 16; ipc ++) {
    if (C2I(ipc) == 0x60e2b34) {
      free (buff);
      return 6;
    }
  }

  /* avs audio::aatf */
  if (! buff [0] && (buff [1] & 0xf0) == 0x10) {
    free (buff);
    return 7;
  }

  free (buff);
  return 0;
}

int CrcodecApp::what_codec (char * id, ecodec * one) {
  HANDLE file_in;
  unsigned char buff [2048];
  unsigned int i, lenc, swab = 0, offset, fsize;
  unsigned long done;
  long ip_h = 0, ip_l = 0;
  __int64 ipc;
  int codec = 98;

  // for debuf monitor
  // FILE * fff;
  // fff = fopen ("f:\\avs\\cbc\\avs.log", "ab");

  unsigned int ac3_frame [114] = {  /* 114 = 38 * 3 */
    64, 64, 80, 80, 96, 96, 112, 112, 128, 128,
    160, 160, 192, 192, 224, 224, 256, 256, 320, 320,
    384, 384, 448, 448, 512, 512, 640, 640, 768, 768,
    896, 896, 1024, 1024, 1152, 1152, 1280, 1280,
    69, 70, 87, 88, 104, 105, 121, 122, 139, 140,
    174, 175, 208, 209, 243, 244, 278, 279, 348, 349,
    417, 418, 487, 488, 557, 558, 696, 697, 835, 836,
    975, 976, 1114, 1115, 1253, 1254, 1393, 1394,
    96, 96, 120, 120, 144, 144, 168, 168, 192, 192,
    240, 240, 288, 288, 336, 336, 384, 384, 480, 480,
    576, 576, 672, 672, 768, 768, 960, 960, 1152, 1152,
    1344, 1344, 1536, 1536, 1728, 1728, 1920, 1920
  };

#if 0
  /* CRC lookup table */
  unsigned short crc16_table [256] = {
    0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
    0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
    0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
    0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
    0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
    0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
    0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
    0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
    0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
    0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
    0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
    0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
    0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
    0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
    0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
    0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
    0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
    0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
    0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
    0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
    0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
    0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
    0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
    0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
    0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
    0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
    0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
    0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
    0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
    0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
    0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
    0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040
  };
#endif

  if ((file_in = CreateFile (id, GENERIC_READ, FILE_SHARE_READ, 
    NULL, OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE) {
    return 0;
  }

  SetFilePointer (file_in, ip_l, & ip_h, FILE_BEGIN);
  ReadFile (file_in, buff, 8, & done, NULL);

  if (done < 4) {
    set_codec (0, one);
    CloseHandle (file_in);
    return 0;
  }

  switch (C2I(0)) {
  case 0x1b3:
    ip_l = 0;
    ip_h = 0;
    SetFilePointer (file_in, 0, & ip_h, FILE_BEGIN);
    ReadFile (file_in, buff, 2048, & done, NULL);
    if (done < 2048) break;
    for (i = 0; i < 2045; i ++) {
      if ((C2I(i)) == 0x1b5) ip_l ++;
      else if ((C2I(i)) == 0x100) break;
    }
    codec = ip_l ? 2 : 1; /* MPEG2_video : MPEG1_video */
    break;
  case 0x1ba:
    ip_h = 0;
    SetFilePointer (file_in, 0, & ip_h, FILE_BEGIN);
    ReadFile (file_in, buff, 5, & done, NULL);
    if (done != 5) {
      codec = 0;
      break;
    }
    if ((buff [4] & 0xf0) == 0x20) codec = 41;  /* MPEG1_ps */
    else if ((buff [4] & 0xc0) == 0x40) codec = 42;  /* MPEG2_ps */
    else codec = 0;
    /* to do, special for variable length of block */
    break;
  case 1:     codec = 4; break; /* avc */
  case 0x10f: codec = 5; break; /* vc1 */
  case 0x1b0: codec = 6; break; /* avs */
  case 0x1a45dfa3: codec = 34; break; /* mkv */
  case 'RF64': /* 0x52463634 */
    ip_h = 0;
    SetFilePointer (file_in, 0, & ip_h, FILE_BEGIN);
    ReadFile (file_in, buff, 12, & done, NULL);
    if(C2I(8) == 'WAVE') codec = 10;
	break; /* lpcm_wav */
  case 'RIFF': /* 0x52494646 */
    ip_h = 0;
    SetFilePointer (file_in, 0, & ip_h, FILE_BEGIN);
    ReadFile (file_in, buff, 12, & done, NULL);
    switch (C2I(8)) {
    case 'WAVE': codec = 10; break; /* lpcm_wav */
    case 'AVI ': codec = 31; break; /* avi */
    case 'CDXA': codec = 38; break; /* cdxa */
    default: codec = 99; break;
    }
    if (codec != 10) break;
    if (one) {
      ipc = 12;
      while (1) {
        ip_h = (long) ((ipc >> 32) & 0xffffffff);
        ip_l = (long) (ipc & 0xffffffff);
        SetFilePointer (file_in, ip_l, & ip_h, FILE_BEGIN);
        ReadFile (file_in, buff, 24, & done, NULL);
        if (done < 24) break;
        lenc = C2IS(4);
        if ((C2I(0)) == 0x666d7420) {
          one->channels    = ((buff [11] << 8) | buff [10]);
          one->samplerate  = C2IS(12);
          one->bitrate     = (C2IS(16)) * 8;
          one->sampledepth = (buff [21] << 8 | buff [20]) * 8;
          one->sampledepth /= one->channels;
          break;
        }
        ipc += lenc + 8;
      }
    }
    break;
  case 'FORM': /* 0x464f524d */
    ip_h = 0;
    SetFilePointer (file_in, 0, & ip_h, FILE_BEGIN);
    ReadFile (file_in, buff, 12, & done, NULL);
    if ((C2I(8)) != 'AIFF' && (C2I(8)) != 'AIFC') {
      codec = 99;
      break;
    }
    codec = 19; /* lpcm_aiff */
    if (one) {
      ipc = 12;
      while (1) {
        ip_h = (long) ((ipc >> 32) & 0xffffffff);
        ip_l = (long) (ipc & 0xffffffff);
        SetFilePointer (file_in, ip_l, & ip_h, FILE_BEGIN);
        ReadFile (file_in, buff, 26, & done, NULL);
        if (done < 26) break;
        lenc = C2I(4);
        if ((C2I(0)) == 0x434f4d4d) {
          one->channels = ((buff [8] << 8) | buff [9]);
          one->sampledepth = ((buff [14] << 8) | buff [15]);
          one->samplerate = (int) lpcm_from_extended ((unsigned char *) & buff + 16);
          one->bitrate = one->samplerate * one->channels * one->sampledepth;
          break;
        }
        ipc += lenc + 8;
      }
    }
    break;
  case 0x7ffe8001:  /* cpt, lossy */
    codec = 23;
    break;
  case 0x4350544c:  /* cptl */
    codec = ((C2I(4)) == 0x20484452) ? 23 : 0;
    break;
  case 0x44545348:  /* dtshd */
    codec = ((C2I(4)) == 0x44484452) ? 23 : 0;
    break;
  case 0x3026b275: /* asf */
    codec = asf_detail (file_in);
    break;
  case '.RMF': /* RM */
    codec = 36;
    break;
  case 'segh': /* EVD_ps */
    codec = 43;
    break;
  case 'AASF':/* AVS Audio: aasf_id */
    codec = 16;
    break;
  default:
    if (((C2I(4)) & 0xfffffffe) == 0xf8726fba) {
      codec = 20;
      /* detect channels etc. for MLP */
    } else if ((C2I(4)) == 'ftyp' || (C2I(4)) == 'mdat' || (C2I(4)) == 'moov') {
      codec = 35;
      /* QuickTime, 2007-09-04 */
    } else if (((C2I(0)) & 0xffffff00) == 0x464c5600) {
      codec = 37;
      /* FLV, Adobe Video File Format Specification Version 9 */
    } else {

      ip_h = 0;
      SetFilePointer (file_in, 0, & ip_h, FILE_BEGIN);
      ReadFile (file_in, buff, 2048, & done, NULL);
      for (offset = 0; offset < done; offset += 2) {
        if (buff [offset] == 11 && buff [offset + 1] == 0x77) {
          codec = 22; /* DDPlus */
          break;
        } else if (buff [offset + 1] == 11 && buff [offset] == 0x77) {
          swab = 1;
          codec = 22; /* DDPlus */
          break;
        }
      }

      if (codec == 22) {
        ip_h = 0;
        SetFilePointer (file_in, offset, & ip_h, FILE_BEGIN);
        ReadFile (file_in, buff, 8, & done, NULL);
        if (swab) buff [4] = buff [5];
        fsize = ac3_frame [((buff [4] >> 6) & 3) * 38 + (buff [4] & 0x3f)];
        ip_h = (long) (((__int64) ((fsize << 1) + offset) >> 32) & 0xffffffff);
        ip_l = (long) (((fsize << 1) + offset) & 0xffffffff);
        SetFilePointer (file_in, ip_l, & ip_h, FILE_BEGIN);
        if (ReadFile (file_in, & buff, 8, & done, NULL) != 0) {
          if (swab) {
            if (buff [1] == 11 && buff [0] == 0x77) codec = 21; /* AC3 */
          } else {
            if (buff [0] == 11 && buff [1] == 0x77) codec = 21; /* AC3 */
          }
        }

        if (codec == 22) {
          ip_h = 0;
          SetFilePointer (file_in, offset, & ip_h, FILE_BEGIN);
          ReadFile (file_in, buff, 8, & done, NULL);
          fsize = (swab ? ((buff [3] & 7) << 8 | buff [2]) : ((buff [2] & 7) << 8 | buff [3])) + 1;
          ip_h = (long) ((((__int64) ((fsize << 1) + offset)) >> 32) & 0xffffffff);
          ip_l = (long) (((fsize << 1) + offset) & 0xffffffff);
          SetFilePointer (file_in, ip_l, & ip_h, FILE_BEGIN);
          if (ReadFile (file_in, & buff, 8, & done, NULL) != 0) {
            if (swab)  {
              if (buff [1] != 11 || buff [0] != 0x77) codec = 99; /* not DDPluse */
            } else {
              if (buff [0] != 11 || buff [1] != 0x77) codec = 99; /* not DDPlus */
            }
          }
        }
      }

      if (codec != 22 && codec != 21) {
        for (offset = 0; offset < done; offset += 4) {
          if (((C2I(offset)) & 0xfffffffe) == 0xf8726fba) { // modified after 1.1.0.53
            codec = 20; /* MLP */
            break;
          }
        }
        if (codec != 20) {
          switch (rescan (file_in)) {
          case 2:  codec = 11; break;
          case 3:  codec = 15; break;
          case 4:  codec = 40; break;
          case 5:  codec = 40; break;
          case 6:  codec = 44; break;
          case 7:  codec = 17; break;  /* AVS_AATF_audio */
          default: codec = 99; break;
          }
        }
      }
    }
    break;
  }

  set_codec (codec, one);
  CloseHandle (file_in);
  // fclose (fff); // for debuf monitor
  return codec;
}

int CrcodecApp::list_codec (ecodec ** wcodec) {
  int n, i;

  struct ecodec ocodec [] = {
    { 1, "MPEG1_video", 1, "Video", 0, 0, 0, 0},
    { 2, "MPEG2_video", 1, "Video", 0, 0, 0, 0},
    { 3, "MPEG4_video", 1, "Video", 0, 0, 0, 0},
    { 4, "MPEG4_AVC",   1, "Video", 0, 0, 0, 0},
    { 5, "VC1",         1, "Video", 0, 0, 0, 0},
    { 6, "AVS_video",   1, "Video", 0, 0, 0, 0},
    {10, "LPCM_wav",    2, "Audio", 0, 0, 0, 0},
    {11, "MPEG1_audio", 2, "Audio", 0, 0, 0, 0},
    {12, "MPEG2_audio", 2, "Audio", 0, 0, 0, 0},
    {13, "MPEG4_audio", 2, "Audio", 0, 0, 0, 0},
    {14, "MPEG4HE_AAC", 2, "Audio", 0, 0, 0, 0},
    {15, "mp3",         2, "Audio", 0, 0, 0, 0},
    {16, "AVS_AASF",    2, "Audio", 0, 0, 0, 0},
    {17, "AVS_AATF",    2, "Audio", 0, 0, 0, 0},
    {19, "LPCM_aiff",   2, "Audio", 0, 0, 0, 0},
    {20, "MLP",         2, "Audio", 0, 0, 0, 0},
    {21, "AC3",         2, "Audio", 0, 0, 0, 0},
    {22, "DDPlus",      2, "Audio", 0, 0, 0, 0},
    {23, "DTS",         2, "Audio", 0, 0, 0, 0},
    {24, "WMAPro",      2, "Audio", 0, 0, 0, 0},
    {25, "DRA",         2, "Audio", 0, 0, 0, 0},
    {30, "ASF",         6, "MUX",   0, 0, 0, 0},
    {31, "AVI",         6, "MUX",   0, 0, 0, 0},
    {32, "ASF_wmv",     6, "MUX",   0, 0, 0, 0},
    {33, "ASF_wma",     6, "MUX",   0, 0, 0, 0},
    {34, "MKV",         6, "MUX",   0, 0, 0, 0},
    {35, "MOV",         6, "MUX",   0, 0, 0, 0},
    {36, "RM",          6, "MUX",   0, 0, 0, 0},
    {37, "FLV",         6, "MUX",   0, 0, 0, 0},
    {38, "CDXA",        6, "MUX",   0, 0, 0, 0},
    {40, "MPEG2_ts",    4, "TS",    0, 0, 0, 0},
    {41, "MPEG1_ps",    5, "PS",    0, 0, 0, 0},
    {42, "MPEG2_ps",    5, "PS",    0, 0, 0, 0},
    {43, "EVD_ps",      5, "PS",    0, 0, 0, 0},
    {44, "MXF",         6, "MUX",   0, 0, 0, 0}
  };

  n = sizeof (ocodec) / sizeof (ecodec);
  if (wcodec) {
    for (i = 0; i < n; i ++) {
      wcodec [i] = (ecodec *) malloc (sizeof (ecodec));
      wcodec [i]->codec_code = ocodec [i].codec_code;
      memset (wcodec [i]->code_name, 0, 16);
      memcpy (wcodec [i]->code_name, ocodec [i].code_name, strlen (ocodec [i].code_name));
      wcodec [i]->codec_type = ocodec [i].codec_type;
      memset (wcodec [i]->type_name, 0, 16);
      memcpy (wcodec [i]->type_name, ocodec [i].type_name, strlen (ocodec [i].type_name));
    }
  }
  return n;
}
