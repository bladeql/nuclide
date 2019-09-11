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

/*
=================
Input_Handle

Handles impulse and whatnot
=================
*/
void Game_Input(void)
{
	if (input_buttons & INPUT_BUTTON0) {
		Weapons_Primary();
	} else if (input_buttons & INPUT_BUTTON4) {
		Weapons_Reload();
	} else if (input_buttons & INPUT_BUTTON3) {
		Weapons_Secondary();
	} else {
		Weapons_Release();
	}

	if (input_buttons & INPUT_BUTTON5) {
		Player_UseDown(); 
	} else {
		Player_UseUp();
	}

	if (self.impulse == 100) {
		Flashlight_Toggle();
	}

	if (cvar("sv_cheats") == 1) {
		player pl = (player)self;
		if (self.impulse == 101) {
			pl.health = 100;
			pl.armor = 100;
			Weapons_AddItem(pl, WEAPON_CROWBAR);
			Weapons_AddItem(pl, WEAPON_MEDKIT);
			Weapons_AddItem(pl, WEAPON_KNIFE);
			Weapons_AddItem(pl, WEAPON_WRENCH);
			Weapons_AddItem(pl, WEAPON_UMBRELLA);
			Weapons_AddItem(pl, WEAPON_SBS);
			Weapons_AddItem(pl, WEAPON_SNIPER);
			Weapons_AddItem(pl, WEAPON_TRANQUIL);
			Weapons_AddItem(pl, WEAPON_RAILGUN);
			Weapons_AddItem(pl, WEAPON_AUTORIFLE);
			Weapons_AddItem(pl, WEAPON_DBS);
			Weapons_AddItem(pl, WEAPON_NAILGUN);
			Weapons_AddItem(pl, WEAPON_GLAUNCHER);
			Weapons_AddItem(pl, WEAPON_SUPERNAIL);
			Weapons_AddItem(pl, WEAPON_FLAMER);
			Weapons_AddItem(pl, WEAPON_RPG);
			Weapons_AddItem(pl, WEAPON_PIPEBOMB);
			Weapons_AddItem(pl, WEAPON_ASSCAN);
			Weapons_AddItem(pl, WEAPON_INCENDIARY);
		}

		if (self.impulse == 102) {
			// Respawn all the entities
			for (entity a = world; (a = findfloat(a, gflags, GF_CANRESPAWN));) {
				CBaseEntity caw = (CBaseEntity)a;
				caw.Respawn();
			}
			bprint(PRINT_HIGH, "Respawning all map entities...\n");
		}
	}

	self.impulse = 0;
}
