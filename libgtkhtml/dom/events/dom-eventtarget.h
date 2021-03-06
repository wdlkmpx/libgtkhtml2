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

#ifndef __DOM_EVENTTARGET_H__
#define __DOM_EVENTTARGET_H__

typedef struct _DomEventTarget DomEventTarget;
typedef struct _DomEventTargetIface DomEventTargetIface;

#include <glib-object.h>

#include "dom-eventlistener.h"

#define DOM_TYPE_EVENT_TARGET             (dom_event_target_get_type ())
#define DOM_EVENT_TARGET(object)          (G_TYPE_CHECK_INSTANCE_CAST ((object), DOM_TYPE_EVENT_TARGET, DomEventTarget))
#define DOM_EVENT_TARGET_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DOM_TYPE_EVENT_TARGET, DomEventTargetClass))
#define DOM_IS_EVENT_TARGET(object)       (G_TYPE_CHECK_INSTANCE_TYPE ((object),  DOM_TYPE_EVENT_TARGET))
#define DOM_IS_EVENT_TARGET_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DOM_TYPE_EVENT_TARGET))
#define DOM_EVENT_TARGET_GET_IFACE(obj)  ((DomEventTargetIface *)g_type_interface_peek (((GTypeInstance *)DOM_EVENT_TARGET (obj))->g_class, DOM_TYPE_EVENT_TARGET))

struct _DomEventTargetIface {
	GTypeInterface g_iface;

	void (* addEventListener) (DomEventTarget *target, const DomString *type, DomEventListener *listener, DomBoolean useCapture);
	void (* removeEventListener) (DomEventTarget *target, const DomString *type, DomEventListener *listener, DomBoolean useCapture);
	DomBoolean (* dispatchEvent) (DomEventTarget *target, DomEvent *event);
};

GType dom_event_target_get_type (void);

void dom_EventTarget_addEventListener (DomEventTarget *target, const DomString *type, DomEventListener *listener, DomBoolean useCapture);
void dom_EventTarget_removeEventListener (DomEventTarget *target, const DomString *type, DomEventListener *listener, DomBoolean useCapture);
DomBoolean dom_EventTarget_dispatchEvent (DomEventTarget *target, DomEvent *event, DomException *exc);


#endif /* __DOM_EVENTTARGET_H__ */
