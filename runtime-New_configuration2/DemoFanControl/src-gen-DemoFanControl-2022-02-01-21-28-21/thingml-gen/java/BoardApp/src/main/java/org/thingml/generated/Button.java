/**
 * File generated by the ThingML IDE
 * /!\Do not edit this file/!\
 * In case of a bug in the generated code,
 * please submit an issue on our GitHub
 **/

package org.thingml.generated;

import no.sintef.jasm.*;
import no.sintef.jasm.ext.*;

import org.thingml.generated.api.*;
import org.thingml.generated.messages.*;

import java.util.*;

/**
 * Definition for type : Button
 **/
public class Button extends Component implements IButton_clock_tic {

private boolean debug = false;
public boolean isDebug() {return debug;}
public void setDebug(boolean debug) {this.debug = debug;}
public String toString() {
String result = "instance " + getName() + "\n";
result += "\tPIN0 = " + Button_PIN0_var;
result += "";
return result;
}

public synchronized void ms25_tic_via_clock_tic(){
final Event _msg = ms25_ticType.instantiate();
_msg.setPort(clock_tic_port);
receive(_msg);
}

private void sendPress_via_toBoard(){
toBoard_port.send(pressType.instantiate());
}

private void sendRelease_via_toBoard(){
toBoard_port.send(releaseType.instantiate());
}

//Attributes
private short Button_PIN0_var;
//Ports
private Port toBoard_port;
private Port clock_tic_port;
//Message types
protected final Timer_startMessageType timer_startType = new Timer_startMessageType();
protected final Timer_cancelMessageType timer_cancelType = new Timer_cancelMessageType();
protected final Timer_timeoutMessageType timer_timeoutType = new Timer_timeoutMessageType();
protected final Ms25_ticMessageType ms25_ticType = new Ms25_ticMessageType();
protected final Ms500_ticMessageType ms500_ticType = new Ms500_ticMessageType();
protected final ReleaseMessageType releaseType = new ReleaseMessageType();
protected final PressMessageType pressType = new PressMessageType();
//Empty Constructor
public Button() {
super();
}

//Getters and Setters for non readonly/final attributes
public short getButton_PIN0_var() {
return Button_PIN0_var;
}

public void setButton_PIN0_var(short Button_PIN0_var) {
this.Button_PIN0_var = Button_PIN0_var;
}

public Button initButton_PIN0_var(short Button_PIN0_var) {
this.Button_PIN0_var = Button_PIN0_var;
return this;
}

//Getters for Ports
public Port getToBoard_port() {
return toBoard_port;
}
public Port getClock_tic_port() {
return clock_tic_port;
}
private CompositeState buildButton_BUTTON_SM(){
final AtomicState state_Button_BUTTON_SM_PRESSED = new AtomicState("PRESSED");
final AtomicState state_Button_BUTTON_SM_RELEASED = new AtomicState("RELEASED");
Transition h1796171410 = new Transition();
h1796171410.from(state_Button_BUTTON_SM_PRESSED).to(state_Button_BUTTON_SM_RELEASED);
h1796171410.event(ms25_ticType);
h1796171410.guard((Event e)->{
return digitalRead(getButton_PIN0_var());
});

h1796171410.port(clock_tic_port);
h1796171410.action((Event e)->{
sendRelease_via_toBoard();
});

Transition h1890615594 = new Transition();
h1890615594.from(state_Button_BUTTON_SM_RELEASED).to(state_Button_BUTTON_SM_PRESSED);
h1890615594.event(ms25_ticType);
h1890615594.guard((Event e)->{
return digitalRead(getButton_PIN0_var());
});

h1890615594.port(clock_tic_port);
h1890615594.action((Event e)->{
sendPress_via_toBoard();
});

final CompositeState state_Button_BUTTON_SM = new CompositeState("BUTTON_SM");
state_Button_BUTTON_SM.onEntry(()->{
});
state_Button_BUTTON_SM.add(state_Button_BUTTON_SM_PRESSED);
state_Button_BUTTON_SM.add(state_Button_BUTTON_SM_RELEASED);
state_Button_BUTTON_SM.initial(state_Button_BUTTON_SM_RELEASED);
return state_Button_BUTTON_SM;
}

public Component buildBehavior(String session, Component root) {
if (root == null) {
//Init ports
toBoard_port = new Port("toBoard", this);
clock_tic_port = new Port("clock_tic", this);
} else {
toBoard_port = ((Button)root).toBoard_port;
clock_tic_port = ((Button)root).clock_tic_port;
}
if (session == null){
//Init state machine
behavior = buildButton_BUTTON_SM();
}
return this;
}

}