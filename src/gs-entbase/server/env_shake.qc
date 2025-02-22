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

#define EVS_GLOBAL 1

/*!QUAKED env_shake (1 .5 0) (-8 -8 -8) (8 8 8) EVS_GLOBAL
# OVERVIEW
Causes an earthquake/shaking effect when triggered.

# KEYS
- "targetname" : Name
- "target" : Target when triggered.
- "killtarget" : Target to kill when triggered.
- "radius" : Radius of the quake/shake effect.
- "amplitude" : Amplitude of the effect.
- "duration" : Duration of the effect in seconds.
- "frequency" : The frequency of the shake.

# SPAWNFLAGS
- EVS_GLOBAL : Affect all clients, ignoring "radius" entirely.

# TRIVIA
This entity was introduced in Half-Life (1998).
*/
class
env_shake:NSPointTrigger
{
	float m_flRadius;
	float m_flAmplitude;
	float m_flDuration;
	float m_flFrequency;

public:
	void env_shake(void);
	
	virtual void Save(float);
	virtual void Restore(string,string);
	virtual void SpawnKey(string,string);
	virtual void Trigger(entity, triggermode_t);

};

void
env_shake::env_shake(void)
{
	m_flRadius = 0.0f;
	m_flAmplitude = 0.0f;
	m_flDuration = 0.0f;
	m_flFrequency = 0.0f;
}

void
env_shake::Save(float handle)
{
	super::Save(handle);
	SaveFloat(handle, "m_flRadius", m_flRadius);
	SaveFloat(handle, "m_flAmplitude", m_flAmplitude);
	SaveFloat(handle, "m_flDuration", m_flDuration);
	SaveFloat(handle, "m_flFrequency", m_flFrequency);
}

void
env_shake::Restore(string strKey, string strValue)
{
	switch (strKey) {
	case "m_flRadius":
		m_flRadius = ReadFloat(strValue);
		break;
	case "m_flAmplitude":
		m_flAmplitude = ReadFloat(strValue);
		break;
	case "m_flDuration":
		m_flDuration = ReadFloat(strValue);
		break;
	case "m_flFrequency":
		m_flFrequency = ReadFloat(strValue);
		break;
	default:
		super::Restore(strKey, strValue);
	}
}

void
env_shake::SpawnKey(string strKey, string strValue)
{
	switch (strKey) {
	case "radius":
		m_flRadius = stof(strValue);
		break;
	case "amplitude":
		m_flAmplitude = stof(strValue);
		break;
	case "duration":
		m_flDuration = stof(strValue);
		break;
	case "frequency":
		m_flFrequency = stof(strValue);
		break;
	default:
		super::SpawnKey(strKey, strValue);
	}
}

void
env_shake::Trigger(entity act, triggermode_t state)
{
	Client_ShakeOnce(origin, m_flRadius, m_flDuration, m_flFrequency, m_flAmplitude);
}
