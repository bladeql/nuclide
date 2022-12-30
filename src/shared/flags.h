/*
 * Copyright (c) 2016-2022 Vera Visions LLC.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

/* engine reserved */
#define FL_FLY					(1<<0) /**< Entity is flying. */
#define FL_SWIM					(1<<1) /**< Entity is swimming. */
#define FL_GLIMPSE				(1<<2) /**< Unused? */
#define FL_CLIENT				(1<<3) /**< Entity is a client. */
#define FL_INWATER				(1<<4) /**< Entity is in water. */
#define FL_MONSTER				(1<<5) /**< Entity is a monster. */
#define FL_GODMODE				(1<<6) /**< Entity has 'god-mode' enabled. */
#define FL_NOTARGET				(1<<7) /**< Entity has `notarget` enabled. */
#define FL_ITEM					(1<<8) /**< Entity is an item. */
#define FL_ONGROUND				(1<<9) /**< Entity is standing on ground. */
#define FL_PARTIALGROUND		(1<<10) /**< Entity is (partially) on ground. */
#define FL_WATERJUMP			(1<<11) /**< Entity is within a water-jump moment. */
#define FL_JUMPRELEASED			(1<<12) /**< Entity has let go off the jump button. */
#define FL_FINDABLE_NONSOLID	(1<<14) /**< Entity is findable by find() calls, even when not-solid. */
#define FLQW_LAGGEDMOVE			(1<<16) /**< Entity will move with lag compenstation. */

/* nuclide */
#define FL_ONLADDER			(1<<13) /**< Entity is attached to a ladder. */
#define FL_CROUCHING		(1<<17) /**< Entity is crouching. */
#define FL_INVEHICLE		(1<<18) /**< Entity is inside a vehicle. */
#define FL_FROZEN			(1<<19) /**< Entity is not allowed to move. */
#define FL_USE_RELEASED		(1<<20) /**< Entity has release the +use button. */
#define FL_FAKESPEC			(1<<21) /**< Entity is a fake spectator. */
#define FL_ONUSABLE			(1<<22) /**< Entity is able to +use a thing. */
#define FL_ONFIRE			(1<<23) /**< Entity is on fire. */
#define FL_GOALITEM			(1<<15) /**< Entity is a goal-item. */
