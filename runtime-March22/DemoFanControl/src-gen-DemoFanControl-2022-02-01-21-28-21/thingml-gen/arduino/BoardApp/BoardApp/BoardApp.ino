#include <stdint.h>
#include <Arduino.h>
/*****************************************************************************
 * Headers for type : Button
 *****************************************************************************/

// Definition of the instance struct:
struct Button_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_toBoard;
uint16_t id_clock_tic;
// Variables for the current instance state
int Button_BUTTON_SM_State;
// Variables for the properties of the instance
uint8_t Button_PIN0_var;

};
// Declaration of prototypes outgoing messages :
void Button_BUTTON_SM_OnEntry(int state, struct Button_Instance *_instance);
void Button_handle_clock_tic_ms25_tic(struct Button_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_Button_send_toBoard_press_listener(void (*_listener)(struct Button_Instance *));
void register_external_Button_send_toBoard_press_listener(void (*_listener)(struct Button_Instance *));
void register_Button_send_toBoard_release_listener(void (*_listener)(struct Button_Instance *));
void register_external_Button_send_toBoard_release_listener(void (*_listener)(struct Button_Instance *));

// Definition of the states:
#define BUTTON_BUTTON_SM_RELEASED_STATE 0
#define BUTTON_BUTTON_SM_PRESSED_STATE 1
#define BUTTON_BUTTON_SM_STATE 2


/*****************************************************************************
 * Headers for type : LED
 *****************************************************************************/

// Definition of the instance struct:
struct LED_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_inLED;
// Variables for the current instance state
int LED_LED_SM_State;
// Variables for the properties of the instance
uint8_t LED_PIN11_var;

};
// Declaration of prototypes outgoing messages :
void LED_LED_SM_OnEntry(int state, struct LED_Instance *_instance);
void LED_handle_inLED_LedON(struct LED_Instance *_instance);
void LED_handle_inLED_LedOFF(struct LED_Instance *_instance);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define LED_LED_SM_STATE 0
#define LED_LED_SM_READY_STATE 1


/* Adds and instance to the runtime and returns its id */
uint16_t add_instance(void * instance_struct);
/* Returns the instance with id */
void * instance_by_id(uint16_t id);

/* Returns the number of byte currently in the fifo */
int fifo_byte_length();
/* Returns the number of bytes currently available in the fifo */
int fifo_byte_available();
/* Returns true if the fifo is empty */
int fifo_empty();
/* Return true if the fifo is full */
int fifo_full();
/* Enqueue 1 byte in the fifo if there is space
   returns 1 for sucess and 0 if the fifo was full */
int fifo_enqueue(byte b);
/* Enqueue 1 byte in the fifo without checking for available space
   The caller should have checked that there is enough space */
int _fifo_enqueue(byte b);
/* Dequeue 1 byte in the fifo.
   The caller should check that the fifo is not empty */
byte fifo_dequeue();
/*****************************************************************************
 * Headers for type : Board
 *****************************************************************************/

// Definition of the instance struct:
struct Board_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_toLED;
uint16_t id_toFAN;
uint16_t id_fromButton;
// Variables for the current instance state
int Board_BOARD_SM_State;
// Variables for the properties of the instance

};
// Declaration of prototypes outgoing messages :
void Board_BOARD_SM_OnEntry(int state, struct Board_Instance *_instance);
void Board_handle_fromButton_release(struct Board_Instance *_instance);
void Board_handle_fromButton_press(struct Board_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_Board_send_toLED_LedON_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toLED_LedON_listener(void (*_listener)(struct Board_Instance *));
void register_Board_send_toLED_LedOFF_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toLED_LedOFF_listener(void (*_listener)(struct Board_Instance *));
void register_Board_send_toFAN_FanON_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toFAN_FanON_listener(void (*_listener)(struct Board_Instance *));
void register_Board_send_toFAN_FanOFF_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toFAN_FanOFF_listener(void (*_listener)(struct Board_Instance *));

// Definition of the states:
#define BOARD_BOARD_SM_FANONLEDOFF_STATE 0
#define BOARD_BOARD_SM_FANOFFLEDON_STATE 1
#define BOARD_BOARD_SM_IDLE_STATE 2
#define BOARD_BOARD_SM_STATE 3


/*****************************************************************************
 * Headers for type : FAN
 *****************************************************************************/

// Definition of the instance struct:
struct FAN_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_inFAN;
// Variables for the current instance state
int FAN_FAN_SM_State;
// Variables for the properties of the instance
uint8_t FAN_PIN12_var;

};
// Declaration of prototypes outgoing messages :
void FAN_FAN_SM_OnEntry(int state, struct FAN_Instance *_instance);
void FAN_handle_inFAN_FanON(struct FAN_Instance *_instance);
void FAN_handle_inFAN_FanOFF(struct FAN_Instance *_instance);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define FAN_FAN_SM_STANDBY_STATE 0
#define FAN_FAN_SM_STATE 1



