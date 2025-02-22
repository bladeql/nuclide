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

void
NSClient::NSClient(void)
{
	customphysics = Empty; /* we don't want any engine physics to run on clients, ever. */
	flags |= FL_CLIENT;
	XR_Init(this);
}

#ifdef SERVER
void
NSClient::Save(float handle)
{
	super::Save(handle);
}

void
NSClient::Restore(string strKey, string strValue)
{
	switch (strKey) {
	default:
		super::Restore(strKey, strValue);
	}
}

void
NSClient::ServerInputFrame(void)
{
}

void
NSClient::SetInfoKey(string strKey, string strValue)
{
	forceinfokey(this, strKey, strValue);
}

string
NSClient::GetInfoKey(string strKey)
{
	return infokey(this, strKey);
}

#endif

void
NSClient::SharedInputFrame(void)
{

}

void
NSClient::OnRemoveEntity(void)
{
	XR_Shutdown(this);
}

void
NSClient::ProcessInput(void)
{
}

void
NSClient::PreFrame(void)
{
}

void
NSClient::PostFrame(void)
{
}

bool
NSClient::IsFakeSpectator(void)
{
	return (false);
}

bool
NSClient::IsRealSpectator(void)
{
	return (false);
}

bool
NSClient::IsDead(void)
{
	return (false);
}

bool
NSClient::IsPlayer(void)
{
	return (false);
}

#ifdef CLIENT
void
NSClient::ClientInputFrame(void)
{
}

void
NSClient::UpdateAliveCam(void)
{
	g_view.SetCameraOrigin(GetEyePos());
	g_view.SetCameraAngle(view_angles);
}

void
NSClient::UpdateDeathcam(void)
{
	/* death cam */
	view_angles[2] = 45.0f;

	g_view.SetCameraOrigin(GetEyePos());
	g_view.SetCameraAngle(view_angles);
}

void
NSClient::UpdateIntermissionCam(void)
{
	view_angles = pSeat->m_vecCameraAngle;
	view_angles += [sin(time), sin(time * 1.5f)] * 0.1f;
	g_view.SetCameraOrigin(pSeat->m_vecCameraOrigin);
	g_view.SetCameraAngle(view_angles);
}

float
NSClient::predraw(void)
{
	return (PREDRAW_NEXT);
}
#endif

float
Client_InIntermission(void)
{
#ifdef CLIENT
	return g_iIntermission;
#else
	return (float)g_grMode.InIntermission();
#endif
}
