#pragma once

/*
foldtree.hpp

Поиск каталога по Alt-F10
*/
/*
Copyright (c) 1996 Eugene Roshal
Copyright (c) 2000 Far Group
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the authors may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "frame.hpp"
#include "keybar.hpp"
#include "chgmmode.hpp"

class TreeList;
class Edit;
class SaveScreen;

class FolderTree : public Frame
{
private:
	ChangeMacroMode CMM;
	TreeList *Tree;
	Edit *FindEdit;

	KeyBar TreeKeyBar;	// кейбар
	int ModalMode;
	int IsFullScreen;
	int IsStandalone;

	FARString strNewFolder;
	FARString strLastName;

private:
	void DrawEdit();
	virtual void DisplayObject();
	void SetCoords();

public:
	static void
	Present(FARString &strResultFolder, int ModalMode, int IsStandalone = TRUE, int IsFullScreen = TRUE);

	FolderTree(FARString &strResultFolder, int ModalMode, int IsStandalone = TRUE, int IsFullScreen = TRUE);
	virtual ~FolderTree();

public:
	virtual int ProcessKey(int Key);
	virtual int ProcessMouse(MOUSE_EVENT_RECORD *MouseEvent);

	virtual void InitKeyBar();
	virtual void OnChangeFocus(int focus);	// вызывается при смене фокуса
	virtual void SetScreenPosition();
	virtual void ResizeConsole();
	/* $ Введена для нужд CtrlAltShift OT */
	virtual int FastHide();

	virtual const wchar_t *GetTypeName() { return L"[FolderTree]"; }
	virtual int GetTypeAndName(FARString &strType, FARString &strName);
	virtual int GetType() { return MODALTYPE_FINDFOLDER; }
};