struct timer2_instance_type {
    uint16_t listener_id;
    /*INSTANCE_INFORMATION*/
};
extern struct timer2_instance_type timer2_instance;

void timer2_setup();
void timer2_read();

//void forward_timer2_SoftButton_send_Timer_timer_start(struct SoftButton_Instance *_instance, uint8_t id, uint32_t time);
//void forward_timer2_SoftButton_send_Timer_timer_cancel(struct SoftButton_Instance *_instance, uint8_t id);
// Definition of Enumeration  DigitalState
#define DIGITALSTATE_LOW 0
#define DIGITALSTATE_HIGH 1


/*****************************************************************************
 * Implementation for type : Button
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void Button_BUTTON_SM_OnExit(int state, struct Button_Instance *_instance);
//Prototypes: Message Sending
void Button_send_toBoard_press(struct Button_Instance *_instance);
void Button_send_toBoard_release(struct Button_Instance *_instance);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void Button_BUTTON_SM_OnEntry(int state, struct Button_Instance *_instance) {
switch(state) {
case BUTTON_BUTTON_SM_STATE:{
_instance->Button_BUTTON_SM_State = BUTTON_BUTTON_SM_RELEASED_STATE;
Button_BUTTON_SM_OnEntry(_instance->Button_BUTTON_SM_State, _instance);
break;
}
case BUTTON_BUTTON_SM_RELEASED_STATE:{
break;
}
case BUTTON_BUTTON_SM_PRESSED_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Button_BUTTON_SM_OnExit(int state, struct Button_Instance *_instance) {
switch(state) {
case BUTTON_BUTTON_SM_STATE:{
Button_BUTTON_SM_OnExit(_instance->Button_BUTTON_SM_State, _instance);
break;}
case BUTTON_BUTTON_SM_RELEASED_STATE:{
break;}
case BUTTON_BUTTON_SM_PRESSED_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Button_handle_clock_tic_ms25_tic(struct Button_Instance *_instance) {
if(!(_instance->active)) return;
//Region BUTTON_SM
uint8_t Button_BUTTON_SM_State_event_consumed = 0;
if (_instance->Button_BUTTON_SM_State == BUTTON_BUTTON_SM_PRESSED_STATE) {
if (Button_BUTTON_SM_State_event_consumed == 0 && digitalRead(_instance->Button_PIN0_var)) {
Button_BUTTON_SM_OnExit(BUTTON_BUTTON_SM_PRESSED_STATE, _instance);
_instance->Button_BUTTON_SM_State = BUTTON_BUTTON_SM_RELEASED_STATE;
Button_send_toBoard_release(_instance);
Button_BUTTON_SM_OnEntry(BUTTON_BUTTON_SM_RELEASED_STATE, _instance);
Button_BUTTON_SM_State_event_consumed = 1;
}
}
else if (_instance->Button_BUTTON_SM_State == BUTTON_BUTTON_SM_RELEASED_STATE) {
if (Button_BUTTON_SM_State_event_consumed == 0 && digitalRead(_instance->Button_PIN0_var)) {
Button_BUTTON_SM_OnExit(BUTTON_BUTTON_SM_RELEASED_STATE, _instance);
_instance->Button_BUTTON_SM_State = BUTTON_BUTTON_SM_PRESSED_STATE;
Button_send_toBoard_press(_instance);
Button_BUTTON_SM_OnEntry(BUTTON_BUTTON_SM_PRESSED_STATE, _instance);
Button_BUTTON_SM_State_event_consumed = 1;
}
}
//End Region BUTTON_SM
//End dsregion BUTTON_SM
//Session list: 
}

// Observers for outgoing messages:
void (*external_Button_send_toBoard_press_listener)(struct Button_Instance *)= 0x0;
void (*Button_send_toBoard_press_listener)(struct Button_Instance *)= 0x0;
void register_external_Button_send_toBoard_press_listener(void (*_listener)(struct Button_Instance *)){
external_Button_send_toBoard_press_listener = _listener;
}
void register_Button_send_toBoard_press_listener(void (*_listener)(struct Button_Instance *)){
Button_send_toBoard_press_listener = _listener;
}
void Button_send_toBoard_press(struct Button_Instance *_instance){
if (Button_send_toBoard_press_listener != 0x0) Button_send_toBoard_press_listener(_instance);
if (external_Button_send_toBoard_press_listener != 0x0) external_Button_send_toBoard_press_listener(_instance);
;
}
void (*external_Button_send_toBoard_release_listener)(struct Button_Instance *)= 0x0;
void (*Button_send_toBoard_release_listener)(struct Button_Instance *)= 0x0;
void register_external_Button_send_toBoard_release_listener(void (*_listener)(struct Button_Instance *)){
external_Button_send_toBoard_release_listener = _listener;
}
void register_Button_send_toBoard_release_listener(void (*_listener)(struct Button_Instance *)){
Button_send_toBoard_release_listener = _listener;
}
void Button_send_toBoard_release(struct Button_Instance *_instance){
if (Button_send_toBoard_release_listener != 0x0) Button_send_toBoard_release_listener(_instance);
if (external_Button_send_toBoard_release_listener != 0x0) external_Button_send_toBoard_release_listener(_instance);
;
}



/*****************************************************************************
 * Implementation for type : Board
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void Board_BOARD_SM_OnExit(int state, struct Board_Instance *_instance);
//Prototypes: Message Sending
void Board_send_toLED_LedON(struct Board_Instance *_instance);
void Board_send_toLED_LedOFF(struct Board_Instance *_instance);
void Board_send_toFAN_FanON(struct Board_Instance *_instance);
void Board_send_toFAN_FanOFF(struct Board_Instance *_instance);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void Board_BOARD_SM_OnEntry(int state, struct Board_Instance *_instance) {
switch(state) {
case BOARD_BOARD_SM_STATE:{
_instance->Board_BOARD_SM_State = BOARD_BOARD_SM_IDLE_STATE;
Board_BOARD_SM_OnEntry(_instance->Board_BOARD_SM_State, _instance);
break;
}
case BOARD_BOARD_SM_FANONLEDOFF_STATE:{
Board_send_toLED_LedOFF(_instance);
Board_send_toFAN_FanON(_instance);
break;
}
case BOARD_BOARD_SM_FANOFFLEDON_STATE:{
Board_send_toLED_LedON(_instance);
Board_send_toFAN_FanOFF(_instance);
break;
}
case BOARD_BOARD_SM_IDLE_STATE:{
Board_send_toLED_LedON(_instance);
Board_send_toFAN_FanOFF(_instance);
break;
}
default: break;
}
}

// On Exit Actions:
void Board_BOARD_SM_OnExit(int state, struct Board_Instance *_instance) {
switch(state) {
case BOARD_BOARD_SM_STATE:{
Board_BOARD_SM_OnExit(_instance->Board_BOARD_SM_State, _instance);
break;}
case BOARD_BOARD_SM_FANONLEDOFF_STATE:{
break;}
case BOARD_BOARD_SM_FANOFFLEDON_STATE:{
break;}
case BOARD_BOARD_SM_IDLE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Board_handle_fromButton_release(struct Board_Instance *_instance) {
if(!(_instance->active)) return;
//Region BOARD_SM
uint8_t Board_BOARD_SM_State_event_consumed = 0;
if (_instance->Board_BOARD_SM_State == BOARD_BOARD_SM_FANONLEDOFF_STATE) {
if (Board_BOARD_SM_State_event_consumed == 0 && 1) {
Board_BOARD_SM_OnExit(BOARD_BOARD_SM_FANONLEDOFF_STATE, _instance);
_instance->Board_BOARD_SM_State = BOARD_BOARD_SM_FANOFFLEDON_STATE;
Board_BOARD_SM_OnEntry(BOARD_BOARD_SM_FANOFFLEDON_STATE, _instance);
Board_BOARD_SM_State_event_consumed = 1;
}
}
//End Region BOARD_SM
//End dsregion BOARD_SM
//Session list: 
}
void Board_handle_fromButton_press(struct Board_Instance *_instance) {
if(!(_instance->active)) return;
//Region BOARD_SM
uint8_t Board_BOARD_SM_State_event_consumed = 0;
if (_instance->Board_BOARD_SM_State == BOARD_BOARD_SM_FANOFFLEDON_STATE) {
if (Board_BOARD_SM_State_event_consumed == 0 && 1) {
Board_BOARD_SM_OnExit(BOARD_BOARD_SM_FANOFFLEDON_STATE, _instance);
_instance->Board_BOARD_SM_State = BOARD_BOARD_SM_FANONLEDOFF_STATE;
Board_BOARD_SM_OnEntry(BOARD_BOARD_SM_FANONLEDOFF_STATE, _instance);
Board_BOARD_SM_State_event_consumed = 1;
}
}
//End Region BOARD_SM
//End dsregion BOARD_SM
//Session list: 
}
int Board_handle_empty_event(struct Board_Instance *_instance) {
 uint8_t empty_event_consumed = 0;
if(!(_instance->active)) return 0;
//Region BOARD_SM
if (_instance->Board_BOARD_SM_State == BOARD_BOARD_SM_IDLE_STATE) {
if (1) {
Board_BOARD_SM_OnExit(BOARD_BOARD_SM_IDLE_STATE, _instance);
_instance->Board_BOARD_SM_State = BOARD_BOARD_SM_FANOFFLEDON_STATE;
Board_BOARD_SM_OnEntry(BOARD_BOARD_SM_FANOFFLEDON_STATE, _instance);
return 1;
}
}
//begin dispatchEmptyToSession
//end dispatchEmptyToSession
return empty_event_consumed;
}

// Observers for outgoing messages:
void (*external_Board_send_toLED_LedON_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toLED_LedON_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toLED_LedON_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toLED_LedON_listener = _listener;
}
void register_Board_send_toLED_LedON_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toLED_LedON_listener = _listener;
}
void Board_send_toLED_LedON(struct Board_Instance *_instance){
if (Board_send_toLED_LedON_listener != 0x0) Board_send_toLED_LedON_listener(_instance);
if (external_Board_send_toLED_LedON_listener != 0x0) external_Board_send_toLED_LedON_listener(_instance);
;
}
void (*external_Board_send_toLED_LedOFF_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toLED_LedOFF_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toLED_LedOFF_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toLED_LedOFF_listener = _listener;
}
void register_Board_send_toLED_LedOFF_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toLED_LedOFF_listener = _listener;
}
void Board_send_toLED_LedOFF(struct Board_Instance *_instance){
if (Board_send_toLED_LedOFF_listener != 0x0) Board_send_toLED_LedOFF_listener(_instance);
if (external_Board_send_toLED_LedOFF_listener != 0x0) external_Board_send_toLED_LedOFF_listener(_instance);
;
}
void (*external_Board_send_toFAN_FanON_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toFAN_FanON_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toFAN_FanON_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toFAN_FanON_listener = _listener;
}
void register_Board_send_toFAN_FanON_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toFAN_FanON_listener = _listener;
}
void Board_send_toFAN_FanON(struct Board_Instance *_instance){
if (Board_send_toFAN_FanON_listener != 0x0) Board_send_toFAN_FanON_listener(_instance);
if (external_Board_send_toFAN_FanON_listener != 0x0) external_Board_send_toFAN_FanON_listener(_instance);
;
}
void (*external_Board_send_toFAN_FanOFF_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toFAN_FanOFF_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toFAN_FanOFF_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toFAN_FanOFF_listener = _listener;
}
void register_Board_send_toFAN_FanOFF_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toFAN_FanOFF_listener = _listener;
}
void Board_send_toFAN_FanOFF(struct Board_Instance *_instance){
if (Board_send_toFAN_FanOFF_listener != 0x0) Board_send_toFAN_FanOFF_listener(_instance);
if (external_Board_send_toFAN_FanOFF_listener != 0x0) external_Board_send_toFAN_FanOFF_listener(_instance);
;
}



/*****************************************************************************
 * Implementation for type : LED
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void LED_LED_SM_OnExit(int state, struct LED_Instance *_instance);
//Prototypes: Message Sending
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void LED_LED_SM_OnEntry(int state, struct LED_Instance *_instance) {
switch(state) {
case LED_LED_SM_STATE:{
_instance->LED_LED_SM_State = LED_LED_SM_READY_STATE;
LED_LED_SM_OnEntry(_instance->LED_LED_SM_State, _instance);
break;
}
case LED_LED_SM_READY_STATE:{
pinMode(_instance->LED_PIN11_var, OUTPUT);
break;
}
default: break;
}
}

// On Exit Actions:
void LED_LED_SM_OnExit(int state, struct LED_Instance *_instance) {
switch(state) {
case LED_LED_SM_STATE:{
LED_LED_SM_OnExit(_instance->LED_LED_SM_State, _instance);
break;}
case LED_LED_SM_READY_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void LED_handle_inLED_LedON(struct LED_Instance *_instance) {
if(!(_instance->active)) return;
//Region LED_SM
uint8_t LED_LED_SM_State_event_consumed = 0;
if (_instance->LED_LED_SM_State == LED_LED_SM_READY_STATE) {
if (LED_LED_SM_State_event_consumed == 0 && 1) {
digitalWrite(_instance->LED_PIN11_var,HIGH);
LED_LED_SM_State_event_consumed = 1;
}
}
//End Region LED_SM
//End dsregion LED_SM
//Session list: 
}
void LED_handle_inLED_LedOFF(struct LED_Instance *_instance) {
if(!(_instance->active)) return;
//Region LED_SM
uint8_t LED_LED_SM_State_event_consumed = 0;
if (_instance->LED_LED_SM_State == LED_LED_SM_READY_STATE) {
if (LED_LED_SM_State_event_consumed == 0 && 1) {
digitalWrite(_instance->LED_PIN11_var, LOW);
LED_LED_SM_State_event_consumed = 1;
}
}
//End Region LED_SM
//End dsregion LED_SM
//Session list: 
}

// Observers for outgoing messages:




#define MAX_INSTANCES 8
#define FIFO_SIZE 256

/*********************************
 * Instance IDs and lookup
 *********************************/

