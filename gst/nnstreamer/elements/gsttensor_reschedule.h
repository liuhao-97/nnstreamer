/**
 * GStreamer
 * Copyright (C) 2005 Thomas Vander Stichele <thomas@apestaart.org>
 * Copyright (C) 2005 Ronald S. Bultje <rbultje@ronald.bitfreak.net>
 * Copyright (C) 2018 Samsung Electronics Co., Ltd.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation;
 * version 2.1 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 */

/**
 * @file	gsttensor_reschedule.h
 * @date	29 August 2018
 * @brief	GStreamer plugin to aggregate tensor stream
 * @see		https://github.com/nnstreamer/nnstreamer
 * @author	Jaeyun Jung <jy1210.jung@samsung.com>
 * @bug		No known bugs except for NYI items
 */

#ifndef __GST_TENSOR_RESCHEDULE_H__
#define __GST_TENSOR_RESCHEDULE_H__

#include <gst/gst.h>
#include <tensor_common.h>

G_BEGIN_DECLS

#define GST_TYPE_TENSOR_RESCHEDULE \
  (gst_tensor_reschedule_get_type())
#define GST_TENSOR_RESCHEDULE(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_TENSOR_RESCHEDULE,GstTensorReschedule))
#define GST_TENSOR_RESCHEDULE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_TENSOR_RESCHEDULE,GstTensorRescheduleClass))
#define GST_IS_TENSOR_RESCHEDULE(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_TENSOR_RESCHEDULE))
#define GST_IS_TENSOR_RESCHEDULE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_TENSOR_RESCHEDULE))

typedef struct _GstTensorReschedule GstTensorReschedule;
typedef struct _GstTensorRescheduleClass GstTensorRescheduleClass;

/**
 * @brief GstTensorReschedule data structure.
 */
struct _GstTensorReschedule
{
  GstElement element; /**< parent object */

  GstPad *sinkpad; /**< sink pad */
  GstPad *srcpad; /**< src pad */

  gboolean silent; /**< true to print minimized log */
  gboolean concat; /**< true to concatenate output buffer */
  guint frames_in; /**< number of frames in input buffer */
  guint frames_out; /**< number of frames in output buffer */
  guint frames_flush; /**< number of frames to flush */
  guint frames_dim; /**< index of frames in tensor dimension */

  GHashTable *adapter_table; /**< adapt incoming tensor */

  gboolean tensor_configured; /**< True if already successfully configured tensor metadata */
  GstTensorsConfig in_config; /**< input tensor info */
  GstTensorsConfig out_config; /**< output tensor info */
};

/**
 * @brief GstTensorRescheduleClass data structure.
 */
struct _GstTensorRescheduleClass
{
  GstElementClass parent_class; /**< parent class */
};

/**
 * @brief Function to get type of tensor_reschedule.
 */
GType gst_tensor_reschedule_get_type (void);

G_END_DECLS

#endif /** __GST_TENSOR_RESCHEDULE_H__ */
