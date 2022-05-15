/**
 * File generated by the ThingML IDE
 * /!\Do not edit this file/!\
 * In case of a bug in the generated code,
 * please submit an issue on our GitHub
 **/

package org.thingml.generated.messages;

import no.sintef.jasm.*;
import no.sintef.jasm.ext.*;

import java.util.*;
import java.nio.*;

public class Timer_timeoutMessageType extends EventType {
public Timer_timeoutMessageType(short code) {super("timer_timeout", code);
}

public Timer_timeoutMessageType() {
super("timer_timeout", (short) 0);
}

public Event instantiate(final short id) { return new Timer_timeoutMessage(this, id); }
public Event instantiate(Map<String, Object> params) {return instantiate((Short) params.get("id"));
}

public class Timer_timeoutMessage extends Event implements java.io.Serializable {

public final short id;
public String toString(){
return "timer_timeout (" + "id: " + id + ")";
}

protected Timer_timeoutMessage(EventType type, final short id) {
super(type);
this.id = id;
}
public Event clone() {
return instantiate(this.id);
}}

}