void * instances[MAX_INSTANCES];
uint16_t instances_count = 0;

void * instance_by_id(uint16_t id) {
  return instances[id];
}

uint16_t add_instance(void * instance_struct) {
  instances[instances_count] = instance_struct;
  return instances_count++;
}

/******************************************
 * Simple byte FIFO implementation
 ******************************************/

byte fifo[FIFO_SIZE];
int fifo_head = 0;
int fifo_tail = 0;

// Returns the number of byte currently in the fifo
int fifo_byte_length() {
  if (fifo_tail >= fifo_head)
    return fifo_tail - fifo_head;
  return fifo_tail + FIFO_SIZE - fifo_head;
}

// Returns the number of bytes currently available in the fifo
int fifo_byte_available() {
  return FIFO_SIZE - 1 - fifo_byte_length();
}

// Returns true if the fifo is empty
int fifo_empty() {
  return fifo_head == fifo_tail;
}

// Return true if the fifo is full
int fifo_full() {
  return fifo_head == ((fifo_tail + 1) % FIFO_SIZE);
}

// Enqueue 1 byte in the fifo if there is space
// returns 1 for sucess and 0 if the fifo was full
int fifo_enqueue(byte b) {
  int new_tail = (fifo_tail + 1) % FIFO_SIZE;
  if (new_tail == fifo_head) return 0; // the fifo is full
  fifo[fifo_tail] = b;
  fifo_tail = new_tail;
  return 1;
}

