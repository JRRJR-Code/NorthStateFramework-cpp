// Copyright 2004-2016, North State Software, LLC.  All rights reserved.

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#ifndef NSF_OS_SIGNAL_POSIX_H
#define NSF_OS_SIGNAL_POSIX_H

#include "NSFOSSignal.h"
#include <semaphore.h>

namespace NorthStateFramework
{
    /// <summary>
    /// Represents an operating system signal in the POSIX environment
    /// </summary>
    class NSFOSSignal_POSIX : public NSFOSSignal
    {
    public:

        /// <summary>
        /// Creates an operating system signal in the POSIX environment.
        /// </summary>
        /// <param name="name">The name of the signal.</param>
        NSFOSSignal_POSIX(const NSFString& name);

        /// <summary>
        /// Destroys an operating system signal in the POSIX environment.
        /// </summary>
        ~NSFOSSignal_POSIX();

        void clear();

        void send();

        bool wait();

        bool wait(Int32 timeout);

    private:

        sem_t signalSemaphore;
    };
}

#endif // NSF_OS_SIGNAL_POSIX_H

