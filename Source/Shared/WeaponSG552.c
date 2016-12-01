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

.int iClip_SG552;

// Weapon Info
weaponinfo_t wptSG552 = { 
	WEAPON_SG552, 		// Identifier
	SLOT_PRIMARY,
	3500, 				// Price
	CALIBER_556MM, 		// Caliber ID
	235, 				// Max Player Speed
	1, 					// Bullets Per Shot
	30, 				// Clip/MagSize
	33, 				// Damage Per Bullet
	2, 					// Penetration Multiplier
	8192, 				// Bullet Range
	0.955, 				// Range Modifier
	TYPE_AUTO,
	0.09, 				// Attack-Delay
	3.0, 				// Reload-Delay
	iAmmo_556MM, 		// Caliber Pointer
	iClip_SG552 		// Clip Pointer
};

// Anim Table
enum {
	ANIM_SG552_IDLE,
	ANIM_SG552_RELOAD,
	ANIM_SG552_DRAW,
	ANIM_SG552_SHOOT1,
	ANIM_SG552_SHOOT2,
	ANIM_SG552_SHOOT3
};

void WeaponSG552_Draw( void ) {
	#ifdef QWSSQC
	OpenCSGunBase_Draw();
	sound( self, CHAN_WEAPON, "weapons/sg552_boltpull.wav", 1, ATTN_IDLE ); // TODO: Move to the client...?
	#else
	View_PlayAnimation( ANIM_SG552_DRAW );
	#endif
}

void WeaponSG552_PrimaryFire( void ) {
	#ifdef QWSSQC
	if ( OpenCSGunBase_PrimaryFire() == TRUE ) {
		if ( random() <= 0.5 ) {
			sound( self, CHAN_WEAPON, "weapons/sg552-1.wav", 1, ATTN_NORM );
		} else {
			sound( self, CHAN_WEAPON, "weapons/sg552-2.wav", 1, ATTN_NORM );
		}
	}
	#else
	int iRand = ceil( random() * 3 );
	if ( iRand == 1 ) {
		View_PlayAnimation( ANIM_SG552_SHOOT1 );
	} else if ( iRand == 2 ) {
		View_PlayAnimation( ANIM_SG552_SHOOT2 );
	} else {
		View_PlayAnimation( ANIM_SG552_SHOOT3 );
	}
	#endif
}

void WeaponSG552_Reload( void ) {
	#ifdef QWSSQC
	if ( OpenCSGunBase_Reload() == TRUE ) {
		// Play Sound
	}
	#else
	View_PlayAnimation( ANIM_SG552_RELOAD );
	#endif
}