// Enqueue 1 byte in the fifo without checking for available space
// The caller should have checked that there is enough space
int _fifo_enqueue(byte b) {
  fifo[fifo_tail] = b;
  fifo_tail = (fifo_tail + 1) % FIFO_SIZE;
  return 0; // Dummy added by steffend
}

// Dequeue 1 byte in the fifo.
// The caller should check that the fifo is not empty
byte fifo_dequeue() {
  if (!fifo_empty()) {
    byte result = fifo[fifo_head];
    fifo_head = (fifo_head + 1) % FIFO_SIZE;
    return result;
  }
  return 0;
}

/*****************************************************************************
 * Implementation for type : FAN
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void FAN_FAN_SM_OnExit(int state, struct FAN_Instance *_instance);
//Prototypes: Message Sending
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void FAN_FAN_SM_OnEntry(int state, struct FAN_Instance *_instance) {
switch(state) {
case FAN_FAN_SM_STATE:{
_instance->FAN_FAN_SM_State = FAN_FAN_SM_STANDBY_STATE;
FAN_FAN_SM_OnEntry(_instance->FAN_FAN_SM_State, _instance);
break;
}
case FAN_FAN_SM_STANDBY_STATE:{
pinMode(_instance->FAN_PIN12_var, OUTPUT);
break;
}
default: break;
}
}

// On Exit Actions:
void FAN_FAN_SM_OnExit(int state, struct FAN_Instance *_instance) {
switch(state) {
case FAN_FAN_SM_STATE:{
FAN_FAN_SM_OnExit(_instance->FAN_FAN_SM_State, _instance);
break;}
case FAN_FAN_SM_STANDBY_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void FAN_handle_inFAN_FanON(struct FAN_Instance *_instance) {
if(!(_instance->active)) return;
//Region FAN_SM
uint8_t FAN_FAN_SM_State_event_consumed = 0;
if (_instance->FAN_FAN_SM_State == FAN_FAN_SM_STANDBY_STATE) {
if (FAN_FAN_SM_State_event_consumed == 0 && 1) {
digitalWrite(_instance->FAN_PIN12_var,HIGH);
FAN_FAN_SM_State_event_consumed = 1;
}
}
//End Region FAN_SM
//End dsregion FAN_SM
//Session list: 
}
void FAN_handle_inFAN_FanOFF(struct FAN_Instance *_instance) {
if(!(_instance->active)) return;
//Region FAN_SM
uint8_t FAN_FAN_SM_State_event_consumed = 0;
if (_instance->FAN_FAN_SM_State == FAN_FAN_SM_STANDBY_STATE) {
if (FAN_FAN_SM_State_event_consumed == 0 && 1) {
digitalWrite(_instance->FAN_PIN12_var, LOW);
FAN_FAN_SM_State_event_consumed = 1;
}
}
//End Region FAN_SM
//End dsregion FAN_SM
//Session list: 
}

// Observers for outgoing messages:



#define timer2_NB_SOFT_TIMER 4
uint32_t timer2_timer[timer2_NB_SOFT_TIMER];
uint32_t  timer2_prev_1sec = 0;

uint8_t timer2_tic_flags = 0;

void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id);

uint8_t timer2_interrupt_counter = 0;
SIGNAL(TIMER2_OVF_vect) {
TCNT2 = 5;
timer2_interrupt_counter++;
if((timer2_interrupt_counter % 25) == 0) {
timer2_tic_flags |= 0b00000001;
}
if(timer2_interrupt_counter >= 25) {
timer2_interrupt_counter = 0;
}
}



//struct timer2_instance_type {
//    uint16_t listener_id;
//    /*INSTANCE_INFORMATION*/
//} timer2_instance;

