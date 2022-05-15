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

public class LedOFFMessageType extends EventType {
public LedOFFMessageType(short code) {super("LedOFF", code);
}

public LedOFFMessageType() {
super("LedOFF", (short) 0);
}

public Event instantiate() { return new LedOFFMessage(this); }
public Event instantiate(Map<String, Object> params) {return instantiate();
}

public class LedOFFMessage extends Event implements java.io.Serializable {

public String toString(){
return "LedOFF (" + ")";
}

protected LedOFFMessage(EventType type) {
super(type);
}
public Event clone() {
return instantiate();
}}

}

