#pragma once

extern "C" {
#include <libavutil/frame.h>
#include <libavutil/mem.h>
#include <libavcodec/avcodec.h>
#include <libavutil/timestamp.h>
#include <libavformat/avformat.h>
}

class FfmpegHandler
{
public:
    FfmpegHandler();

private:
    int cutVideo(double from_seconds, double end_seconds, const char* in_filename, const char* out_filename);
    static void logPacket(const AVFormatContext *fmt_ctx, const AVPacket *pkt, const char *tag);
};
