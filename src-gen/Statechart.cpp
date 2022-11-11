/** Generated by YAKINDU Statechart Tools code generator. */

#include "Statechart.h"

/*! \file
Implementation of the state machine 'Statechart'
*/




Statechart::Statechart() :
	viMyCounter(0),
	timerService(sc_null),
	isExecuting(false)
{
	for (sc_ushort state_vec_pos = 0; state_vec_pos < maxOrthogonalStates; ++state_vec_pos)
		stateConfVector[state_vec_pos] = Statechart_last_state;
	
	clearInEvents();
}

Statechart::~Statechart()
{
}


using namespace statechart_events;

SctEvent* Statechart::getNextEvent()
{
	SctEvent* nextEvent = 0;
	
	if(!inEventQueue.empty()) {
		nextEvent = inEventQueue.front();
		inEventQueue.pop_front();
	}
	
	return nextEvent;
}

void Statechart::dispatch_event(SctEvent * event)
{
	if(event == 0) {
		return;
	}
	switch(event->name)
	{
		case Statechart_Toggle_Toggle_time_event_0:
		{
			timeEvents[0] = true;
			break;
		}
		default:
			/* do nothing */
			break;
	}
	delete event;
}

void Statechart::iface_dispatch_event(SctEvent * event)
{
	switch(event->name)
	{
		default:
			/* do nothing */
			break;
	}
}
void Statechart::internal_dispatch_event(SctEvent * event)
{
	switch(event->name)
	{
		default:
			/* do nothing */
			break;
	}
}

StatechartEventName Statechart::getTimedEventName(sc_eventid evid)
{
	if (evid == (sc_eventid)(&timeEvents[0])) {
		return Statechart_Toggle_Toggle_time_event_0;
	}
	return invalid_event;
}



sc_boolean Statechart::isActive() const
{
	return stateConfVector[0] != Statechart_last_state;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean Statechart::isFinal() const
{
   return false;}

sc_boolean Statechart::check() {
	if(timerService == sc_null) {
		return false;
	}
	return true;
}


void Statechart::setTimerService(sc::timer::TimerServiceInterface* timerService_)
{
	this->timerService = timerService_;
}

sc::timer::TimerServiceInterface* Statechart::getTimerService()
{
	return timerService;
}

sc_integer Statechart::getNumberOfParallelTimeEvents() {
	return parallelTimeEventsCount;
}

void Statechart::raiseTimeEvent(sc_eventid evid)
{
	if ((evid >= (sc_eventid)timeEvents) && (evid < (sc_eventid)(&timeEvents[timeEventsCount])))
	{
		inEventQueue.push_back(new TimedSctEvent(getTimedEventName(evid)));
		runCycle();
	}
}


sc_boolean Statechart::isStateActive(StatechartStates state) const
{
	switch (state)
	{
		case Toggle_Toggle :
		{
			return (sc_boolean) (stateConfVector[SCVI_TOGGLE_TOGGLE] == Toggle_Toggle);
			break;
		}
		default:
		{
			/* State is not active*/
			return false;
			break;
		}
	}
}


// implementations of all internal functions
/* Entry action for state 'Toggle'. */
void Statechart::enact_Toggle_Toggle()
{
	/* Entry action for state 'Toggle'. */
	timerService->setTimer(this, (sc_eventid)(&timeEvents[0]), 1000, false);
	opLedUpdate();
	viMyCounter++;
}

/* Exit action for state 'Toggle'. */
void Statechart::exact_Toggle_Toggle()
{
	/* Exit action for state 'Toggle'. */
	timerService->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
}

/* 'default' enter sequence for state Toggle */
void Statechart::enseq_Toggle_Toggle_default()
{
	/* 'default' enter sequence for state Toggle */
	enact_Toggle_Toggle();
	stateConfVector[0] = Toggle_Toggle;
}

/* 'default' enter sequence for region Toggle */
void Statechart::enseq_Toggle_default()
{
	/* 'default' enter sequence for region Toggle */
	react_Toggle__entry_Default();
}

/* Default exit sequence for state Toggle */
void Statechart::exseq_Toggle_Toggle()
{
	/* Default exit sequence for state Toggle */
	stateConfVector[0] = Statechart_last_state;
	exact_Toggle_Toggle();
}

/* Default exit sequence for region Toggle */
void Statechart::exseq_Toggle()
{
	/* Default exit sequence for region Toggle */
	/* Handle exit of all possible states (of Statechart.Toggle) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case Toggle_Toggle :
		{
			exseq_Toggle_Toggle();
			break;
		}
		default:
			/* do nothing */
			break;
	}
}

/* Default react sequence for initial entry  */
void Statechart::react_Toggle__entry_Default()
{
	/* Default react sequence for initial entry  */
	opLedInit();
	viMyCounter = 0;
	enseq_Toggle_Toggle_default();
}

sc_integer Statechart::react(const sc_integer transitioned_before) {
	/* State machine reactions. */
	return transitioned_before;
}

sc_integer Statechart::Toggle_Toggle_react(const sc_integer transitioned_before) {
	/* The reactions of state Toggle. */
	sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (timeEvents[0])
		{ 
			exseq_Toggle_Toggle();
			timeEvents[0] = false;
			enseq_Toggle_Toggle_default();
			react(0);
			transitioned_after = 0;
		} 
	} 
	/* If no transition was taken then execute local reactions */
	if ((transitioned_after) == (transitioned_before))
	{ 
		transitioned_after = react(transitioned_before);
	} 
	return transitioned_after;
}

void Statechart::clearInEvents() {
	timeEvents[0] = false;
}

void Statechart::microStep() {
	switch(stateConfVector[ 0 ])
	{
		case Toggle_Toggle :
		{
			Toggle_Toggle_react(-1);
			break;
		}
		default:
			/* do nothing */
			break;
	}
}

void Statechart::runCycle() {
	/* Performs a 'run to completion' step. */
	if (isExecuting)
	{ 
		return;
	} 
	isExecuting = true;
	dispatch_event(getNextEvent());
	do
	{ 
		microStep();
		clearInEvents();
		dispatch_event(getNextEvent());
	} while (timeEvents[0]);
	isExecuting = false;
}

void Statechart::enter() {
	/* Activates the state machine. */
	if (isExecuting)
	{ 
		return;
	} 
	isExecuting = true;
	/* Default enter sequence for statechart Statechart */
	enseq_Toggle_default();
	isExecuting = false;
}

void Statechart::exit() {
	/* Deactivates the state machine. */
	if (isExecuting)
	{ 
		return;
	} 
	isExecuting = true;
	/* Default exit sequence for statechart Statechart */
	exseq_Toggle();
	isExecuting = false;
}

/* Can be used by the client code to trigger a run to completion step without raising an event. */
void Statechart::triggerWithoutEvent() {
	runCycle();
}

