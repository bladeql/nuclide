/*
 * Copyright (c) 2016-2020 Marco Hladik <marco@icculus.org>
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
void
Client_Init(float apilevel, string enginename, float engineversion)
{
}

void
Client_InitDone(void)
{
	VGUI_ChooseTeam();
}

void
Game_RendererRestarted(string rstr)
{
	FX_Blood_Init();
	FX_BreakModel_Init();
	FX_Explosion_Init();
	FX_GibHuman_Init();
	FX_Spark_Init();
	FX_Impact_Init();

	precache_model("sprites/640hud1.spr");
	precache_model("sprites/640hud2.spr");
	precache_model("sprites/640hud3.spr");
	precache_model("sprites/640hud4.spr");
	precache_model("sprites/640hud5.spr");
	precache_model("sprites/640hud6.spr");

	precache_model("sprites/tfc_dmsg.spr");
	precache_model("sprites/tfchud01.spr");
	precache_model("sprites/tfchud02.spr");
	precache_model("sprites/tfchud03.spr");
	precache_model("sprites/tfchud04.spr");
	precache_model("sprites/tfchud05.spr");
	precache_model("sprites/tfchud06.spr");
	precache_model("sprites/tfchud07.spr");

	precache_model("sprites/chainsaw.spr");
	precache_model("sprites/hammer.spr");
	precache_model("sprites/w_cannon.spr");

	BEAM_TRIPMINE = particleeffectnum("weapon_tripmine.beam");
}