struct timer2_instance_type timer2_instance;


void timer2_setup() {
	// Run timer2 interrupt up counting at 250kHz 
		 TCCR2A = 0;
		 TCCR2B = 1<<CS22 | 0<<CS21 | 0<<CS20;
		
		 //Timer2 Overflow Interrupt Enable
		 TIMSK2 |= 1<<TOIE2;


	timer2_prev_1sec = millis() + 1000;
}

void timer2_set_listener_id(uint16_t id) {
	timer2_instance.listener_id = id;
}

void timer2_25ms_tic() {
{
uint8_t enqueue_buf[2];
enqueue_buf[0] = (1 >> 8) & 0xFF;
enqueue_buf[1] = 1 & 0xFF;
externalMessageEnqueue(enqueue_buf, 2, timer2_instance.listener_id);
}
}





void timer2_read() {
    uint32_t tms = millis();
    
    if (timer2_prev_1sec < tms) {
        timer2_prev_1sec += 1000;
    }
    if((timer2_tic_flags & 0b00000001) >> 0) {
timer2_25ms_tic();
timer2_tic_flags &= 0b11111110;
}

}



/*****************************************************************************
 * Definitions for configuration : BoardApp
 *****************************************************************************/

//Declaration of instance variables
//Instance buttonObj
// Variables for the properties of the instance
struct Button_Instance buttonObj_var;
// Variables for the sessions of the instance
//Instance boardObj
// Variables for the properties of the instance
struct Board_Instance boardObj_var;
// Variables for the sessions of the instance
//Instance lEDObj
// Variables for the properties of the instance
struct LED_Instance lEDObj_var;
// Variables for the sessions of the instance
//Instance fANObj
// Variables for the properties of the instance
struct FAN_Instance fANObj_var;
// Variables for the sessions of the instance


