/**
 * File name: LgMainXWin.h
 * Project: Redkite (A small GUI toolkit)
 *
 * Copyright (C) 2019 Iurie Nistor 
 *
 * This file is part of Redkite.
 *
 * Redkite is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef RK_MAIN_IMPL_H
#define RK_MAIN_IMPL_H

#include "RkMain.h"

class RkWidget;

#ifdef RK_OS_WIN
class RkEventQueueWin;
#elif RK_OS_MAC
#else
class RkEventQueueX;
#endif // RK_WIN_OS

class LgMain::LgMainImpl
{
 public:

        LgMainImpl(LgMain *interface);
        LgMainImpl(LgMain *interface, int argc, char **argv);
	virtual ~LgMainImpl();
        LgMainImpl(const LgMainImpl &other) = delete;
        LgMainImpl& operator=(const LgMainImpl &other) = delete;
        LgMainImpl(LgMainImpl &&other) = delete;
        LgMainImpl& operator=(LgMainImpl &&other) = delete;
	bool setTopLevelWidget(RkWidget* widget);
        RkWidget* topLevelWidget(void);
        RkEventQueue* getEventQueue() const;
	int exec(bool block = true);

 private:
        RK_DECALRE_INTERFACE_PTR(LgMain);
        RkWidget* topWidget;
        std::unique_ptr<RkEventQueue> eventQueue;
};

#endif // RK_MAIN_IMPL_H
