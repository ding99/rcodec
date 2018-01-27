/***************************************************************************
 * codec_code:                                                             *
 * 0-unknown,                                                              *
 * 1-MPEG1_video, 2-MPEG2_video, 3-MPEG4_video, 4-MPEG4_AVC, 5-VC1, 6-AVS, *
 * 10-LPCM_wav, 19-LPCM_aiff,                                              *
 * 11-MPEG1_audio, 12-MPEG2_audio, 13-MPEG4_auduo, 14-MPEG4HE_AAC, 15-mp3, *
 * 16-AVS_s_audio, 17-AVS_t_audio                                          *
 * 20-MLP, 21-AC3, 22-DDPlus, 23-DTS, 24-WMAPro,                           *
 * 30-ASF, 31-AVI, 32-ASF_wmv, 33-ASF_wma, 34-MKV, 35-MOV, 36-RM, 37-FLV   *
 * 38-CDXA,                                                                *
 * 40-MPEG2_ts, 41-MPEG1_ps, 42-MPEG2_ps, 43-EVD_ps, 44-MXF                *
 * 99-other.                                                               *
 *                                                                         *
 * codec_type                                                              *
 * 0-unknown, 1-video_es, 2-audio_es, 3-image, 4-ts, 5-ps, 6-mux, 99-other *
 ***************************************************************************/

struct ecodec {
  int codec_code;
  char code_name [16];
  int codec_type;
  char type_name [16];
  union {
    int profile;     /* for video */
    int channels;    /* for audio */
  };
  union {
    int level;       /* for video */
    int sampledepth; /* for audio */
  };
  union {
    int width;       /* for video */
    int samplerate;  /* for audio */
  };
  union {
    int height;      /* for video */
    int bitrate;     /* for audio */
  };
};
