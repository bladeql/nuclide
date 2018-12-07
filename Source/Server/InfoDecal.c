/*
	Copyright 2016-2018 Marco "eukara" Hladik
	
	MIT LICENSE

	Permission is hereby granted, free of charge, to any person 
	obtaining a copy of this software and associated documentation 
	files (the "Software"), to deal in the Software without 
	restriction, including without limitation the rights to use,
	copy, modify, merge, publish, distribute, sublicense, and/or
	sell copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
	OTHER DEALINGS IN THE SOFTWARE.
*/

/* decal name */
.string texture;

/* We need to save trace infos temporarily in order to figure out what to
 * project the decal against. Half-Life's infodecal entity only stores origin,
 * but not angles. So we have to figure them out ourselves. */
typedef struct {
	float fraction;
	vector normal;
	vector endpos;
} traced_t;

float infodecal_send(entity pvsent, float cflags)
{
	WriteByte(MSG_ENTITY, ENT_DECAL);
	WriteCoord(MSG_ENTITY, self.origin[0]);
	WriteCoord(MSG_ENTITY, self.origin[1]);
	WriteCoord(MSG_ENTITY, self.origin[2]);
	WriteCoord(MSG_ENTITY, self.angles[0]);
	WriteCoord(MSG_ENTITY, self.angles[1]);
	WriteCoord(MSG_ENTITY, self.angles[2]);
	/* Figure this thing out */
	WriteByte(MSG_ENTITY, 255);
	WriteByte(MSG_ENTITY, 0);
	WriteByte(MSG_ENTITY, 0);
	WriteString(MSG_ENTITY, self.texture );
	return TRUE;
}

void infodecal(void)
{
	traced_t tmp[6];
	int i = 0;
	int b = 0;
	float frac = 1.0f;
	vector vpos = self.origin;

	/* Unrolled because I'm lazy */
	makevectors([0, 0, 0]);
	traceline(vpos + (v_forward * -1), vpos + (v_forward * 128), 1, self);
	tmp[0].fraction = trace_fraction;
	tmp[0].normal = trace_plane_normal;
	tmp[0].endpos = trace_endpos;
	traceline(vpos + (v_forward * 1), vpos + (v_forward * -128), 1, self);
	tmp[1].fraction = trace_fraction;
	tmp[1].normal = trace_plane_normal;
	tmp[1].endpos = trace_endpos;
	traceline(vpos + (v_right * -1), vpos + (v_right * 128), 1, self);
	tmp[2].fraction = trace_fraction;
	tmp[2].normal = trace_plane_normal;
	tmp[2].endpos = trace_endpos;
	traceline(vpos + (v_right * 1), vpos + (v_right * -128), 1, self);
	tmp[3].fraction = trace_fraction;
	tmp[3].normal = trace_plane_normal;
	tmp[3].endpos = trace_endpos;
	traceline(vpos + (v_up * -1), vpos + (v_up * 128), 1, self);
	tmp[4].fraction = trace_fraction;
	tmp[4].normal = trace_plane_normal;
	tmp[4].endpos = trace_endpos;
	traceline(vpos + (v_up * 1), vpos + (v_up * -128), 1, self);
	tmp[5].fraction = trace_fraction;
	tmp[5].normal = trace_plane_normal;
	tmp[5].endpos = trace_endpos;

	for (i = 0; i < 6; i++) {
		if ( tmp[i].fraction < frac ) {
			frac = tmp[i].fraction;
			b = i;
		}
	}

	if (frac == 1.0f) {
		objerror(sprintf("infodecal tracing failed at %v\n", self.origin));
		return;
	}

	makevectors(vectoangles(tmp[b].endpos - self.origin ));
	vector cpl = v_forward - (v_forward * tmp[b].normal) * tmp[b].normal;

	if (tmp[b].normal[2] == 0) {
		cpl = [0, 0, 1];
	}

	self.angles = vectoangles(cpl, tmp[b].normal);
	self.solid = SOLID_NOT;
	self.pvsflags = PVSF_NOREMOVE | PVSF_IGNOREPVS;
	self.SendEntity = infodecal_send;
	self.SendFlags = 1;
}