// Enqueue of messages Button::toBoard::release
void enqueue_Button_send_toBoard_release(struct Button_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toBoard >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toBoard & 0xFF );
}
}
// Enqueue of messages Button::toBoard::press
void enqueue_Button_send_toBoard_press(struct Button_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toBoard >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toBoard & 0xFF );
}
}
// Enqueue of messages Board::toLED::LedON
void enqueue_Board_send_toLED_LedON(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toLED >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toLED & 0xFF );
}
}
// Enqueue of messages Board::toLED::LedOFF
void enqueue_Board_send_toLED_LedOFF(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toLED >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toLED & 0xFF );
}
}
// Enqueue of messages Board::toFAN::FanON
void enqueue_Board_send_toFAN_FanON(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toFAN >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toFAN & 0xFF );
}
}
// Enqueue of messages Board::toFAN::FanOFF
void enqueue_Board_send_toFAN_FanOFF(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toFAN >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toFAN & 0xFF );
}
}


//New dispatcher for messages
void dispatch_LedON(uint16_t sender) {
if (sender == boardObj_var.id_toLED) {
LED_handle_inLED_LedON(&lEDObj_var);

}

}


//New dispatcher for messages
void dispatch_FanON(uint16_t sender) {
if (sender == boardObj_var.id_toFAN) {
FAN_handle_inFAN_FanON(&fANObj_var);

}

}


