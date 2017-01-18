/* -*-mode:c++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#ifndef CAMERA_HH
#define CAMERA_HH

#include <linux/videodev2.h>

#include "optional.hh"
#include "file_descriptor.hh"
#include "mmap_region.hh"
#include "raster_handle.hh"
#include "frame_input.hh"

class Camera : public FrameInput
{
private:
  uint16_t width_;
  uint16_t height_;

  FileDescriptor camera_fd_;
  std::unique_ptr<MMap_Region> mmap_region_;

  v4l2_buffer buffer_info_;
  int type_;

public:
  Camera( const uint16_t width, const uint16_t height, const std::string device = "/dev/video0" );

  ~Camera();

  Optional<RasterHandle> get_next_frame() override;

  uint16_t display_width() { return width_; }
  uint16_t display_height() { return height_; }
};

#endif
