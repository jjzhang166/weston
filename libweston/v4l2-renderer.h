/*
 * Copyright © 2014-2018 Renesas Electronics Corp.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Authors:
 *	Takanari Hayama <taki@igel.co.jp>
 */

#ifndef V4L2_RENDERER_H
#define V4L2_RENDERER_H

#include "config.h"

#include "compositor.h"

struct v4l2_bo_state {
	int dmafd;
	void *map;
	uint32_t stride;
};

struct v4l2_renderer_backend_config {
	char *device;
	int max_inputs;
	int max_compose;
	bool scaler_enable;
};

struct v4l2_renderer_config {
	char *device;
	char *device_module;
	bool gl_fallback;
	bool defer_attach;
	struct v4l2_renderer_backend_config backend;
};

struct gbm_device;

struct v4l2_renderer_interface {
	int (*init)(struct weston_compositor *ec, struct v4l2_renderer_config *config, int drm_fd, char *drm_fn, struct gbm_device *gbm);
	int (*output_create)(struct weston_output *output, struct v4l2_bo_state *bo_states, int count);
	void (*output_destroy)(struct weston_output *output);
	void (*set_output_buffer)(struct weston_output *output, int bo_index);
};

#endif /* !V4L2_RENDERER_H */