//New dispatcher for messages
void dispatch_LedOFF(uint16_t sender) {
if (sender == boardObj_var.id_toLED) {
LED_handle_inLED_LedOFF(&lEDObj_var);

}

}


//New dispatcher for messages
void dispatch_ms25_tic(uint16_t sender) {
if (sender == timer2_instance.listener_id) {
Button_handle_clock_tic_ms25_tic(&buttonObj_var);

}

}


//New dispatcher for messages
void dispatch_release(uint16_t sender) {
if (sender == buttonObj_var.id_toBoard) {
Board_handle_fromButton_release(&boardObj_var);

}

}


//New dispatcher for messages
void dispatch_press(uint16_t sender) {
if (sender == buttonObj_var.id_toBoard) {
Board_handle_fromButton_press(&boardObj_var);

}

}


//New dispatcher for messages
void dispatch_FanOFF(uint16_t sender) {
if (sender == boardObj_var.id_toFAN) {
FAN_handle_inFAN_FanOFF(&fANObj_var);

}

}


int processMessageQueue() {
if (fifo_empty()) return 0; // return 0 if there is nothing to do

uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 4:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_LedON = 2;
dispatch_LedON((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 5:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_LedOFF = 2;
dispatch_LedOFF((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 6:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_FanON = 2;
dispatch_FanON((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 1:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_ms25_tic = 2;
dispatch_ms25_tic((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 2:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_release = 2;
dispatch_release((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 3:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_press = 2;
dispatch_press((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 7:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_FanOFF = 2;
dispatch_FanOFF((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
}
return 1;
}


//external Message enqueue
void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id) {
if ((msgSize >= 2) && (msg != NULL)) {
uint8_t msgSizeOK = 0;
switch(msg[0] * 256 + msg[1]) {
case 1:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
}

if(msgSizeOK == 1) {
if ( fifo_byte_available() > (msgSize + 2) ) {
	uint8_t i;
	for (i = 0; i < 2; i++) {
		_fifo_enqueue(msg[i]);
	}
	_fifo_enqueue((listener_id >> 8) & 0xFF);
	_fifo_enqueue(listener_id & 0xFF);
	for (i = 2; i < msgSize; i++) {
		_fifo_enqueue(msg[i]);
	}
}
}
}
}

void initialize_configuration_BoardApp() {
// Initialize connectors
register_Button_send_toBoard_release_listener(&enqueue_Button_send_toBoard_release);
register_Button_send_toBoard_press_listener(&enqueue_Button_send_toBoard_press);
register_Board_send_toLED_LedON_listener(&enqueue_Board_send_toLED_LedON);
register_Board_send_toLED_LedOFF_listener(&enqueue_Board_send_toLED_LedOFF);
register_Board_send_toFAN_FanON_listener(&enqueue_Board_send_toFAN_FanON);
register_Board_send_toFAN_FanOFF_listener(&enqueue_Board_send_toFAN_FanOFF);

// Init the ID, state variables and properties for external connector timer2

// Network Initialization

timer2_instance.listener_id = add_instance(&timer2_instance);

timer2_setup();

// End Network Initialization

// Init the ID, state variables and properties for instance buttonObj
buttonObj_var.active = true;
buttonObj_var.id_toBoard = add_instance( (void*) &buttonObj_var);
buttonObj_var.id_clock_tic = add_instance( (void*) &buttonObj_var);
buttonObj_var.Button_BUTTON_SM_State = BUTTON_BUTTON_SM_RELEASED_STATE;
buttonObj_var.Button_PIN0_var = 0;

Button_BUTTON_SM_OnEntry(BUTTON_BUTTON_SM_STATE, &buttonObj_var);
// Init the ID, state variables and properties for instance fANObj
fANObj_var.active = true;
fANObj_var.id_inFAN = add_instance( (void*) &fANObj_var);
fANObj_var.FAN_FAN_SM_State = FAN_FAN_SM_STANDBY_STATE;
fANObj_var.FAN_PIN12_var = 12;

FAN_FAN_SM_OnEntry(FAN_FAN_SM_STATE, &fANObj_var);
// Init the ID, state variables and properties for instance lEDObj
lEDObj_var.active = true;
lEDObj_var.id_inLED = add_instance( (void*) &lEDObj_var);
lEDObj_var.LED_LED_SM_State = LED_LED_SM_READY_STATE;
lEDObj_var.LED_PIN11_var = 11;

LED_LED_SM_OnEntry(LED_LED_SM_STATE, &lEDObj_var);
// Init the ID, state variables and properties for instance boardObj
boardObj_var.active = true;
boardObj_var.id_toLED = add_instance( (void*) &boardObj_var);
boardObj_var.id_toFAN = add_instance( (void*) &boardObj_var);
boardObj_var.id_fromButton = add_instance( (void*) &boardObj_var);
boardObj_var.Board_BOARD_SM_State = BOARD_BOARD_SM_IDLE_STATE;

Board_BOARD_SM_OnEntry(BOARD_BOARD_SM_STATE, &boardObj_var);
}




void setup() {
initialize_configuration_BoardApp();

}

void loop() {

// Network Listener
timer2_read();
// End Network Listener

int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
emptyEventConsumed += Board_handle_empty_event(&boardObj_var);
}

    processMessageQueue();
}
