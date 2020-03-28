/*
 * Copyright (c) 2016-2019 Marco Hladik <marco@icculus.org>
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

float(entity foo, float chanid) getchannellevel = #0;


/*
=================
Client_Init

Comparable to worldspawn in SSQC in that it's mostly used for precaches
=================
*/
void Client_Init(float apilevel, string enginename, float engineversion)
{
	precache_model("sprites/640hud1.spr");
	precache_model("sprites/640hud2.spr");
	precache_model("sprites/640hud3.spr");
	precache_model("sprites/640hud4.spr");
	precache_model("sprites/640hud5.spr");
	precache_model("sprites/640hud6.spr");
	precache_model("sprites/640hud7.spr");
	precache_model("sprites/640hud10.spr");
	precache_model("sprites/640hud11.spr");
	precache_model("sprites/640hud12.spr");
	precache_model("sprites/640hud13.spr");
	precache_model("sprites/640hud14.spr");
	precache_model("sprites/640hud15.spr");
	precache_model("sprites/640hud16.spr");
	precache_model("sprites/hud640_01.spr");
	precache_model("sprites/hud640_02.spr");
	precache_model("sprites/hud640_04.spr");
	precache_model("sprites/bottom.spr");
	precache_model("sprites/bottom_left.spr");
	precache_model("sprites/bottom_right.spr");
	precache_model("sprites/left.spr");
	precache_model("sprites/radar640.spr");
	precache_model("sprites/right.spr");
	precache_model("sprites/sniper_scope.spr");
	precache_model("sprites/top.spr");
	precache_model("sprites/top_left.spr");
	precache_model("sprites/top_right.spr");

	BEAM_TRIPMINE = particleeffectnum("beam_tripmine");
}

void Client_InitDone(void)
{
	/* change this to the motd */
	//VGUI_ChooseTeam();
}

void Game_RendererRestarted(string rstr)
{
}
