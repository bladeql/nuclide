/*
OpenCS Project
Copyright (C) 2015 Marco "eukara" Hladik

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

.int iClip_SCOUT;

// Weapon Info
weaponinfo_t wptSCOUT = { 
	WEAPON_SCOUT, 		// Identifier
	SLOT_PRIMARY,
	2750, 				// Price
	CALIBER_762MM, 		// Caliber ID
	240, 				// Max Player Speed
	1, 					// Bullets Per Shot
	10, 				// Clip/MagSize
	75, 				// Damage Per Bullet
	3, 					// Penetration Multiplier
	8192, 				// Bullet Range
	0.98, 				// Range Modifier
	TYPE_AUTO,
	1.25, 				// Attack-Delay
	3.0, 				// Reload-Delay
	iAmmo_762MM, 		// Caliber Pointer
	iClip_SCOUT 		// Clip Pointer
};

// Anim Table
enum {
	ANIM_SCOUT_IDLE,
	ANIM_SCOUT_SHOOT1,
	ANIM_SCOUT_SHOOT2,
	ANIM_SCOUT_RELOAD,
	ANIM_SCOUT_DRAW
};

void WeaponSCOUT_Draw( void ) {
#ifdef QWSSQC
	OpenCSGunBase_Draw();
	sound( self, CHAN_WEAPON, "weapons/scout_bolt.wav", 1, ATTN_IDLE ); // TODO: Move to the client...?
#else
	View_PlayAnimation( ANIM_SCOUT_DRAW );
#endif
}

void WeaponSCOUT_PrimaryFire( void ) {
#ifdef QWSSQC
	if ( OpenCSGunBase_PrimaryFire() == TRUE ) {
		// Play Sound
		sound( self, CHAN_WEAPON, "weapons/scout_fire-1.wav", 1, ATTN_NORM );
	}
#else
	if ( random() <= 0.5 ) {
		View_PlayAnimation( ANIM_SCOUT_SHOOT1 );
	} else {
		View_PlayAnimation( ANIM_SCOUT_SHOOT2 );
	}
#endif
}

void WeaponSCOUT_Reload( void ) {
#ifdef QWSSQC
	if ( OpenCSGunBase_Reload() == TRUE ) {
		// Play Sound
	}
#else
	View_PlayAnimation( ANIM_SCOUT_RELOAD );
#endif
}
