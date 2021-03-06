/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
   Copyright (C) 2000 CodeFactory AB
   Copyright (C) 2000 Jonas Borgstr\366m <jonas@codefactory.se>
   Copyright (C) 2000 Anders Carlsson <andersca@codefactory.se>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef __HTML_IMAGE_H__
#define __HTML_IMAGE_H__

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gdk-pixbuf/gdk-pixbuf-loader.h>

#include "libgtkhtml/util/htmlstream.h"

G_BEGIN_DECLS

typedef struct _HtmlImage HtmlImage;
typedef struct _HtmlImageClass HtmlImageClass;

#define HTML_IMAGE_TYPE (html_image_get_type ())
#define HTML_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), HTML_IMAGE_TYPE, HtmlImage))
#define HTML_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), HTML_IMAGE_TYPE, HtmlImageClass))
#define HTML_IMAGE_GET_CLASS(klass) (G_TYPE_INSTANCE_GET_CLASS ((klass), HTML_IMAGE_TYPE, HtmlImageClass))

struct _HtmlImage {
	GObject parent;

	GdkPixbuf *pixbuf;

	gchar *uri;
	gboolean broken;
	gboolean loading;

	HtmlStream *stream;

	GdkPixbufLoader *loader;
};

struct _HtmlImageClass {
	GObjectClass parent_class;

	void (* last_unref) (HtmlImage *image);
	
	void (* repaint_image) (HtmlImage *image, gint x, gint y, gint width, gint height);
	void (* resize_image) (HtmlImage *image);
};

GType html_image_get_type (void);

gint html_image_get_width (HtmlImage *image);
gint html_image_get_height (HtmlImage *image);

G_END_DECLS

#endif /* __HTML_IMAGE_H__ */
