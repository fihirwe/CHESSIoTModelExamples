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

public class PressMessageType extends EventType {
public PressMessageType(short code) {super("press", code);
}

public PressMessageType() {
super("press", (short) 0);
}

public Event instantiate() { return new PressMessage(this); }
public Event instantiate(Map<String, Object> params) {return instantiate();
}

public class PressMessage extends Event implements java.io.Serializable {

public String toString(){
return "press (" + ")";
}

protected PressMessage(EventType type) {
super(type);
}
public Event clone() {
return instantiate();
}}

}
