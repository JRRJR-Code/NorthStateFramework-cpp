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

#ifndef STATE_MACHINE_RESTART_TEST_H
#define STATE_MACHINE_RESTART_TEST_H

#include "TestHarness.h"
#include "TestInterface.h"

using namespace NorthStateFramework;
using namespace std;

namespace NSFTest
{
    /// <summary>
    /// Test State Machine Restart
    /// </summary>
    class StateMachineRestartTest : public NSFStateMachine, public ITestInterface
    {
    public:
        StateMachineRestartTest(const NSFString& name);

        ~StateMachineRestartTest();

        const NSFString& getName() { return NSFStateMachine::getName();}

        bool runTest(NSFString& errorMessage);

    private:

        TestHarness testHarness;

        //Events
        NSFEvent event1;
        NSFEvent event2;

        // Regions and states, from outer to inner
        NSFInitialState initialState;
        NSFCompositeState state1;
        NSFCompositeState state2;
        NSFCompositeState state3;

        // Transitions, ordered internal, local, external
        NSFInternalTransition test1ReactionToEvent2;
        NSFInternalTransition state2ReactionToEvent1;
        NSFExternalTransition initialToState1Transition;
        NSFExternalTransition state1ToState2Transition;
        NSFExternalTransition state2ToState3Transition;
        NSFExternalTransition state3ToState2Transition;
        NSFExternalTransition state2ToState1Transition;

        void state2ReactionToEvent1Actions(const NSFStateMachineContext& context);
        void test1ReactionToEvent2Actions(const NSFStateMachineContext& context);
    };
}

#endif // STATE_MACHINE_RESTART_TEST_H